#include "MongoEventData.h"


MongoEventData::MongoEventData()
{
}


MongoEventData::~MongoEventData()
{
}

void MongoEventData::setLevel(EventLevel level)
{
	m_level = level;
}

MongoEventData* MongoEventData::createFromBson(BsonDocument* pDocument)
{
	MongoEventData* pObject = new MongoEventData;

	Int64 millsec = pDocument->elementByName("UtcTimestamp")->asInt64();

	pObject->m_message = pDocument->elementByName("Message")->asUtfString();
	pObject->m_message = pObject->m_message.remove("\r\n");

	pObject->m_time = QDateTime::fromMSecsSinceEpoch(millsec);
	pObject->m_bIsAlert = pDocument->elementByName("IsAlert")->asBool();

	return pObject;
}

bool MongoEventData::acsByMessage(MongoEventData* item1, MongoEventData* item2)
{
	return item1->message() < item2->message();
}

bool MongoEventData::decsByMessage(MongoEventData* item1, MongoEventData* item2)
{
	return item1->message() > item2->message();
}

bool MongoEventData::acsByTime(MongoEventData* item1, MongoEventData* item2)
{
	return item1->time() < item2->time();
}

bool MongoEventData::decsByTime(MongoEventData* item1, MongoEventData* item2)
{
	return item1->time() > item2->time();
}


