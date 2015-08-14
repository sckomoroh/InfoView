#pragma once

#include <QString>
#include <QList>
#include <QMap>

#include "IMongoEventParserListener.h"
#include "MongoEventStorage.h"

class MongoEventParser
{
private:
	static QMap<QString, EventLevel> m_events;

	QList<IMongoEventParserListener*> m_listeners;
	MongoEventStorage* m_pStorage;

public:
	MongoEventParser();
	~MongoEventParser();

	void parse(const QString& fileName);
	void addListener(IMongoEventParserListener* pListener);
	
	inline MongoEventStorage* storage()
	{
		return m_pStorage;
	}

private:
	void fireStartParsingBson();
	void fireCompleteParsingBson();
	void fireStartParsingEvents();
	void fireEventParsed(uint iCurrent, uint iTotal);
	void fireCompleteParsingEvents();

	static void readEventsMap();
	static EventLevel parseEventLevel(const QString& strLevel);
};

