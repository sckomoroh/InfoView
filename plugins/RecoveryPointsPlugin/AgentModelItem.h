#pragma once

#include <QString>
#include <QList>

#include "BaseModelItem.h"
#include "RecoveryPointModelItem.h"


class AgentModelItem : public BaseModelItem
{
private:
	QString m_agentHostName;
	QString m_id;

public:
	AgentModelItem(BaseModelItem* pParent, const QString& displayName, const QString& id);
	~AgentModelItem();

	QString& displayName();
	QString& id();
};

