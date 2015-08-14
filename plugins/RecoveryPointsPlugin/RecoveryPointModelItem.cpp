#include "RecoveryPointModelItem.h"


RecoveryPointModelItem::RecoveryPointModelItem(BaseModelItem* pParent, RecoveryPointRecord* pRecoveryPointRecord)
	: BaseModelItem(pParent)
	, m_pRecoveryPointRecord(pRecoveryPointRecord)
{
}


RecoveryPointModelItem::~RecoveryPointModelItem()
{
	delete m_pRecoveryPointRecord;
}

const QString& RecoveryPointModelItem::id() const
{
	return m_pRecoveryPointRecord->recoveryPointId();
}

const QString RecoveryPointModelItem::content() const
{
	return m_pRecoveryPointRecord->content();
}

const QString& RecoveryPointModelItem::status() const
{
	return m_pRecoveryPointRecord->status();
}

const QString RecoveryPointModelItem::timestamp() const
{
	return m_pRecoveryPointRecord->timestamp().toString("yyyy-MM-dd hh:mm");
}

uint RecoveryPointModelItem::size()
{
	return m_pRecoveryPointRecord->size();
}

CheckState RecoveryPointModelItem::checkState()
{
	CheckState state = CheckState::NoneState;

	for each (VolumeImageSummary* pVolumeImageSummary in m_pRecoveryPointRecord->volumeImageSummuries())
	{
		if (pVolumeImageSummary->state() == CheckState::Red)
		{
			state = CheckState::Red;
			continue;
		}

		if (pVolumeImageSummary->state() == CheckState::Green && state != CheckState::Red)
		{
			state = CheckState::Green;
			continue;
		}

		if (pVolumeImageSummary->state() == CheckState::Yellow && (state != CheckState::Green && state != CheckState::Red))
		{
			state = CheckState::Yellow;
		}
	}

	return state;
}

bool RecoveryPointModelItem::ascTimeCompare(BaseModelItem* pItem1, BaseModelItem* pItem2)
{
	RecoveryPointModelItem* pRpItem1 = (RecoveryPointModelItem*)pItem1;
	RecoveryPointModelItem* pRpItem2 = (RecoveryPointModelItem*)pItem2;
	
	return pRpItem1->timestamp() > pRpItem2->timestamp();
}

bool RecoveryPointModelItem::descTimeCompare(BaseModelItem* pItem1, BaseModelItem* pItem2)
{
	RecoveryPointModelItem* pRpItem1 = (RecoveryPointModelItem*)pItem1;
	RecoveryPointModelItem* pRpItem2 = (RecoveryPointModelItem*)pItem2;

	return pRpItem1->timestamp() < pRpItem2->timestamp();
}

bool RecoveryPointModelItem::ascSizeCompare(BaseModelItem* pItem1, BaseModelItem* pItem2)
{
	RecoveryPointModelItem* pRpItem1 = (RecoveryPointModelItem*)pItem1;
	RecoveryPointModelItem* pRpItem2 = (RecoveryPointModelItem*)pItem2;

	return pRpItem1->size() > pRpItem2->size();
}

bool RecoveryPointModelItem::descSizeCompare(BaseModelItem* pItem1, BaseModelItem* pItem2)
{
	RecoveryPointModelItem* pRpItem1 = (RecoveryPointModelItem*)pItem1;
	RecoveryPointModelItem* pRpItem2 = (RecoveryPointModelItem*)pItem2;

	return pRpItem1->size() < pRpItem2->size();
}
