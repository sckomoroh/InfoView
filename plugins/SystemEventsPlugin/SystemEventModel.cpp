#include "SystemEventModel.h"

#include <QImage>

QImage SystemEventModel::m_sysEventCritical;
QImage SystemEventModel::m_sysEventError;
QImage SystemEventModel::m_sysEventInfo;
QImage SystemEventModel::m_sysEventVerbose;
QImage SystemEventModel::m_sysEventWarning;
QImage SystemEventModel::m_sysEventLogAlways;
QImage SystemEventModel::m_sysEventQuestion;

SystemEventModel::SystemEventModel(SystemEventStorage* storage, QObject *parent)
	: QAbstractItemModel(parent)
	, m_storage(storage)
{
	m_storage->setListener(this);

	if (m_sysEventCritical.isNull())
	{
		m_sysEventCritical = QImage(":/plugin/images/Resources/critical.png");
	}

	if (m_sysEventError.isNull())
	{
		m_sysEventError = QImage(":/plugin/images/Resources/error.png");
	}

	if (m_sysEventInfo.isNull())
	{
		m_sysEventInfo = QImage(":/plugin/images/Resources/information.png");
	}

	if (m_sysEventVerbose.isNull())
	{
		m_sysEventVerbose = QImage(":/plugin/images/Resources/verbose.png");
	}

	if (m_sysEventWarning.isNull())
	{
		m_sysEventWarning = QImage(":/plugin/images/Resources/warning.png");
	}

	if (m_sysEventLogAlways.isNull())
	{
		m_sysEventLogAlways = QImage(":/plugin/images/Resources/logAlways.png");
	}

	if (m_sysEventQuestion.isNull())
	{
		m_sysEventQuestion = QImage(":/plugin/images/Resources/question.png");
	}
}

SystemEventModel::~SystemEventModel()
{
}

SystemEventData* SystemEventModel::rawData(const QModelIndex & index)
{
	if (!index.isValid())
	{
		return NULL;
	}

	return m_storage->filteredRecordAt(index.row());
}

QModelIndex	SystemEventModel::index(int row, int column, const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (!hasIndex(row, column, parent))
	{
		return QModelIndex();
	}

	return createIndex(row, column);
}

QModelIndex	SystemEventModel::parent(const QModelIndex& index) const
{
	return QModelIndex();
}

int	SystemEventModel::columnCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	return 3;
}

QVariant SystemEventModel::data(const QModelIndex& index, int role/* = Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole && role != Qt::DecorationRole)
	{
		return QVariant();
	}

	if (!index.isValid())
	{
		return QVariant();
	}

	SystemEventData* pObject = m_storage->filteredRecordAt(index.row());

	if (role == Qt::DecorationRole)
	{
		if (index.column() == 0)
		{
			switch (pObject->eventLevel())
			{
				case SystemEventData::SysEventCritical:
					return m_sysEventCritical;
				case SystemEventData::SysEventError:
					return m_sysEventError;
				case SystemEventData::SysEventInfo:
					return m_sysEventInfo;
				case SystemEventData::SysEventVerbose:
					return m_sysEventVerbose;
				case SystemEventData::SysEventWarning:
					return m_sysEventWarning;
				case SystemEventData::SysEventLogAlways:
					return m_sysEventLogAlways;
				default:
					return m_sysEventQuestion;
			}
		}

		return QVariant();
	}


	switch (index.column())
	{
	case 0:
		return pObject->eventId();
	case 1:
		return pObject->providerName();
	case 2:
		return pObject->creationTime().toString("yyyy-MM-dd hh:mm");
	}

	return QVariant();
}

int	SystemEventModel::rowCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (parent.isValid())
	{
		return 0;
	}

	return m_storage->filteredRecordsCount();
}

QVariant SystemEventModel::headerData(int section, Qt::Orientation orientation, int role/* = Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}

	if (orientation == Qt::Horizontal)
	{
		if (section < 3)
		{
			switch (section)
			{
			case 0:
				return "Event ID";
			case 1:
				return "Provider";
			case 2:
				return "Creation time";
			}
		}
	}

	return QVariant();
}

void SystemEventModel::sort(int column, Qt::SortOrder order)
{
	beginResetModel();

	switch (column)
	{
	case 0:
		sortByEventId(order == Qt::AscendingOrder);
		break;
	case 1:
		sortByProvider(order == Qt::AscendingOrder);
		break;
	case 2:
		sortByTime(order == Qt::AscendingOrder);
		break;
	}

	endResetModel();
}

void SystemEventModel::sortByEventId(bool ascending)
{
	m_storage->sortByEventId(ascending);
}

void SystemEventModel::sortByProvider(bool ascending)
{
	m_storage->sortByProvider(ascending);
}

void SystemEventModel::sortByTime(bool ascending)
{
	m_storage->sortByTime(ascending);
}

void SystemEventModel::beginStorageChange()
{
	this->beginResetModel();
}

void SystemEventModel::endStorageChange()
{
	this->endResetModel();
}
