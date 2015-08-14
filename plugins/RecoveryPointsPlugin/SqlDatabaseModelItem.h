#pragma once

#include "SqlBaseModelItem.h"
#include "CheckStates.h"

class SqlDatabaseModelItem : public SqlBaseModelItem
{
private:
	CheckState m_checkState;

public:
	SqlDatabaseModelItem(const QString& content, SqlBaseModelItem* pParent, CheckState checkState);
	virtual ~SqlDatabaseModelItem();

	CheckState checkState();
};

