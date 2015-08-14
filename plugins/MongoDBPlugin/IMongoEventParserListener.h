#pragma once

#include <QObject>

class IMongoEventParserListener
{
public:
	virtual void onStartParsingBson() = 0;
	virtual void onCompleteParsingBson() = 0;
	virtual void onStartParsingEvents() = 0;
	virtual void onEventParsed(uint iCurrent, uint iTotal) = 0;
	virtual void onCompleteParsingEvents() = 0;
};