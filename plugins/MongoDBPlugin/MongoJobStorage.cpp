#include "MongoJobStorage.h"


MongoJobStorage::MongoJobStorage()
{
}

MongoJobStorage::~MongoJobStorage()
{
	clear();
}

void MongoJobStorage::clear()
{
	for each (MongoJobData* pObject in m_jobs)
	{
		delete pObject;
	}

	m_jobs.clear();
}

void MongoJobStorage::addItem(MongoJobData* pItem)
{
	m_jobs.append(pItem);
	m_filteredJobs.append(pItem);
}

void MongoJobStorage::filterJob(MongoJobData::MongoJobType jobType, const QString& filterString)
{
	fireBeginChange();

	m_filteredJobs.clear();

	for each (MongoJobData* pJob in m_jobs)
	{
		if ((jobType & pJob->jobType()) != pJob->jobType())
		{
			continue;
		}

		if (filterString.isNull() || filterString.isEmpty())
		{
			m_filteredJobs.append(pJob);
		}
		else if (pJob->summary().contains(filterString, Qt::CaseInsensitive))
		{
			m_filteredJobs.append(pJob);
		}
	}

	fireEndChange();
}

void MongoJobStorage::onStartBsonParsing()
{
}

void MongoJobStorage::onCompleteBsonParsing()
{
}

void MongoJobStorage::onStartJobParsing()
{
}

void MongoJobStorage::onJobParsed(uint iCurrent, uint iTotal)
{
}

void MongoJobStorage::onCompleteJobParsing()
{
	sortByTime(false);
}

void MongoJobStorage::sortByMessage(bool acsending)
{
	fireBeginChange();

	if (acsending)
	{
		qSort(m_jobs.begin(), m_jobs.end(), MongoJobData::acsByMessage);
		qSort(m_filteredJobs.begin(), m_filteredJobs.end(), MongoJobData::acsByMessage);
	}
	else
	{
		qSort(m_jobs.begin(), m_jobs.end(), MongoJobData::decsByMessage);
		qSort(m_filteredJobs.begin(), m_filteredJobs.end(), MongoJobData::decsByMessage);
	}

	fireEndChange();
}

void MongoJobStorage::sortByTime(bool acsending)
{
	fireBeginChange();

	if (acsending)
	{
		qSort(m_jobs.begin(), m_jobs.end(), MongoJobData::acsByTime);
		qSort(m_filteredJobs.begin(), m_filteredJobs.end(), MongoJobData::acsByTime);
	}
	else
	{
		qSort(m_jobs.begin(), m_jobs.end(), MongoJobData::decsByTime);
		qSort(m_filteredJobs.begin(), m_filteredJobs.end(), MongoJobData::decsByTime);
	}

	fireEndChange();
}

void MongoJobStorage::fireBeginChange()
{
	foreach(IMongoStorageListener* listener, m_listeners)
	{
		listener->onBeginChange();
	}
}

void MongoJobStorage::fireEndChange()
{
	foreach(IMongoStorageListener* listener, m_listeners)
	{
		listener->onEndChange();
	}
}
