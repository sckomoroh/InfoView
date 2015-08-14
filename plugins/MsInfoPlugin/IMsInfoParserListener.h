#pragma once

class IMsInfoParserListener
{
public:
	virtual void onParsingStart() = 0;
	virtual void onParsingComplete() = 0;
};