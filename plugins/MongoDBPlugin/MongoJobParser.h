#pragma once

#include <QList>
#include <QString>

#include "IMongoJobParserListener.h"
#include "MongoJobStorage.h"

#include "ILogClient.h"

class MongoJobParser
{
private:
	QList<IJobsParserListener*> m_pListeners;
	MongoJobStorage* m_pStorage;

	ILogClient* m_logClient;

public:
	MongoJobParser();
	~MongoJobParser();

	void addListener(IJobsParserListener* pListener);
	void parse(const QString& fileName);

	inline MongoJobStorage* storage()
	{
		return m_pStorage;
	}

private:
	void fireStartBsonParsing();
	void fireCompleteBsonParsing();

	void fireStartJobParsing();
	void fireJobParsed(uint iCurrent, uint iTotal);
	void fireCompleteJobParsing();
};

