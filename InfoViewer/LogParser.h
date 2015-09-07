#pragma once

#include <QString>
#include <QList>

#include "LogStorage.h"
#include "LogLineData.h"
#include "ILogParserListener.h"
#include "ILogClient.h"

class LogParser
{
private:
	LogStorage* m_pStorage;
	ILogParserListener* m_pListener;
	ILogClient* m_logClient;

public:
	LogParser();
	~LogParser();

	void parseFile(const QString& fileName);

	inline LogStorage* storage()
	{
		return m_pStorage;
	}

	void setListener(ILogParserListener* pListener);

private:
	void fireStartParse();
	void fireCompleteParse();
};
