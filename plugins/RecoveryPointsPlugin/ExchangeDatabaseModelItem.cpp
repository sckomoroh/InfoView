#include "ExchangeDatabaseModelItem.h"


ExchangeDatabaseModelItem::ExchangeDatabaseModelItem(const QString& content, ExchangeBaseModelItem* pParent, CheckState checkState)
: ExchangeBaseModelItem(content, pParent)
	, m_checkState(checkState)
{
}

ExchangeDatabaseModelItem::~ExchangeDatabaseModelItem()
{
}

CheckState ExchangeDatabaseModelItem::checkState()
{
	return m_checkState;
}
