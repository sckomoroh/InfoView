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
	for each (MongoEventData* pItem in m_events)
	{
		delete pItem;
	}

	m_events.clear();
}

void MongoEventStorage::addEvent(MongoEventData* pEvent)
{
	m_events.append(pEvent);
}

QList<MongoEventData*> MongoEventStorage::filteredEvents(const QString& filterString, int iFilterFlags)
{
	QList<MongoEventData*> result;

	for each (MongoEventData* pItem in m_events)
	{
		if ((pItem->level() & iFilterFlags) != pItem->level())
		{
			continue;
		}

		if (pItem->message().contains(filterString, Qt::CaseInsensitive))
		{
			result.append(pItem);
		}
	}

	return result;
}
