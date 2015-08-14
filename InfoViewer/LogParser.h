#pragma once

#include <QString>
#include <QList>

#include "LogStorage.h"
#include "LogLineData.h"
#include "ILogParserListener.h"

#define ERROR_PREFIX    "ERRO"
#define INFO_PREFIX     "INFO"
#define WARN_PREFIX     "WARN"
#define DEBUG_PREFIX    "DEBU"
#define TRACE_PREFIX    "TRAC"
#define FATAL_PREFIX    "FATA"

class LogParser
{
private:
	LogStorage* m_pStorage;
	ILogParserListener* m_pListener;

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
