#include "AgentModelItem.h"

AgentModelItem::AgentModelItem(BaseModelItem* pParent, const QString& displayName, const QString& id)
	: BaseModelItem(pParent)
	, m_agentHostName(displayName)
	, m_id(id)
{
}

AgentModelItem::~AgentModelItem()
{
}

QString& AgentModelItem::displayName()
{
	return m_agentHostName;
}

QString& AgentModelItem::id()
{
	return m_id;
}
