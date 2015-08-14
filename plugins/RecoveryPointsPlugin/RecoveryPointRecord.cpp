#include "RecoveryPointRecord.h"

RecoveryPointRecord::~RecoveryPointRecord()
{
	{
		QList<Volume*>::iterator iter = m_volumeList.begin();
		for (; iter != m_volumeList.end(); iter++)
		{
			Volume* pVolume = *iter;
			delete pVolume;
		}

		m_volumeList.clear();
	}

	{
		QList<VolumeImageSummary*>::iterator iter = m_volumeSummaryList.begin();
		for (; iter != m_volumeSummaryList.end(); iter++)
		{
			VolumeImageSummary* pVolumeImageSummary = *iter;
			delete pVolumeImageSummary;
		}

		m_volumeSummaryList.clear();
	}
}

const QString RecoveryPointRecord::content() const
{
	QString result = "";
	
	QListIterator<VolumeImageSummary*> iter(m_volumeSummaryList);
	while (iter.hasNext())
	{
		VolumeImageSummary* imageSummary = iter.next();
		result += imageSummary->displayName();

		if (iter.hasNext())
		{
			result += ", ";
		}
	}

	return result;
}

const QString& RecoveryPointRecord::agentHostName() const
{
	return m_agentHostName;
}

const QString& RecoveryPointRecord::agentId() const
{
	return m_agentId;
}

const QString& RecoveryPointRecord::recoveryPointId() const
{
	return m_recoveryPointId;
}

const QString& RecoveryPointRecord::status() const
{
	return m_status;
}

qlonglong RecoveryPointRecord::size() const
{
	return m_iSize;
}

const QDateTime& RecoveryPointRecord::timestamp() const
{
	return m_timeStamp;
}

QList<Volume*>& RecoveryPointRecord::volumes()
{
	return m_volumeList;
}

QList<VolumeImageSummary*>& RecoveryPointRecord::volumeImageSummuries()
{
	return m_volumeSummaryList;
}

