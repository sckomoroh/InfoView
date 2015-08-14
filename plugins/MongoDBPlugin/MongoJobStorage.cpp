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
}

QList<MongoJobData*> MongoJobStorage::filteredJob(MongoJobType jobType, const QString& filterString)
{
	QList<MongoJobData*> result;

	for each (MongoJobData* pJob in m_jobs)
	{
		if ((jobType & pJob->jobType()) != pJob->jobType())
		{
			continue;
		}

		if (filterString.isNull() || filterString.isEmpty())
		{
			result.append(pJob);
		}
		else if (pJob->summary().contains(filterString, Qt::CaseInsensitive))
		{
			result.append(pJob);
		}
	}

	return result;
}
