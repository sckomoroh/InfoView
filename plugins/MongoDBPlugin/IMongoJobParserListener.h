#pragma once

#include <QObject>

class IJobsParserListener
{
public:
	virtual void onStartBsonParsing() = 0;
	virtual void onCompleteBsonParsing() = 0;
	virtual void onStartJobParsing() = 0;
	virtual void onJobParsed(uint iCurrent, uint iTotal) = 0;
	virtual void onCompleteJobParsing() = 0;
};

