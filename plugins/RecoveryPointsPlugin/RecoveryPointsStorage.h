#pragma once

#include <QList>

#include "RecoveryPointRecord.h"
#include "BaseModelItem.h"

class RecoveryPointsStorage
{
private:
	BaseModelItem* m_pRootItem;

public:
	RecoveryPointsStorage();
	~RecoveryPointsStorage();

	void clear();
	BaseModelItem* rootItem();

	void appendAgent(QList<RecoveryPointRecord*> recoveryPoints);
};

