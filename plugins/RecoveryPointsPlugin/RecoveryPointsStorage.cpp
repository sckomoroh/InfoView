#include "RecoveryPointsStorage.h"

#include "AgentModelItem.h"
#include "VolumeModelItem.h"

RecoveryPointsStorage::RecoveryPointsStorage()
{
	m_pRootItem = new BaseModelItem(NULL);
}


RecoveryPointsStorage::~RecoveryPointsStorage()
{
}

void RecoveryPointsStorage::clear()
{
	QList<BaseModelItem*>& children = m_pRootItem->children();
	for each (BaseModelItem* pItem in children)
	{
		delete pItem;
	}

	children.clear();
}

BaseModelItem* RecoveryPointsStorage::rootItem()
{
	return m_pRootItem;
}

void RecoveryPointsStorage::appendAgent(QList<RecoveryPointRecord*> recoveryPoints)
{
	RecoveryPointRecord* recoveryPoint = recoveryPoints.at(0);
	QString agentDisplayName = recoveryPoint->agentHostName();
	QString agentId = recoveryPoint->agentId();
	AgentModelItem* pAgentItem = new AgentModelItem(m_pRootItem, agentDisplayName, agentId);

	for each (RecoveryPointRecord* recoveryPoint in recoveryPoints)
	{
		RecoveryPointModelItem* pRecoveryPointItem = new RecoveryPointModelItem(pAgentItem, recoveryPoint);

		for each (VolumeImageSummary* volumeImageSummary in recoveryPoint->volumeImageSummuries())
		{
			Volume* pVolume = NULL;
			for each (Volume* pVolumeIter in recoveryPoint->volumes())
			{
				if (pVolumeIter->guidName() == volumeImageSummary->guidName())
				{
					pVolume = pVolumeIter;
					break;
				}
			}

			new VolumeModelItem(pRecoveryPointItem, volumeImageSummary, pVolume);
		}
	}
}
