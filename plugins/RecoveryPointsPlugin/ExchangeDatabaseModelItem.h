#pragma once

#include "ExchangeBaseModelItem.h"
#include "CheckStates.h"

class ExchangeDatabaseModelItem : public ExchangeBaseModelItem
{
private:
	CheckState m_checkState;

public:
	ExchangeDatabaseModelItem(const QString& content, ExchangeBaseModelItem* pParent, CheckState checkState);
	virtual ~ExchangeDatabaseModelItem();

	CheckState checkState();
};

