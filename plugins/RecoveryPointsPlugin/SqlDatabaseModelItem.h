#pragma once

#include "SqlBaseModelItem.h"
#include "CheckStates.h"

class SqlDatabaseModelItem : public SqlBaseModelItem
{
private:
	CheckStatesParser::CheckState m_checkState;

public:
	SqlDatabaseModelItem(const QString& content, SqlBaseModelItem* pParent, CheckStatesParser::CheckState checkState);
	virtual ~SqlDatabaseModelItem();

	CheckStatesParser::CheckState checkState();
};

