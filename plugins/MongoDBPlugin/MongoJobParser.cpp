#include "MongoJobParser.h"

#include <QDebug>
#include <QFile>

#include "BsonDocumentSet.h"

MongoJobParser::MongoJobParser()
{
	m_pStorage = new MongoJobStorage;
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
	fireStartBsonParsing();

	m_pStorage->clear();

	if (!QFile::exists(fileName))
	{
		fireCompleteJobParsing();
		return;
	}

	std::string stdString = fileName.toStdString();
	const char* sFileName = stdString.c_str();
	BsonDocumentSet* pDocumentSet = BsonDocumentSetFactory::createFromDump(sFileName);

	fireCompleteBsonParsing();
	fireStartJobParsing();

	uint iJobsCount = pDocumentSet->documents().size();
	uint iCurrentJob = 0;

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

	fireCompleteJobParsing();
}

void MongoJobParser::fireStartBsonParsing()
{
	qDebug() << "[DEBUG] Start parse Jobs BSON dump";

	for each (IJobsParserListener*  pListener in m_pListeners)
	{
		pListener->onStartBsonParsing();
	}
}

void MongoJobParser::fireCompleteBsonParsing()
{
	qDebug() << "[DEBUG] Completed parse Jobs BSON dump";

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
