#include "RegKeyModel.h"

RegKeyModel::RegKeyModel(QObject *parent)
	: QAbstractItemModel(parent)
	, m_pRootKey(NULL)
{

}

RegKeyModel::~RegKeyModel()
{

}

void RegKeyModel::setModelData(const RegKeyData* pRootKey)
{
	beginResetModel();

	m_pRootKey = pRootKey;

	endResetModel();
}

void RegKeyModel::reset()
{
	beginResetModel();

	m_pRootKey = NULL;

	endResetModel();
}

QModelIndex	RegKeyModel::index(int row, int column, const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (!hasIndex(row, column, parent))
	{
		return QModelIndex();
	}

	const RegKeyData *parentItem = NULL;

	if (!parent.isValid())
	{
		parentItem = m_pRootKey;
	}
	else
	{
		parentItem = static_cast<RegKeyData*>(parent.internalPointer());
	}

	RegKeyData *childItem = parentItem->keys().at(row);
	if (childItem)
	{
		return createIndex(row, column, childItem);
	}
	else
	{
		return QModelIndex();
	}
}

QModelIndex	RegKeyModel::parent(const QModelIndex& index) const
{
	if (!index.isValid())
	{
		return QModelIndex();
	}

	RegKeyData *childItem = static_cast<RegKeyData*>(index.internalPointer());
	RegKeyData *parentItem = childItem->parent();

	if (parentItem == m_pRootKey || parentItem == NULL)
	{
		return QModelIndex();
	}

	RegKeyData* pParent = parentItem->parent();
	if (pParent == NULL)
	{
		return QModelIndex();
	}

	int idx = pParent->keys().indexOf(parentItem);
	return createIndex(idx, 0, parentItem);
}

int	RegKeyModel::columnCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	return 1;
}

QVariant RegKeyModel::data(const QModelIndex& index, int role/* = Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}

	if (!index.isValid())
	{
		return QVariant();
	}

	RegKeyData* pItem = static_cast<RegKeyData*>(index.internalPointer());
	if (pItem != NULL)
	{
		return pItem->shortName();
	}

	return QVariant();
}

int	RegKeyModel::rowCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	const RegKeyData *parentItem;
	if (parent.column() > 0)
	{
		return 0;
	}

	if (!parent.isValid())
	{
		parentItem = m_pRootKey;
	}
	else
	{
		parentItem = static_cast<RegKeyData*>(parent.internalPointer());
	}

	if (parentItem != NULL)
	{
		return parentItem->keys().size();
	}

	return 0;
}

QVariant RegKeyModel::headerData(int section, Qt::Orientation orientation, int role/* = Qt::DisplayRole*/) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		return QString("Key name");
	}

	return QVariant();
}

RegKeyData* RegKeyModel::rawData(const QModelIndex & index)
{
	if (!index.isValid())
	{
		return NULL;
	}

	RegKeyData* item = static_cast<RegKeyData*>(index.internalPointer());

	return item;
}
