#pragma once

#include <QString>
#include <QList>
#include <QDomElement>

#include "ISystemEventParserListener.h"
#include "SystemEventData.h"
#include "SystemEventStorage.h"

#include "ILogClient.h"

class SystemEventParser
{
private:
	QList<ISystemEventParserListener*> m_listeners;
	SystemEventStorage* m_pStorage;
	ILogClient* m_logClient;

public:
	SystemEventParser();
	~SystemEventParser();

	void parseFile(const QString& fileName);

	void addListener(ISystemEventParserListener* pListener);
	SystemEventStorage* storage();

private:
	SystemEventData* parseXmlEntry(const QDomElement& element);

	SystemEventData::SysEventLevel parseEventLevel(uint iEventLevel);

	void fireEventStartParsing();
	void fireEventParsed(uint iCurrent, uint iTotal);
	void fireEventCompleteParsing();
};
