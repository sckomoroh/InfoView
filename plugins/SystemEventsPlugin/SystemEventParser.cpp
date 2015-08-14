#include "SystemEventParser.h"

#include <QDebug>
#include <QFile>

SystemEventParser::SystemEventParser()
{
	m_pStorage = new SystemEventStorage;
}

SystemEventParser::~SystemEventParser()
{
	delete m_pStorage;
}

void SystemEventParser::addListener(ISystemEventParserListener* pListener)
{
	m_listeners.append(pListener);
}

void SystemEventParser::parseFile(const QString& fileName)
{
	fireEventStartParsing();

	m_pStorage->clear();

	QFile eventsFile(fileName);
	if (!eventsFile.open(QIODevice::ReadOnly))
	{
		qDebug() << "Unable to open events file";
		fireEventCompleteParsing();
		return;
	}

	QDomDocument doc;
	if (!doc.setContent(&eventsFile))
	{
		qDebug() << "Unable to set content";
		fireEventCompleteParsing();
		eventsFile.close();
		return;
	}

	eventsFile.close();

	QDomElement rootElement = doc.documentElement();
	QDomElement elementIter = rootElement.firstChildElement();

	uint iTotal = rootElement.childNodes().count();
	uint iCurrent = 0;
	while (!elementIter.isNull())
	{
		SystemEventData* record = parseXmlEntry(elementIter);

		m_pStorage->addRecord(record);

		fireEventParsed(++iCurrent, iTotal);

		elementIter = elementIter.nextSiblingElement();
	}

	fireEventCompleteParsing();
}

SystemEventData* SystemEventParser::parseXmlEntry(const QDomElement& element)
{
	QDomElement descriptionElement = element.elementsByTagName("description").at(0).toElement();
	QDomElement idElement = element.elementsByTagName("id").at(0).toElement();
	QDomElement levelElement = element.elementsByTagName("level").at(0).toElement();
	QDomElement providerElement = element.elementsByTagName("providerName").at(0).toElement();
	QDomElement timeElement = element.elementsByTagName("timeCreatedUtc").at(0).toElement();

	QString description = descriptionElement.text();
	QString id = idElement.text();
	QString providerName = providerElement.text();
	QString time = timeElement.text();
	QString level = levelElement.text();

	SystemEventData* record = new SystemEventData;
	record->m_createdTime = QDateTime::fromString(time, Qt::ISODate);
	record->m_description = description;
	record->m_providerName = providerName;
	record->m_eventLevel = parseEventLevel(level.toInt());
	record->m_eventId = id.toInt();

	return record;
}

void SystemEventParser::fireEventStartParsing()
{
	foreach (ISystemEventParserListener* listener, m_listeners)
	{
		listener->onEventStartParsing();
	}
}

void SystemEventParser::fireEventParsed(uint iCurrent, uint iTotal)
{
	foreach (ISystemEventParserListener* listener, m_listeners)
	{
		listener->onEventParsed(iCurrent, iTotal);
	}
}

void SystemEventParser::fireEventCompleteParsing()
{
	foreach (ISystemEventParserListener* listener, m_listeners)
	{
		listener->onEventCompleteParsing();
	}
}

SystemEventStorage* SystemEventParser::storage()
{
	return m_pStorage;
}

SystemEventData::SysEventLevel SystemEventParser::parseEventLevel(uint iEventLevel)
{
	switch (iEventLevel)
	{
		case 1:
			return SystemEventData::SysEventCritical;
		case 2:
			return SystemEventData::SysEventError;
		case 3:
			return SystemEventData::SysEventWarning;
		case 4:
			return SystemEventData::SysEventInfo;
		case 5:
			return SystemEventData::SysEventVerbose;
	}

	if (iEventLevel != 0)
	{
		qDebug() << "UNKNOWN EVENT LEVEL: " << iEventLevel;
	}

	return SystemEventData::SysEventLogAlways;
}