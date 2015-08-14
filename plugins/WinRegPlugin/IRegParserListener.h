#pragma once

class IRegParserListener
{
public:
	virtual void onParsingStart() = 0;
	virtual void onParsingComplete() = 0;
};