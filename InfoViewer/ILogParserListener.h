#pragma once

class ILogParserListener
{
public:
	virtual void onStartParse() = 0;
	virtual void onCompleteParse() = 0;
};