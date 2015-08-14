#pragma once

class IRecoveryPointsParserListener
{
public:
	virtual void onStartParsing() = 0;
	virtual void onCompleteParsing() = 0;
	virtual void onAgentParsed(unsigned int current, unsigned int total) = 0;
	virtual void onRecoveryPointParsed(unsigned int current, unsigned int total) = 0;
};
	