#pragma once

#include <QObject>

class ISystemEventParserListener
{
public:
	virtual void onEventStartParsing() = 0;
	virtual void onEventParsed(uint iCurrent, uint iTotal) = 0;
	virtual void onEventCompleteParsing() = 0;
};