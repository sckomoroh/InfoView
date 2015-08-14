#include "MsInfoCategoryModel.h"

MsInfoCategoryModel::MsInfoCategoryModel(QObject *parent)
: QAbstractItemModel(parent)
, rootCategory(NULL)
{
}

MsInfoCategoryModel::~MsInfoCategoryModel()
{
}


void MsInfoCategoryModel::setRootCategory(const MsInfoCategory* rootCategory)
{
	beginResetModel();

	this->rootCategory = rootCategory;

	endResetModel();
}

void MsInfoCategoryModel::reset()
{
	beginResetModel();

	rootCategory = NULL;

	endResetModel();
}

QModelIndex	MsInfoCategoryModel::index(int row, int column, const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (!hasIndex(row, column, parent))
	{
		return QModelIndex();
	}

	const MsInfoCategory* parentItem = NULL;
	if (!parent.isValid())
	{
		parentItem = rootCategory;
	}
	else
	{
		parentItem = static_cast<MsInfoCategory*>(parent.internalPointer());
	}

	MsInfoCategory *childItem = parentItem->categories().at(row);
	if (childItem)
	{
		return createIndex(row, column, childItem);
	}
	else
	{
		return QModelIndex();
	}
}

int	MsInfoCategoryModel::columnCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	return 1;
}

QVariant MsInfoCategoryModel::data(const QModelIndex& index, int role/* = Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}

	MsInfoCategory* item = rawData(index);

	if (item == NULL)
	{
		return QVariant();
	}

	return item->categoryName();
}

QModelIndex	MsInfoCategoryModel::parent(const QModelIndex& index) const
{
	if (!index.isValid())
	{
		return QModelIndex();
	}

	MsInfoCategory* childItem = static_cast<MsInfoCategory*>(index.internalPointer());
	const MsInfoCategory* parentItem = childItem->parent();

	if (parentItem == rootCategory)
	{
		return QModelIndex();
	}

	return createIndex(parentItem->row(), 0, (void*)parentItem);
}

int	MsInfoCategoryModel::rowCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	const MsInfoCategory *parentItem;
	if (parent.column() > 0)
	{
		return 0;
	}

	if (!parent.isValid())
	{
		parentItem = rootCategory;
	}
	else
	{
		parentItem = static_cast<MsInfoCategory*>(parent.internalPointer());
	}


	if (parentItem == NULL)
	{
		return 0;
	}

	return parentItem->categories().count();
}

QVariant MsInfoCategoryModel::headerData(int section, Qt::Orientation orientation, int role/* = Qt::DisplayRole*/) const
{
	if (orientation == Qt::Orientation::Horizontal)
	{
		return QString("Categories");
	}

	return QVariant();
}

MsInfoCategory* MsInfoCategoryModel::rawData(const QModelIndex& index) const
{
	if (!index.isValid())
	{
		return NULL;
	}

	return static_cast<MsInfoCategory*>(index.internalPointer());
}
