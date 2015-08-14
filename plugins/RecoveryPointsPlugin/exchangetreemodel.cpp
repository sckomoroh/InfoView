#include "exchangetreemodel.h"

#include <QImage>
#include <QDebug>

QImage ExchangeTreeModel::m_redBall;
QImage ExchangeTreeModel::m_yellowBall;
QImage ExchangeTreeModel::m_grayBall;
QImage ExchangeTreeModel::m_greenBall;

ExchangeTreeModel::ExchangeTreeModel(QObject *parent)
	: QAbstractItemModel(parent)
	, m_pRootItem(NULL)
{
	if (m_redBall.isNull())
	{
		m_redBall = QImage(":/plugin/images/Resources/RedBall.png");
	}

	if (m_yellowBall.isNull())
	{
		m_yellowBall = QImage(":/plugin/images/Resources/YellowBall.png");
	}

	if (m_grayBall.isNull())
	{
		m_grayBall = QImage(":/plugin/images/Resources/GrayBall.png");
	}

	if (m_greenBall.isNull())
	{
		m_greenBall = QImage(":/plugin/images/Resources/GreenBall.png");
	}
}

ExchangeTreeModel::~ExchangeTreeModel()
{
	if (m_pRootItem != NULL)
	{
		delete m_pRootItem;
	}
}

void ExchangeTreeModel::reset()
{
	beginResetModel();
	if (m_pRootItem != NULL)
	{
		delete m_pRootItem;
		m_pRootItem = NULL;
	}
	endResetModel();
}

void ExchangeTreeModel::buildModel(Exchange* pExchange)
{
	beginResetModel();

	m_pRootItem = new ExchangeBaseModelItem("ROOT", NULL);

	for each (MailStore* pMailStore in pExchange->mailStores())
	{
		ExchangeDatabaseModelItem* pNameItem = new ExchangeDatabaseModelItem(pMailStore->name(), m_pRootItem, pMailStore->checkState());
		new ExchangeBaseModelItem(pMailStore->exchangeDatabasePath(), pNameItem);
		new ExchangeBaseModelItem("LOG: " + pMailStore->logFilePath(), pNameItem);
		new ExchangeBaseModelItem("SYS: " + pMailStore->systemPath(), pNameItem);
		new ExchangeBaseModelItem(pMailStore->logPrefix(), pNameItem);
	}

	for each (LegacyStorageGroup* pLegacyStorageGroup in pExchange->legacyStorageGroups())
	{
		ExchangeBaseModelItem* pNameItem = new ExchangeBaseModelItem(pLegacyStorageGroup->name(), m_pRootItem);
		new ExchangeBaseModelItem("LOG: " + pLegacyStorageGroup->logFilePath(), pNameItem);
		new ExchangeBaseModelItem("SYS: " + pLegacyStorageGroup->systemPath(), pNameItem);
		new ExchangeBaseModelItem(pLegacyStorageGroup->logPrefix(), pNameItem);

		if (pLegacyStorageGroup->mailStores().count() > 0)
		{
			ExchangeBaseModelItem* pStorageTitle = new ExchangeBaseModelItem("Legacy mail stores", pNameItem);

			for each (LegacyMailStore* pLegacyMailStore in pLegacyStorageGroup->mailStores())
			{
				ExchangeDatabaseModelItem* pStoreName = new ExchangeDatabaseModelItem(pLegacyMailStore->name(), pStorageTitle, pLegacyMailStore->checkState());
				new ExchangeBaseModelItem(pLegacyMailStore->exchangeDatabasePath(), pStoreName);
				new ExchangeBaseModelItem(pLegacyMailStore->mailStoreType(), pStoreName);
			}
		}
	}

	endResetModel();
}

QVariant ExchangeTreeModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
	{
		return QVariant();
	}

	if (role != Qt::DisplayRole && role != Qt::DecorationRole)
	{
		return QVariant();
	}

	ExchangeBaseModelItem* pItem = static_cast<ExchangeBaseModelItem*>(index.internalPointer());
	ExchangeDatabaseModelItem* pDatabase = dynamic_cast<ExchangeDatabaseModelItem*>(pItem);
	if (pDatabase != NULL)
	{
		return databaseItemData(pDatabase, role);
	}

	return baseItemData(pItem, role);
}

QVariant ExchangeTreeModel::headerData(int, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		return "Content";
	}

	return QVariant();
}

QModelIndex ExchangeTreeModel::index(int row, int column, const QModelIndex &parent) const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();

	ExchangeBaseModelItem* pParentItem;

	if (!parent.isValid())
	{
		pParentItem = m_pRootItem;
	}
	else
	{
		pParentItem = static_cast<ExchangeBaseModelItem*>(parent.internalPointer());
	}

	ExchangeBaseModelItem* pChildItem = pParentItem->child(row);

	if (pChildItem)
	{
		return createIndex(row, column, pChildItem);
	}
	else
	{
		return QModelIndex();
	}
}

QModelIndex ExchangeTreeModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
	{
		return QModelIndex();
	}

	ExchangeBaseModelItem* pChildItem = static_cast<ExchangeBaseModelItem*>(index.internalPointer());
	ExchangeBaseModelItem* pParentItem = pChildItem->parent();

	if (pParentItem == m_pRootItem)
	{
		return QModelIndex();
	}

	return createIndex(pParentItem->row(), 0, pParentItem);
}

int ExchangeTreeModel::rowCount(const QModelIndex &parent) const
{
	ExchangeBaseModelItem *pParentItem;
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
		pParentItem = static_cast<ExchangeBaseModelItem*>(parent.internalPointer());
	}

	if (pParentItem == NULL)
	{
		return 0;
	}

	return pParentItem->childCount();
}

int ExchangeTreeModel::columnCount(const QModelIndex&) const
{
	return 1;
}

QVariant ExchangeTreeModel::baseItemData(ExchangeBaseModelItem* pItemData, int role) const
{
	if (role == Qt::DisplayRole)
	{
		return pItemData->content();
	}

	return QVariant();
}

QVariant ExchangeTreeModel::databaseItemData(ExchangeDatabaseModelItem* pItemData, int role) const
{
	if (role == Qt::DisplayRole)
	{
		return pItemData->content();
	}

	if (role == Qt::DecorationRole)
	{
		switch (pItemData->checkState())
		{
		case CheckStatesParser::Yellow:
			return m_yellowBall;
		case CheckStatesParser::Red:
			return m_redBall;
		case CheckStatesParser::Green:
			return m_greenBall;
		}

		return m_grayBall;
	}

	return QVariant();
}
