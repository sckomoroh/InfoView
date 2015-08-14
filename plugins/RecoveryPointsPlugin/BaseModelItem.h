#pragma once

#include <QList>

#include "RecoveryPointRecord.h"

class BaseModelItem
{
private:
	BaseModelItem* m_pParent;

protected:
	QList<BaseModelItem*> m_children;

public:
	BaseModelItem(BaseModelItem* pParent);
	virtual ~BaseModelItem();

	QList<BaseModelItem*>& children();

	BaseModelItem* child(int index);
	BaseModelItem* parent();
	int row();
	int childCount();
};

