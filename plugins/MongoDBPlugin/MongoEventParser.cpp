#include "MongoEventParser.h"

#include <QFile>
#include <QDomDOcument>
#include <QDebug>
#include <QApplication>

#include "BsonDocumentSet.h"
#include "MongoEventData.h"

QMap<QString, MongoEventData::EventLevel> MongoEventParser::m_events;

MongoEventParser::MongoEventParser()
{
	m_pStorage = new MongoEventStorage;

	m_logClient = getLogClientInstance();

	addListener(m_pStorage);

	if (m_events.isEmpty())
	{
		m_logClient->Debug("<MONGO-EVT> The core events dump is empty so try to read its.");
		readEventsMap();
	}
}

MongoEventParser::~MongoEventParser()
{
	delete m_pStorage;
}

void MongoEventParser::parse(const QString& fileName)
{
	m_logClient->Info("<MONGO-EVT> Start parse Mongo events file %s", fileName.toStdString().c_str());
	fireStartParsingBson();

	m_pStorage->clear();
	
	if (!QFile::exists(fileName))
	{
		m_logClient->Error("<MONGO-EVT> File does not exists");
		fireCompleteParsingEvents();
		return;
	}

	std::string stdFileName = fileName.toStdString();
	const char* sFileName = stdFileName.c_str();

	m_logClient->Debug("<MONGO-EVT> Parse BSON content");
	BsonDocumentSet* pDocumentSet = BsonDocumentSetFactory::createFromDump(sFileName);

	fireCompleteParsingBson();

	fireStartParsingEvents();

	uint iTotal = pDocumentSet->documents().size();
	uint iCurrent = 0;

	m_logClient->Debug("<MONGO-EVT> Parse objects");
	std::list<BsonDocument*>::iterator iter = pDocumentSet->documents().begin();
	for (; iter != pDocumentSet->documents().end(); iter++)
	{
		BsonDocument* pDocument = *iter;
		MongoEventData* pObject = MongoEventData::createFromBson(pDocument);

		QString eventClassName = pDocument->elementByName("EventTypeName")->asUtfString();
		int eventLevel = 0;

		if (m_events.keys().contains(eventClassName))
		{
			eventLevel = m_events[eventClassName];
		}
		else
		{
			eventLevel = MongoEventData::EventUnknown;
			pObject->setLevel((MongoEventData::EventLevel)eventLevel);
		}

		fireEventParsed(++iCurrent, iTotal);

		if (pObject->isAlert())
		{
			eventLevel |= (int)MongoEventData::EventAlert;
		}
		else
		{
			eventLevel |= (int)MongoEventData::EventEvent;
		}

		pObject->setLevel((MongoEventData::EventLevel)eventLevel);
		m_pStorage->addEvent(pObject);
	}

	delete pDocumentSet;

	fireCompleteParsingEvents();
}

void MongoEventParser::addListener(IMongoEventParserListener* pListener)
{
	m_listeners.append(pListener);
}

void MongoEventParser::fireStartParsingBson()
{
	for each (IMongoEventParserListener* pListener in m_listeners)
	{
		pListener->onStartParsingBson();
	}
}

void MongoEventParser::fireCompleteParsingBson()
{
	for each (IMongoEventParserListener* pListener in m_listeners)
	{
		pListener->onCompleteParsingBson();
	}
}

void MongoEventParser::fireStartParsingEvents()
{
	for each (IMongoEventParserListener* pListener in m_listeners)
	{
		pListener->onStartParsingEvents();
	}
}

void MongoEventParser::fireEventParsed(uint iCurrent, uint iTotal)
{
	for each (IMongoEventParserListener* pListener in m_listeners)
	{
		pListener->onEventParsed(iCurrent, iTotal);
	}
}

void MongoEventParser::fireCompleteParsingEvents()
{
	for each (IMongoEventParserListener* pListener in m_listeners)
	{
		pListener->onCompleteParsingEvents();
	}
}

void MongoEventParser::readEventsMap()
{
	m_logClient->Debug("<MONGO-EVT> Start parse core events dump");

	QString appFolder = QApplication::applicationDirPath();
	QString coreEventFileName = appFolder + "/coreEvents.xml";
	QFile msInfoFile(coreEventFileName);

	if (!msInfoFile.open(QIODevice::ReadOnly))
	{
		m_logClient->Error("<MONGO-EVT> Unable to open core events dump file %s", coreEventFileName.toStdString().c_str());
		return;
	}

	QDomDocument doc;
	if (!doc.setContent(&msInfoFile))
	{
		m_logClient->Error("<MONGO-EVT> Unable to parse XML content of the core dump file events");
		return;
	}

	msInfoFile.close();

	QDomElement rootElement = doc.documentElement();
	QDomNodeList events = rootElement.elementsByTagName("eventLevel");
	for (int i = 0; i < events.count(); i++)
	{
		QDomElement eventElement = events.at(i).toElement();

		QString className = eventElement.attribute("className");
		QString eventLevelStr = eventElement.attribute("level");
		MongoEventData::EventLevel eventLevel = MongoEventParser::parseEventLevel(eventLevelStr);

		MongoEventParser::m_events[className] = eventLevel;
	}

	m_logClient->Debug("<MONGO-EVT> Parsing of core events dump is completed");
}

MongoEventData::EventLevel MongoEventParser::parseEventLevel(const QString& strLevel)
{
	if (strLevel == "Info")
	{
		return MongoEventData::EventInformation;
	}

	if (strLevel == "Error")
	{
		return MongoEventData::EventError;
	}

	if (strLevel == "Warning")
	{
		return MongoEventData::EventWarning;
	}

	return MongoEventData::EventUnknown;
}
