#pragma once

#include <QObject>
#include <QString>
#include <QDateTime>

class SystemEventParser;

class SystemEventData
{
public:
	enum SysEventLevel
	{
		SysEventCritical	= 0x01,
		SysEventError		= 0x02,
		SysEventInfo		= 0x04,
		SysEventVerbose		= 0x08,
		SysEventWarning		= 0x10,
		SysEventLogAlways	= 0x20
	};


private:
	QString			m_description;
	int				m_eventId;
	SysEventLevel	m_eventLevel;
	QString			m_providerName;
	QDateTime		m_createdTime;

public:
	SystemEventData();
	~SystemEventData();

	QString&		description();
	int				eventId();
	SysEventLevel	eventLevel();
	QString&		providerName();
	QDateTime&		creationTime();


	static bool ascEventIdCompare(SystemEventData* item1, SystemEventData* item2);
	static bool descEventIdCompare(SystemEventData* item1, SystemEventData* item2);

	static bool ascProviderCompare(SystemEventData* item1, SystemEventData* item2);
	static bool descProviderCompare(SystemEventData* item1, SystemEventData* item2);

	static bool ascTimeCompare(SystemEventData* item1, SystemEventData* item2);
	static bool descTimeCompare(SystemEventData* item1, SystemEventData* item2);

private:
	friend class SystemEventParser;
};

