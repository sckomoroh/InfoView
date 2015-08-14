#pragma once

#include <QList>

#include "MongoEventData.h"
#include "IMongoEventParserListener.h"
#include "IMongoStorageListener.h"

class MongoEventStorage
	: public IMongoEventParserListener
{
private:
	QList<MongoEventData*> m_events;
	QList<MongoEventData*> m_filteredEvents;

	QList<IMongoStorageListener*> m_listeners;

public:
	MongoEventStorage();
	~MongoEventStorage();

public:
	virtual void onStartParsingBson();
	virtual void onCompleteParsingBson();
	virtual void onStartParsingEvents();
	virtual void onEventParsed(uint iCurrent, uint iTotal);
	virtual void onCompleteParsingEvents();

public:
	void clear();
	void addEvent(MongoEventData* pEvent);

	void addListener(IMongoStorageListener* listener) 
	{
		this->m_listeners.append(listener);
	}

	inline uint originEventsCount() const
	{
		return m_events.count();
	}

	inline uint filteredEventsCount() const
	{
		return m_filteredEvents.count();
	}

	inline MongoEventData* originEventAt(uint iIndex) const
	{
		return m_events.at(iIndex);
	}

	inline MongoEventData* filteredEventAt(uint iIndex) const
	{
		return m_filteredEvents.at(iIndex);
	}

	inline const QList<MongoEventData*>& originEvents() const
	{
		return m_events;
	}

	inline const QList<MongoEventData*>& filteredEvents() const
	{
		return m_filteredEvents	;
	}

	void filterEvents(const QString& filterString, int iFilterFlags);

	void	sortByMessage(bool acsending);
	void	sortByTime(bool acsending);

private:
	void fireBeginChange();
	void fireEndChange();
};

