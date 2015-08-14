#include "ProviderModel.h"

ProviderModel::ProviderModel(QObject *parent)
	: QAbstractItemModel(parent)
{

}

ProviderModel::~ProviderModel()
{

}

void ProviderModel::setModelData(QStringList data)
{
	beginResetModel();

	qSort(data);

	for each (QString item in data)
	{
		m_data.append(new ProviderData(item));
	}

	endResetModel();
}

ProviderData* ProviderModel::rawData(const QModelIndex& index)
{
	if (index.isValid())
	{
		return m_data.at(index.row());
	}

	return NULL;
}

void ProviderModel::inverseProvider(const QModelIndex& index)
{
	beginResetModel();

	if (index.isValid())
	{
		ProviderData* pItem = m_data.at(index.row());
		pItem->setChecked(!pItem->isChecked());
	}

	endResetModel();
}

QStringList ProviderModel::enabledProviders()
{
	QStringList result;

	for each (ProviderData* pItem in m_data)
	{
		if (pItem->isChecked())
		{
			result.append(pItem->data());
		}
	}

	return result;
}

QModelIndex	ProviderModel::index(int row, int column, const QModelIndex & parent) const
{
	if (!hasIndex(row, column, parent))
	{
		return QModelIndex();
	}

	return createIndex(row, column);
}

int	ProviderModel::columnCount(const QModelIndex & parent) const
{
	return 1;
}

QVariant ProviderModel::data(const QModelIndex & index, int role) const
{
	if (!index.isValid())
	{
		return QVariant();
	}

	if (role != Qt::DisplayRole && role != Qt::CheckStateRole)
	{
		return QVariant();
	}

	if (role == Qt::CheckStateRole)
	{
		return m_data.at(index.row())->isChecked() ? Qt::Checked : Qt::Unchecked;
	}

	return m_data.at(index.row())->data();
}

QModelIndex	ProviderModel::parent(const QModelIndex & index) const
{
	return QModelIndex();
}

int	ProviderModel::rowCount(const QModelIndex & parent) const
{
	if (!parent.isValid())
	{
		return m_data.count();
	}

	return 0;
}

Qt::ItemFlags ProviderModel::flags(const QModelIndex & index) const
{
	return Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

void ProviderModel::reset()
{
	beginResetModel();

	for each (ProviderData* pProvider in m_data)
	{
		delete pProvider;
	}

	m_data.clear();

	endResetModel();
}

void ProviderModel::selectAll()
{
	beginResetModel();

	for each (ProviderData* pItem in m_data)
	{
		pItem->setChecked(true);
	}

	endResetModel();
}

void ProviderModel::unselectAll()
{
	beginResetModel();

	for each (ProviderData* pItem in m_data)
	{
		pItem->setChecked(false);
	}

	endResetModel();
}
