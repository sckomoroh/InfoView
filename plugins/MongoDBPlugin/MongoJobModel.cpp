#include "MongoJobModel.h"

#include <QImage>

MongoJobModel::MongoJobModel(QObject *parent)
	: QAbstractItemModel(parent)
	, m_pRootItem(NULL)
{
	m_pRootItem = MongoJobData::emptyObject();
}

MongoJobModel::~MongoJobModel()
{
	delete m_pRootItem;
}

void MongoJobModel::reset()
{
	beginResetModel();

	m_pRootItem->childJobs().clear();

	endResetModel();
}

void MongoJobModel::setModelData(const QList<MongoJobData*>& content)
{
	beginResetModel();

	m_pRootItem->childJobs().clear();

	foreach(MongoJobData* pItem, content)
	{
		pItem->setParent(m_pRootItem);
		m_pRootItem->childJobs().append(pItem);
	}

	endResetModel();
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
            if (pItem->jobType() & MongoJobType::mjtSuccess)
			{
				QImage image = QImage(":/plugin/images/Resources/success.png");
				return image;
			}

            if (pItem->jobType() & MongoJobType::mjtFail)
			{
				return QImage(":/plugin/images/Resources/fail.png");
			}

            if (pItem->jobType() & MongoJobType::mjtCancel)
			{
				return QImage(":/plugin/images/Resources/cancel.png");
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
		sortByMessage(order == Qt::AscendingOrder);
		break;
	case 1:
		sortByTime(order == Qt::AscendingOrder);
		break;
	}

	endResetModel();
}

void MongoJobModel::sortByMessage(bool acsending)
{
	if (acsending)
	{
		qSort(m_pRootItem->childJobs().begin(), m_pRootItem->childJobs().end(), MongoJobData::acsByMessage);
	}
	else
	{
		qSort(m_pRootItem->childJobs().begin(), m_pRootItem->childJobs().end(), MongoJobData::decsByMessage);
	}
}

void MongoJobModel::sortByTime(bool acsending)
{
	if (acsending)
	{
		qSort(m_pRootItem->childJobs().begin(), m_pRootItem->childJobs().end(), MongoJobData::acsByTime);
	}
	else
	{
		qSort(m_pRootItem->childJobs().begin(), m_pRootItem->childJobs().end(), MongoJobData::decsByTime);
	}
}
