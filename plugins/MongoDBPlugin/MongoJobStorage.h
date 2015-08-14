#pragma once

#include <QList>

#include "MongoJobData.h"
#include "IMongoJobParserListener.h"

class MongoJobStorage
{
private:
	QList<MongoJobData*> m_jobs;

public:
	MongoJobStorage();
	~MongoJobStorage();

	inline uint jobsCount() const 
	{
		return m_jobs.count();
	}

	inline MongoJobData* jobAt(uint iIndex) const
	{
		return m_jobs.at(iIndex);
	}

	inline const QList<MongoJobData*>& jobs() const
	{
		return m_jobs;
	}
	
	void clear();
	void addItem(MongoJobData* pItem);

	QList<MongoJobData*> filteredJob(MongoJobData::MongoJobType jotType, const QString& filterString);
};
