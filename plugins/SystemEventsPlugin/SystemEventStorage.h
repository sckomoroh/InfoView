#pragma once

#include <QList>

#include "SystemEventData.h"
#include "IStorageListener.h"
#include "ISystemEventParserListener.h"

class SystemEventStorage
	: public ISystemEventParserListener
{
public:
	enum SystemEventLevels
	{
		Critical	= 0x1,
		Error		= 0x2,
		Information	= 0x4,
		Verbose		= 0x8,
		Warning		= 0x10,
		LogAlways	= 0x20
	};

private:
	IStorageListener* m_listener;
	QList<SystemEventData*> m_records;
	QList<SystemEventData*> m_filteredRecords;

public:
	SystemEventStorage();
	~SystemEventStorage();

public:
	virtual void onEventStartParsing();
	virtual void onEventParsed(uint iCurrent, uint iTotal);
	virtual void onEventCompleteParsing();

	void setListener(IStorageListener* listener);

	void addRecord(SystemEventData* pRecord);
	void clear();
	SystemEventData* origianlRecordAt(uint iIndex);
	uint origianlRecordsCount();

	SystemEventData* filteredRecordAt(uint iIndex);
	uint filteredRecordsCount();

	QStringList providersNames();

	void filterRecords(QList<int> eventIds, QList<QString> providers, int eventLevels);
	void sortByEventId(bool ascending);
	void sortByProvider(bool ascending);
	void sortByTime(bool ascending);

private:
	void filterByEventId(QList<int>& eventIds);
	void filterByProvider(QList<QString>& providers);
	void filterByLevels(int levels);

private:
	void fireBeginChange();
	void fireEndChange();
};

