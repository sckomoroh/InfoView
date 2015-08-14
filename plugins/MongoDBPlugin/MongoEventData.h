#pragma once

#include <QString>
#include <QDateTime>

#include "BsonDocument.h"

enum EventLevel
{
	EventWarning		= 0x1,
	EventError			= 0x2,
	EventInformation	= 0x4,
	EventUnknown		= 0x8,
	EventAlert			= 0x10,
	EventEvent			= 0x20
};

class MongoEventData
{
private:
	QString		m_message;
	QDateTime	m_time;
	bool		m_bIsAlert;
	EventLevel	m_level;

public:
	~MongoEventData();

	inline const QString& message() const
	{
		return m_message;
	}

	inline const QDateTime& time() const
	{
		return m_time;
	}

	inline bool isAlert()
	{
		return m_bIsAlert;
	}

	inline EventLevel level()
	{
		return m_level;
	}

	void setLevel(EventLevel level);

	static MongoEventData* createFromBson(BsonDocument* pDocument);

	static bool acsByMessage(MongoEventData* item1, MongoEventData* item2);
	static bool decsByMessage(MongoEventData* item1, MongoEventData* item2);

	static bool acsByTime(MongoEventData* item1, MongoEventData* item2);
	static bool decsByTime(MongoEventData* item1, MongoEventData* item2);

private:
	MongoEventData();
};

