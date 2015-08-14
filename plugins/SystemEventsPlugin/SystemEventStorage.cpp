#include "SystemEventStorage.h"

#include <QStringList>

SystemEventStorage::SystemEventStorage()
{
}


SystemEventStorage::~SystemEventStorage()
{
	clear();
}

void SystemEventStorage::addRecord(SystemEventData* pRecord)
{
	m_records.append(pRecord);
	m_filteredRecords.append(pRecord);
}

void SystemEventStorage::clear()
{
	fireBeginChange();

	foreach (SystemEventData* pRecord, m_records)
	{
		delete pRecord;
	}

	m_records.clear();
	m_filteredRecords.clear();

	fireEndChange();
}

SystemEventData* SystemEventStorage::filteredRecordAt(uint iIndex)
{
	return m_filteredRecords.at(iIndex);
}

uint SystemEventStorage::filteredRecordsCount()
{
	return m_filteredRecords.count();
}

QStringList SystemEventStorage::providersNames()
{
	QStringList result;
	foreach (SystemEventData* pRecord, m_records)
	{
		if (!result.contains(pRecord->providerName()))
		{
			result.append(pRecord->providerName());
		}
	}

	return result;
}

void SystemEventStorage::filterRecords(QList<int> eventIds, QList<QString> providers, int eventLevels)
{
	fireBeginChange();

	m_filteredRecords.clear();
	filterByEventId(eventIds);
	filterByProvider(providers);
	filterByLevels(eventLevels);

	fireEndChange();
}

void SystemEventStorage::filterByEventId(QList<int>& eventIds)
{
	if (eventIds.empty())
	{
		m_filteredRecords = m_records;
		return;
	}

	bool bExcludeEvents = false;
	for each (int eventId in eventIds)
	{
		if (eventId < 0)
		{
			bExcludeEvents = true;
			break;
		}
	}

	if (bExcludeEvents)
	{
		for each (SystemEventData* pRecord in m_records)
		{
			if (!eventIds.contains(-pRecord->eventId()))
			{
				m_filteredRecords.append(pRecord);
			}
		}
	}
	else
	{
		for each (SystemEventData* pRecord in m_records)
		{
			if (eventIds.contains(pRecord->eventId()))
			{
				m_filteredRecords.append(pRecord);
			}
		}
	}
}

void SystemEventStorage::filterByProvider(QList<QString>& providers)
{
	if (providers.empty())
	{
		return;
	}

	QList<SystemEventData*> result;
	for each (SystemEventData* pRecord in m_filteredRecords)
	{
		if (providers.contains(pRecord->providerName()))
		{
			result.append(pRecord);
		}
	}

	m_filteredRecords = result;
}

void SystemEventStorage::filterByLevels(int levels)
{
	QList<SystemEventData*> result;
	for each (SystemEventData* pRecord in m_filteredRecords)
	{
		if ((pRecord->eventLevel() & levels) != 0)
		{
			result.append(pRecord);
		}
	}

	m_filteredRecords = result;
}

void SystemEventStorage::sortByEventId(bool ascending)
{
	fireBeginChange();

	if (ascending)
	{
		qSort(m_records.begin(), m_records.end(), SystemEventData::ascEventIdCompare);
		qSort(m_filteredRecords.begin(), m_filteredRecords.end(), SystemEventData::ascEventIdCompare);
	}
	else
	{
		qSort(m_records.begin(), m_records.end(), SystemEventData::descEventIdCompare);
		qSort(m_filteredRecords.begin(), m_filteredRecords.end(), SystemEventData::descEventIdCompare);
	}

	fireEndChange();
}

void SystemEventStorage::sortByProvider(bool ascending)
{
	fireBeginChange();

	if (ascending)
	{
		qSort(m_records.begin(), m_records.end(), SystemEventData::ascProviderCompare);
		qSort(m_filteredRecords.begin(), m_filteredRecords.end(), SystemEventData::ascProviderCompare);
	}
	else
	{
		qSort(m_records.begin(), m_records.end(), SystemEventData::descProviderCompare);
		qSort(m_filteredRecords.begin(), m_filteredRecords.end(), SystemEventData::descProviderCompare);
	}

	fireEndChange();
}

void SystemEventStorage::sortByTime(bool ascending)
{
	fireBeginChange();

	if (ascending)
	{
		qSort(m_records.begin(), m_records.end(), SystemEventData::ascTimeCompare);
		qSort(m_filteredRecords.begin(), m_filteredRecords.end(), SystemEventData::ascTimeCompare);
	}
	else
	{
		qSort(m_records.begin(), m_records.end(), SystemEventData::descTimeCompare);
		qSort(m_filteredRecords.begin(), m_filteredRecords.end(), SystemEventData::descTimeCompare);
	}

	fireEndChange();
}

void SystemEventStorage::fireBeginChange()
{
	if (m_listener != NULL)
	{
		m_listener->beginStorageChange();
	}
}

void SystemEventStorage::fireEndChange()
{
	if (m_listener != NULL)
	{
		m_listener->endStorageChange();
	}
}

void SystemEventStorage::setListener(IStorageListener* listener)
{
	m_listener = listener;
}

void SystemEventStorage::onEventStartParsing()
{
}

void SystemEventStorage::onEventParsed(uint iCurrent, uint iTotal)
{
}

void SystemEventStorage::onEventCompleteParsing()
{
	fireBeginChange();
	sortByTime(false);
	fireEndChange();
}
