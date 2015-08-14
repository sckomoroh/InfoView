#include "SqlDatabaseModelItem.h"


SqlDatabaseModelItem::SqlDatabaseModelItem(const QString& content, SqlBaseModelItem* pParent, CheckState checkState)
	: SqlBaseModelItem(content, pParent)
	, m_checkState(checkState)
{
}


SqlDatabaseModelItem::~SqlDatabaseModelItem()
{
}

CheckState SqlDatabaseModelItem::checkState()
{
	return m_checkState;
}
