#pragma once

#include "BaseModelItem.h"
#include "RecoveryPointRecord.h"

class RecoveryPointModelItem : public BaseModelItem
{
private:
	RecoveryPointRecord* m_pRecoveryPointRecord;

public:
	RecoveryPointModelItem(BaseModelItem* pParent, RecoveryPointRecord* pRecoveryPointRecord);
	virtual ~RecoveryPointModelItem();

	const QString content() const;
	const QString& status() const;
	const QString timestamp() const;
	uint size();

	const QString& id() const;

	CheckState checkState();

	static bool ascTimeCompare(BaseModelItem* item1, BaseModelItem* item2);
	static bool descTimeCompare(BaseModelItem* item1, BaseModelItem* item2);

	static bool ascSizeCompare(BaseModelItem* item1, BaseModelItem* item2);
	static bool descSizeCompare(BaseModelItem* item1, BaseModelItem* item2);

};

