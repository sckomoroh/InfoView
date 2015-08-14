#include "MongoJobModel.h"

#include <QImage>

QImage MongoJobModel::m_success;
QImage MongoJobModel::m_fail;
QImage MongoJobModel::m_cancel;

MongoJobModel::MongoJobModel(MongoJobStorage* storage, QObject *parent)
	: QAbstractItemModel(parent)
	, m_pRootItem(NULL)
	, m_storage(storage)
{
	m_pRootItem = MongoJobData::emptyObject();

	if (m_success.isNull())
	{
		m_success = QImage(":/plugin/images/Resources/success.png");
	}

	if (m_fail.isNull())
	{
		m_fail = QImage(":/plugin/images/Resources/fail.png");
	}

	if (m_cancel.isNull())
	{
		m_cancel = QImage(":/plugin/images/Resources/cancel.png");
	}

	m_storage->addListener(this);
}

MongoJobModel::~MongoJobModel()
{
	delete m_pRootItem;
}

QModelIndex	MongoJobModel::index(int row, int column, const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (!hasIndex(row, column, parent))
	{
		return QModelIndex();
	}

	MongoJobData *parentItem = NULL;

	if (!parent.isValid())
	{
		parentItem = m_pRootItem;
	}
	else
	{
		parentItem = static_cast<MongoJobData*>(parent.internalPointer());
	}

	MongoJobData *childItem = parentItem->childJobs().at(row);
	if (childItem)
	{
		return createIndex(row, column, childItem);
	}
	else
	{
		return QModelIndex();
	}
}

QModelIndex	MongoJobModel::parent(const QModelIndex& index) const
{
	if (!index.isValid())
	{
		return QModelIndex();
	}

	MongoJobData *childItem = static_cast<MongoJobData*>(index.internalPointer());
	MongoJobData *parentItem = childItem->parent();

	if (parentItem == m_pRootItem)
	{
		return QModelIndex();
	}

	MongoJobData* pParent = parentItem->parent();
	int idx = pParent->childJobs().indexOf(parentItem);
	return createIndex(idx, 0, parentItem);
}

int	MongoJobModel::columnCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	return 2;
}

QVariant MongoJobModel::data(const QModelIndex& index, int role/* = Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole && role != Qt::DecorationRole)
	{
		return QVariant();
	}

	if (!index.isValid())
	{
		return QVariant();
	}

	MongoJobData* pItem = static_cast<MongoJobData*>(index.internalPointer());

	if (role == Qt::DecorationRole)
	{
		if (index.column() == 0)
		{
            if (pItem->jobType() & MongoJobData::Success)
			{
				return m_success;
			}

            if (pItem->jobType() & MongoJobData::Fail)
			{
				return m_fail;
			}

            if (pItem->jobType() & MongoJobData::Cancel)
			{
				return m_cancel;
			}
		}

		return QVariant();
	}

	switch (index.column())
	{
		case 0:
			return pItem->summary();
		case 1:
			return pItem->creationTime().toString("yyyy-MM-dd hh:mm");
	}

	return QVariant();
}

int	MongoJobModel::rowCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	MongoJobData *parentItem;
	if (parent.column() > 0)
	{
		return 0;
	}

	if (!parent.isValid())
	{
		parentItem = m_pRootItem;
	}
	else
	{
		parentItem = static_cast<MongoJobData*>(parent.internalPointer());
	}

	return parentItem->childJobs().size();
}

QVariant MongoJobModel::headerData(int section, Qt::Orientation orientation, int role/* = Qt::DisplayRole*/) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch (section)
		{
		case 0:
			return QString("Summary");
		case 1:
			return QString("Creation time");
		}
	}

	return QVariant();
}

MongoJobData* MongoJobModel::rawData(const QModelIndex & index)
{
	if (!index.isValid())
	{
		return NULL;
	}

	MongoJobData* item = static_cast<MongoJobData*>(index.internalPointer());

	return item;
}

void MongoJobModel::sort(int column, Qt::SortOrder order)
{
	beginResetModel();

	switch (column)
	{
	case 0:
		m_storage->sortByMessage(order == Qt::AscendingOrder);
		break;
	case 1:
		m_storage->sortByTime(order == Qt::AscendingOrder);
		break;
	}

	endResetModel();
}

void MongoJobModel::onBeginChange()
{
	beginResetModel();
}

void MongoJobModel::onEndChange()
{
	m_pRootItem->childJobs().clear();

	foreach(MongoJobData* pItem, m_storage->filteredJobs())
	{
		pItem->setParent(m_pRootItem);
		m_pRootItem->childJobs().append(pItem);
	}

	endResetModel();
}
