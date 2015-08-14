#include "ExchangeDatabaseModelItem.h"


ExchangeDatabaseModelItem::ExchangeDatabaseModelItem(const QString& content, ExchangeBaseModelItem* pParent, CheckStatesParser::CheckState checkState)
: ExchangeBaseModelItem(content, pParent)
	, m_checkState(checkState)
{
}

ExchangeDatabaseModelItem::~ExchangeDatabaseModelItem()
{
}

CheckStatesParser::CheckState ExchangeDatabaseModelItem::checkState()
{
	return m_checkState;
}
