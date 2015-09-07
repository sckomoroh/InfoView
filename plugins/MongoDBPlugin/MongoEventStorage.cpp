#include "MongoEventStorage.h"


MongoEventStorage::MongoEventStorage()
{
}

MongoEventStorage::~MongoEventStorage()
{
	clear();
}

void MongoEventStorage::clear()
{
	fireBeginChange();

	foreach (MongoEventData* pItem, m_events)
	{
		delete pItem;
	}

	m_filteredEvents.clear();
	m_events.clear();

	fireEndChange();
}

void MongoEventStorage::addEvent(MongoEventData* pEvent)
{
	m_events.append(pEvent);
	m_filteredEvents.append(pEvent);
}

void MongoEventStorage::filterEvents(const QString& filterString, int iFilterFlags)
{
	fireBeginChange();

	m_filteredEvents.clear();

	QList<MongoEventData*> result;

	for each (MongoEventData* pItem in m_events)
	{
		if ((pItem->level() & iFilterFlags) != pItem->level())
		{
			continue;
		}

		if (pItem->message().contains(filterString, Qt::CaseInsensitive))
		{
			m_filteredEvents.append(pItem);
		}
	}

	fireEndChange();
}

void MongoEventStorage::fireBeginChange()
{
	foreach(IMongoStorageListener* listener, m_listeners)
	{
		listener->onBeginChange();
	}
}

void MongoEventStorage::fireEndChange()
{
	foreach(IMongoStorageListener* listener, m_listeners)
	{
		listener->onEndChange();
	}
}

void MongoEventStorage::onStartParsingBson()
{
}

void MongoEventStorage::onCompleteParsingBson()
{
}

void MongoEventStorage::onStartParsingEvents()
{
}

void MongoEventStorage::onEventParsed(uint iCurrent, uint iTotal)
{
}

void MongoEventStorage::onCompleteParsingEvents()
{
	sortByTime(false);
}

void MongoEventStorage::sortByMessage(bool acsending)
{
	fireBeginChange();

	if (acsending)
	{
		qSort(m_events.begin(), m_events.end(), MongoEventData::acsByMessage);
		qSort(m_filteredEvents.begin(), m_filteredEvents.end(), MongoEventData::acsByMessage);
	}
	else
	{
		qSort(m_events.begin(), m_events.end(), MongoEventData::decsByMessage);
		qSort(m_filteredEvents.begin(), m_filteredEvents.end(), MongoEventData::decsByMessage);
	}

	fireEndChange();
}

void MongoEventStorage::sortByTime(bool acsending)
{
	fireBeginChange();

	if (acsending)
	{
		qSort(m_events.begin(), m_events.end(), MongoEventData::acsByTime);
		qSort(m_filteredEvents.begin(), m_filteredEvents.end(), MongoEventData::acsByTime);
	}
	else
	{
		qSort(m_events.begin(), m_events.end(), MongoEventData::decsByTime);
		qSort(m_filteredEvents.begin(), m_filteredEvents.end(), MongoEventData::decsByTime);
	}

	fireEndChange();
}
