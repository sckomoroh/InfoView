#pragma once

#include "BaseModelItem.h"
#include "RecoveryPointRecord.h"

class VolumeModelItem : public BaseModelItem
{
private:
	VolumeImageSummary* m_pVolumeImageSummary;
	Volume* m_pVolume;

public:
	VolumeModelItem(BaseModelItem* pParent, VolumeImageSummary* pVolumeImageSummary, Volume* pVolume);
	virtual ~VolumeModelItem();

	const QString& displayName() const;
	const QString& status() const;
	QString timestamp();
	uint size();

	const QString& volumeId() const;
	uint previousEpochNumber();

	Exchange* exchange();

	QList<SqlInstance*>& sqlInstances();

	CheckState checkState();
};

