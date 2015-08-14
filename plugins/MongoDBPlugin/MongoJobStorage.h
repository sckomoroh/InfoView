#pragma once

#include <QList>

#include "MongoJobData.h"
#include "IMongoJobParserListener.h"
#include "IMongoStorageListener.h"

class MongoJobStorage
	: public IJobsParserListener
{
private:
	QList<MongoJobData*> m_jobs;
	QList<MongoJobData*> m_filteredJobs;
	QList<IMongoStorageListener*> m_listeners;

public:
	MongoJobStorage();
	~MongoJobStorage();

public:
	virtual void onStartBsonParsing();
	virtual void onCompleteBsonParsing();
	virtual void onStartJobParsing();
	virtual void onJobParsed(uint iCurrent, uint iTotal);
	virtual void onCompleteJobParsing();

public:
	inline void addListener(IMongoStorageListener* listener)
	{
		m_listeners.append(listener);
	}

	inline uint originJobsCount() const 
	{
		return m_jobs.count();
	}

	inline MongoJobData* otiginJobAt(uint iIndex) const
	{
		return m_jobs.at(iIndex);
	}

	inline const QList<MongoJobData*>& filteredJobs() const
	{
		return m_filteredJobs;
	}
	
	inline uint filteredJobsCount() const 
	{
		return m_filteredJobs.count();
	}

	inline MongoJobData* filteredJobAt(uint iIndex) const
	{
		return m_filteredJobs.at(iIndex);
	}

	inline const QList<MongoJobData*>& originJobs() const
	{
		return m_jobs;
	}

	void clear();
	void addItem(MongoJobData* pItem);

	void filterJob(MongoJobData::MongoJobType jotType, const QString& filterString);

	void	sortByMessage(bool acsending);
	void	sortByTime(bool acsending);

private:
	void fireBeginChange();
	void fireEndChange();
};
