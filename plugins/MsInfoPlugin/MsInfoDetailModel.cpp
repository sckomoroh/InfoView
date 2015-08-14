#include "MsInfoDetailModel.h"

#include <qdebug>

MsInfoDetailModel::MsInfoDetailModel(QObject *parent)
: QAbstractItemModel(parent)
{
}

MsInfoDetailModel::~MsInfoDetailModel()
{
}

void MsInfoDetailModel::setCategory(MsInfoCategory* category)
{
	beginResetModel();

	m_headers = category->headers();
	m_details = category->details();

	endResetModel();
}

void MsInfoDetailModel::reset()
{
	beginResetModel();

	m_headers.clear();
	m_details.clear();

	endResetModel();
}

QModelIndex	MsInfoDetailModel::index(int row, int column, const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (!hasIndex(row, column, parent))
	{
		return QModelIndex();
	}

	return createIndex(row, column);
}

int	MsInfoDetailModel::columnCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	return m_headers.count();
}

QVariant MsInfoDetailModel::data(const QModelIndex& index, int role/* = Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}

	if (!index.isValid())
	{
		return QVariant();
	}

	return m_details.at(index.row())->values().at(index.column());
}

QModelIndex	MsInfoDetailModel::parent(const QModelIndex& index) const
{
	return QModelIndex();
}

int	MsInfoDetailModel::rowCount(const QModelIndex& parent/* = QModelIndex()*/) const
{
	if (parent.isValid())
	{
		return 0;
	}

	return m_details.count();
}

QVariant MsInfoDetailModel::headerData(int section, Qt::Orientation orientation, int role/* = Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}

	if (orientation == Qt::Horizontal)
	{
		if (section < m_headers.count())
		{
			return m_headers.at(section);
		}
	}

	return QVariant();
}


void MsInfoDetailModel::sort(int column, Qt::SortOrder order)
{
	beginResetModel();

	MsInfoDetail::m_iSortColumn = column;
	if (order == Qt::AscendingOrder)
	{
		qSort(m_details.begin(), m_details.end(), MsInfoDetail::ascCompare);
	}
	else
	{
		qSort(m_details.begin(), m_details.end(), MsInfoDetail::descCompare);
	}

	endResetModel();
}
