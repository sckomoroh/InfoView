#include "MongoEventModel.h"

#include <QDebug>
#include <QImage>

QImage MongoEventModel::m_eventError;
QImage MongoEventModel::m_eventInformation;
QImage MongoEventModel::m_eventWarning;
QImage MongoEventModel::m_eventUnknown;

MongoEventModel::MongoEventModel(QObject *parent)
	: QAbstractItemModel(parent)
{
	if (m_eventError.isNull())
	{
		m_eventError = QImage(":/plugin/images/Resources/error.png");
	}

	if (m_eventInformation.isNull())
	{
		m_eventInformation = QImage(":/plugin/images/Resources/information.png");
	}

	if (m_eventWarning.isNull())
	{
		m_eventWarning = QImage(":/plugin/images/Resources/warning.png");
	}

	if (m_eventUnknown.isNull())
	{
		m_eventUnknown = QImage(":/plugin/images/Resources/question.png");
	}
}

MongoEventModel::~MongoEventModel()
{
}

void MongoEventModel::reset()
{
	beginResetModel();

	m_events.clear();

	endResetModel();
}

void MongoEventModel::setModelData(const QList<MongoEventData*>& content)
{
	beginResetModel();

	m_events.clear();

	foreach(MongoEventData* pItem, content)
	{
		m_events.append(pItem);
	}

	endResetModel();
}

QModelIndex	MongoEventModel::index(int row, int column, const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (!hasIndex(row, column, parent))
	{
		return QModelIndex();
	}

	return createIndex(row, column);
}

QModelIndex	MongoEventModel::parent(const QModelIndex& index) const
{
	return QModelIndex();
}

int	MongoEventModel::columnCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	return 2;
}

QVariant MongoEventModel::data(const QModelIndex& index, int role/* = Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole && role != Qt::DecorationRole)
	{
		return QVariant();
	}

	if (!index.isValid())
	{
		return QVariant();
	}

	MongoEventData* pObject = m_events.at(index.row());

	if (role == Qt::DecorationRole)
	{
		if (index.column() == 0)
		{
			if (pObject->level() & MongoEventData::EventError)
			{
				return m_eventError;
			}

			if (pObject->level() & MongoEventData::EventInformation)
			{
				return m_eventInformation;
			}

			if (pObject->level() & MongoEventData::EventWarning)
			{
				return m_eventWarning;
			}

			return m_eventUnknown;
		}

		return QVariant();
	}

	switch (index.column())
	{
	case 0:
		return pObject->message();
	case 1:
		return pObject->time().toString("yyyy-MM-dd hh:mm");
	}

	return QVariant();
}

int	MongoEventModel::rowCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (parent.isValid())
	{
		return 0;
	}

	return m_events.count();
}

QVariant MongoEventModel::headerData(int section, Qt::Orientation orientation, int role/* = Qt::DisplayRole*/) const
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
				return "Message";
			case 1:
				return "Time";
			}
		}
	}

	return QVariant();
}

void MongoEventModel::sort(int column, Qt::SortOrder order)
{
	beginResetModel();

	switch (column)
	{
		case 0:
			sortByMessage(order == Qt::AscendingOrder);
			break;
		case 1:
			sortByTime(order == Qt::AscendingOrder);
			break;
	}

	endResetModel();
}

void MongoEventModel::sortByMessage(bool acsending)
{
	if (acsending)
	{
		qSort(m_events.begin(), m_events.end(), MongoEventData::acsByMessage);
	}
	else
	{
		qSort(m_events.begin(), m_events.end(), MongoEventData::decsByMessage);
	}
}

void MongoEventModel::sortByTime(bool acsending)
{
	if (acsending)
	{
		qSort(m_events.begin(), m_events.end(), MongoEventData::acsByTime);
	}
	else
	{
		qSort(m_events.begin(), m_events.end(), MongoEventData::decsByTime);
	}
}

