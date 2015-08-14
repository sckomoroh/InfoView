#include "SystemEventData.h"


SystemEventData::SystemEventData()
{
}


SystemEventData::~SystemEventData()
{
}

QString& SystemEventData::description()
{
	return m_description;
}

int SystemEventData::eventId()
{
	return m_eventId;
}

SystemEventData::SysEventLevel SystemEventData::eventLevel()
{
	return m_eventLevel;
}

QString& SystemEventData::providerName()
{
	return m_providerName;
}

QDateTime& SystemEventData::creationTime()
{
	return m_createdTime;
}

bool SystemEventData::ascEventIdCompare(SystemEventData* item1, SystemEventData* item2)
{
	return item1->eventId() < item2->eventId();
}

bool SystemEventData::descEventIdCompare(SystemEventData* item1, SystemEventData* item2)
{
	return item1->eventId() > item2->eventId();
}

bool SystemEventData::ascProviderCompare(SystemEventData* item1, SystemEventData* item2)
{
	return item1->providerName() < item2->providerName();
}

bool SystemEventData::descProviderCompare(SystemEventData* item1, SystemEventData* item2)
{
	return item1->providerName() > item2->providerName();
}

bool SystemEventData::ascTimeCompare(SystemEventData* item1, SystemEventData* item2)
{
	return item1->creationTime() < item2->creationTime();
}

bool SystemEventData::descTimeCompare(SystemEventData* item1, SystemEventData* item2)
{
	return item1->creationTime() > item2->creationTime();
}

