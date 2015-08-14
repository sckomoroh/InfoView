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

	if (m_events.isEmpty())
	{
		readEventsMap();
	}
}

MongoEventParser::~MongoEventParser()
{
	delete m_pStorage;
}

void MongoEventParser::parse(const QString& fileName)
{
	fireStartParsingBson();

	m_pStorage->clear();
	
	if (!QFile::exists(fileName))
	{
		fireCompleteParsingEvents();
		return;
	}

	std::string stdFileName = fileName.toStdString();
	const char* sFileName = stdFileName.c_str();
	BsonDocumentSet* pDocumentSet = BsonDocumentSetFactory::createFromDump(sFileName);

	fireCompleteParsingBson();

	fireStartParsingEvents();

	uint iTotal = pDocumentSet->documents().size();
	uint iCurrent = 0;

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
	QString appFolder = QApplication::applicationDirPath();
	QString coreEventFileName = appFolder + "/coreEvents.xml";
	QFile msInfoFile(coreEventFileName);

	if (!msInfoFile.open(QIODevice::ReadOnly))
	{
		return;
	}

	QDomDocument doc;
	if (!doc.setContent(&msInfoFile))
	{
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
