#pragma once

#include <QList>

#include "MongoEventData.h"

class MongoEventStorage
{
private:
	QList<MongoEventData*> m_events;

public:
	MongoEventStorage();
	~MongoEventStorage();

	void clear();
	void addEvent(MongoEventData* pEvent);

	inline uint eventsCount() const
	{
		return m_events.count();
	}

	inline MongoEventData* eventAt(uint iIndex) const
	{
		return m_events.at(iIndex);
	}

	inline const QList<MongoEventData*>& events() const
	{
		return m_events;
	}

	QList<MongoEventData*> filteredEvents(const QString& filterString, int iFilterFlags);
};

