#include "MongoJobParser.h"

#include <QDebug>
#include <QFile>

#include "BsonDocumentSet.h"

MongoJobParser::MongoJobParser()
{
	m_pStorage = new MongoJobStorage;
	m_logClient = getLogClientInstance();

	addListener(m_pStorage);
}

MongoJobParser::~MongoJobParser()
{
	delete m_pStorage;
}

void MongoJobParser::addListener(IJobsParserListener* pListener)
{
	m_pListeners.append(pListener);
}

void MongoJobParser::parse(const QString& fileName)
{
	m_logClient->Info("<MONGO_JOB> Parse Mongo jobs from file %s", fileName.toStdString().c_str());
	fireStartBsonParsing();

	m_pStorage->clear();

	if (!QFile::exists(fileName))
	{
		m_logClient->Error("<MONGO_JOB> The file does not exists");
		fireCompleteJobParsing();
		return;
	}

	std::string stdString = fileName.toStdString();
	const char* sFileName = stdString.c_str();

	m_logClient->Debug("<MONGO_JOB> Parse BSON content");
	BsonDocumentSet* pDocumentSet = BsonDocumentSetFactory::createFromDump(sFileName);

	fireCompleteBsonParsing();
	fireStartJobParsing();

	uint iJobsCount = pDocumentSet->documents().size();
	uint iCurrentJob = 0;

	m_logClient->Debug("<MONGO_JOB> Parse objects");
	std::list<BsonDocument*>::iterator docIter = pDocumentSet->documents().begin();
	for (; docIter != pDocumentSet->documents().end(); docIter++)
	{
		BsonDocument* pDocument = *docIter;
		
		char* jobContent = pDocument->elementByName("SerializedBackgroundJobInfo")->asUtfString();
		MongoJobData* pJobObject = MongoJobData::parseFromContent(jobContent);
		fireJobParsed(++iCurrentJob, iJobsCount);

		m_pStorage->addItem(pJobObject);
	}

	delete pDocumentSet;

	m_logClient->Info("<MONGO_JOB> Complete parsing");
	fireCompleteJobParsing();
}

void MongoJobParser::fireStartBsonParsing()
{
	for each (IJobsParserListener*  pListener in m_pListeners)
	{
		pListener->onStartBsonParsing();
	}
}

void MongoJobParser::fireCompleteBsonParsing()
{
	for each (IJobsParserListener*  pListener in m_pListeners)
	{
		pListener->onCompleteBsonParsing();
	}
}

void MongoJobParser::fireStartJobParsing()
{
	for each (IJobsParserListener*  pListener in m_pListeners)
	{
		pListener->onStartJobParsing();
	}
}

void MongoJobParser::fireJobParsed(uint iCurrent, uint iTotal)
{
	for each (IJobsParserListener*  pListener in m_pListeners)
	{
		pListener->onJobParsed(iCurrent, iTotal);
	}
}

void MongoJobParser::fireCompleteJobParsing()
{
	for each (IJobsParserListener*  pListener in m_pListeners)
	{
		pListener->onCompleteJobParsing();
	}
}
