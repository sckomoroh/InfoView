#include "SqlDatabaseModelItem.h"


SqlDatabaseModelItem::SqlDatabaseModelItem(const QString& content, SqlBaseModelItem* pParent, CheckStatesParser::CheckState checkState)
	: SqlBaseModelItem(content, pParent)
	, m_checkState(checkState)
{
}


SqlDatabaseModelItem::~SqlDatabaseModelItem()
{
}

CheckStatesParser::CheckState SqlDatabaseModelItem::checkState()
{
	return m_checkState;
}
