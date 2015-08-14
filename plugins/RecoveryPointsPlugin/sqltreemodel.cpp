#include "sqltreemodel.h"

#include <QImage>
#include <QDebug>

#include "Volume.h"
#include "SqlDatabaseModelItem.h"

SqlTreeModel::SqlTreeModel(QObject *parent)
	: QAbstractItemModel(parent)
	, m_pRootItem(NULL)
{
	qDebug() << "\tCreating SQL TREE MODEL";
}

SqlTreeModel::~SqlTreeModel()
{
	qDebug() << "\tRemoving SQL TREE MODEL";

	if (m_pRootItem)
	{
		delete m_pRootItem;
	}
}

void SqlTreeModel::reset()
{
	beginResetModel();

	if (m_pRootItem)
	{
		delete m_pRootItem;
		m_pRootItem = NULL;
	}

	endResetModel();
}

void SqlTreeModel::buildModel(QList<SqlInstance*> sqlInstances)
{
	beginResetModel();

	m_pRootItem = new SqlBaseModelItem("ROOT", NULL);

	for each (SqlInstance* pSqlInstance in sqlInstances)
	{
		SqlBaseModelItem* pNameItem = new SqlBaseModelItem(pSqlInstance->name(), m_pRootItem);
		new SqlBaseModelItem(pSqlInstance->version(), pNameItem);
		
		SqlBaseModelItem* pDBTitleItem = new SqlBaseModelItem("Databases", pNameItem);
		for each (SqlDatabase* pSqlDatabase in pSqlInstance->databases())
		{
			SqlDatabaseModelItem* pDatabaseItem = new SqlDatabaseModelItem(pSqlDatabase->name(), pDBTitleItem, pSqlDatabase->checkState());
			new SqlBaseModelItem(pSqlDatabase->IsOnline() ? "Online" : "Offline", pDatabaseItem);

			SqlBaseModelItem* pLogFilesTitleItem = new SqlBaseModelItem("Log files", pDatabaseItem);
			for each (SqlLogFile* pLogFile in pSqlDatabase->logFiles())
			{
				SqlBaseModelItem* pLogFileNameItem = new SqlBaseModelItem(pLogFile->fileName(), pLogFilesTitleItem);
				new SqlBaseModelItem(Volume::strSize(pLogFile->size()), pLogFileNameItem);
			}

			SqlBaseModelItem* pFileGroupsTitleItem = new SqlBaseModelItem("File groups", pDatabaseItem);
			for each (SqlFileGroup* pFileGroup in pSqlDatabase->fileGroups())
			{
				SqlBaseModelItem* pGroupNameItem = new SqlBaseModelItem(pFileGroup->name(), pFileGroupsTitleItem);
				new SqlBaseModelItem(pFileGroup->isFileStream() ? "Filestream" : "Not filestream", pGroupNameItem);

				SqlBaseModelItem* pDataFilesTitleItem = new SqlBaseModelItem("Data files", pGroupNameItem);
				for each (SqlDataFile* pDataFile in pFileGroup->dataFiles())
				{
					SqlBaseModelItem* pDataFileNameItem = new SqlBaseModelItem(pDataFile->fileName(), pDataFilesTitleItem);
					new SqlBaseModelItem(Volume::strSize(pDataFile->size()), pDataFileNameItem);
				}
			}
		}
	}

	endResetModel();
}

QVariant SqlTreeModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
	{
		return QVariant();
	}

	if (role != Qt::DisplayRole && role != Qt::DecorationRole)
	{
		return QVariant();
	}

	SqlBaseModelItem* pItem = static_cast<SqlBaseModelItem*>(index.internalPointer());
	SqlDatabaseModelItem* pDatabase = dynamic_cast<SqlDatabaseModelItem*>(pItem);
	if (pDatabase != NULL)
	{
		return databaseModelItemData(pDatabase, role);
	}

	return baseModelItemData(pItem, role);
}

QVariant SqlTreeModel::headerData(int, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		return "Content";
	}

	return QVariant();
}

QModelIndex SqlTreeModel::index(int row, int column, const QModelIndex &parent) const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();

	SqlBaseModelItem* pParentItem;

	if (!parent.isValid())
	{
		pParentItem = m_pRootItem;
	}
	else
	{
		pParentItem = static_cast<SqlBaseModelItem*>(parent.internalPointer());
	}

	SqlBaseModelItem* pChildItem = pParentItem->child(row);

	if (pChildItem)
	{
		return createIndex(row, column, pChildItem);
	}
	else
	{
		return QModelIndex();
	}
}

QModelIndex SqlTreeModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
	{
		return QModelIndex();
	}

	SqlBaseModelItem* pChildItem = static_cast<SqlBaseModelItem*>(index.internalPointer());
	SqlBaseModelItem* pParentItem = pChildItem->parent();

	if (pParentItem == m_pRootItem)
	{
		return QModelIndex();
	}

	return createIndex(pParentItem->row(), 0, pParentItem);
}

int SqlTreeModel::rowCount(const QModelIndex &parent) const
{
	SqlBaseModelItem *pParentItem;
	if (parent.column() > 0)
	{
		return 0;
	}

	if (!parent.isValid())
	{
		pParentItem = m_pRootItem;
	}
	else
	{
		pParentItem = static_cast<SqlBaseModelItem*>(parent.internalPointer());
	}

	if (pParentItem == NULL)
	{
		return 0;
	}

	return pParentItem->childCount();
}

int SqlTreeModel::columnCount(const QModelIndex&) const
{
	return 1;
}

QVariant SqlTreeModel::baseModelItemData(SqlBaseModelItem* pSqlBaseModelItem, int role) const
{
	if (role == Qt::DisplayRole)
	{
		return pSqlBaseModelItem->content();
	}

	return QVariant();
}

QVariant SqlTreeModel::databaseModelItemData(SqlDatabaseModelItem* pSqlDatabaseModelItem, int role) const
{
	if (role == Qt::DisplayRole)
	{
		return pSqlDatabaseModelItem->content();
	}

	if (role == Qt::DecorationRole)
	{
		switch (pSqlDatabaseModelItem->checkState())
		{
			case CheckState::Yellow:
				return QImage(":/plugin/images/Resources/YellowBall.png");
			case CheckState::Red:
				return QImage(":/plugin/images/Resources/RedBall.png");
			case CheckState::Green:
				return QImage(":/plugin/images/Resources/GreenBall.png");
		}

		return QImage(":/plugin/images/Resources/GrayBall.png");
	}

	return QVariant();
}
