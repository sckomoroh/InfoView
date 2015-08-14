#include "RegValueModel.h"

RegValueModel::RegValueModel(QObject *parent)
	: QAbstractItemModel(parent)
{

}

RegValueModel::~RegValueModel()
{

}

void RegValueModel::reset()
{
	beginResetModel();

	m_values.clear();

	endResetModel();
}

void RegValueModel::setModelData(const QList<RegValueData*>& content)
{
	beginResetModel();

	m_values = content;

	endResetModel();
}

QModelIndex	RegValueModel::index(int row, int column, const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (!hasIndex(row, column, parent))
	{
		return QModelIndex();
	}

	return createIndex(row, column);
}

QModelIndex	RegValueModel::parent(const QModelIndex& index) const
{
	return QModelIndex();
}

int	RegValueModel::columnCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	return 3;
}

QVariant RegValueModel::data(const QModelIndex& index, int role/* = Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}

	if (!index.isValid())
	{
		return QVariant();
	}

	RegValueData* pObject = m_values.at(index.row());

	switch (index.column())
	{
	case 0:
		return pObject->name();
	case 1:
		return pObject->valueTypeToString();
	case 2:
		return pObject->value();
	}

	return QVariant();
}

int	RegValueModel::rowCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (parent.isValid())
	{
		return 0;
	}

	return m_values.count();
}

QVariant RegValueModel::headerData(int section, Qt::Orientation orientation, int role/* = Qt::DisplayRole*/) const
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
				return "Name";
			case 1:
				return "Type";
			case 2:
				return "Value";
			}
		}
	}

	return QVariant();
}

QString RegValueModel::rawData(const QModelIndex& index)
{
	RegValueData* pObject = m_values.at(index.row());

	switch (index.column())
	{
	case 0:
		return pObject->name();
	case 1:
		return pObject->valueTypeToString();
	case 2:
		return pObject->value();
	}

	return QString();
}
