#pragma once

#include "ExchangeBaseModelItem.h"
#include "CheckStates.h"

class ExchangeDatabaseModelItem : public ExchangeBaseModelItem
{
private:
	CheckStatesParser::CheckState m_checkState;

public:
	ExchangeDatabaseModelItem(const QString& content, ExchangeBaseModelItem* pParent, CheckStatesParser::CheckState checkState);
	virtual ~ExchangeDatabaseModelItem();

	CheckStatesParser::CheckState checkState();
};

