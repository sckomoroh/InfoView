#include "BucketModel.h"

BucketModel::BucketModel(QObject *parent)
: QAbstractItemModel(parent)
{

}

BucketModel::~BucketModel()
{

}

void BucketModel::setModelData(const QList<AmazonObject>& objectList)
{
	beginResetModel();

	m_data = objectList;

	endResetModel();
}

QModelIndex	BucketModel::index(int row, int column, const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (!hasIndex(row, column, parent))
	{
		return QModelIndex();
	}

	AmazonObject* pObject = (AmazonObject*)&(m_data.at(row));
	return createIndex(row, column, pObject);
}

QModelIndex	BucketModel::parent(const QModelIndex& index) const
{
	return QModelIndex();
}

int	BucketModel::rowCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (parent.isValid())
	{
		return 0;
	}

	return m_data.count();
}

int	BucketModel::columnCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	return 2;
}

QVariant BucketModel::data(const QModelIndex& index, int role/* = Qt::DisplayRole*/) const
{
	if (!index.isValid())
	{
		return QVariant();
	}

	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}

	AmazonObject* pData = (AmazonObject*)index.internalPointer();

	switch (index.column())
	{
	case 0:
		return pData->link;
	case 1:
		return pData->size;
	}

	return QVariant();
}

AmazonObject* BucketModel::rawData(const QModelIndex& index)
{
	if (!index.isValid())
	{
		return NULL;
	}

	AmazonObject* pData = (AmazonObject*)index.internalPointer();

	return pData;
}

QVariant BucketModel::headerData(int section, Qt::Orientation orientation, int role/* = Qt::DisplayRole*/) const
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
				return "Link";
			case 1:
				return "Size";
			}
		}
	}

	return QVariant();
}

void BucketModel::resetModel()
{
	beginResetModel();

	m_data.clear();

	endResetModel();
}
