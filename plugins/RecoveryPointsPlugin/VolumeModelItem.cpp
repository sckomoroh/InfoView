#include "VolumeModelItem.h"


VolumeModelItem::VolumeModelItem(BaseModelItem* pParent, VolumeImageSummary* pVolumeImageSummary, Volume* pVolume)
	: BaseModelItem(pParent)
	, m_pVolumeImageSummary(pVolumeImageSummary)
	, m_pVolume(pVolume)
{
}


VolumeModelItem::~VolumeModelItem()
{
}

const QString& VolumeModelItem::displayName() const
{
	return m_pVolumeImageSummary->displayName();
}

const QString& VolumeModelItem::status() const
{
	return m_pVolumeImageSummary->status();
}

QString VolumeModelItem::timestamp()
{
	return m_pVolumeImageSummary->timestamp().toString("yyyy-MM-dd hh:mm");
}

uint VolumeModelItem::size()
{
	return m_pVolumeImageSummary->size();
}

const QString& VolumeModelItem::volumeId() const
{
	return m_pVolumeImageSummary->id();
}

uint VolumeModelItem::previousEpochNumber()
{
	return m_pVolume->previousEpochNumber();
}

Exchange* VolumeModelItem::exchange()
{
	return m_pVolumeImageSummary->exchange();
}

QList<SqlInstance*>& VolumeModelItem::sqlInstances()
{
	return m_pVolumeImageSummary->sqlInstances();
}

CheckState VolumeModelItem::checkState()
{
	return m_pVolumeImageSummary->state();
}
