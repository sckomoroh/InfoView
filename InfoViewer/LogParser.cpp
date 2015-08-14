#include "LogParser.h"

#include <QFile>
#include <QTextStream>

LogParser::LogParser()
	: m_pListener(NULL)
{
	m_pStorage = new LogStorage;
}

LogParser::~LogParser()
{
	delete m_pStorage;
}

void LogParser::parseFile(const QString& fileName)
{
	fireStartParse();

	QList<LogLineData*> result;

	QFile file(fileName);
	file.open(QIODevice::ReadOnly | QIODevice::Text);

	QTextStream textStream(&file);

	LogType logType = LogType::LogTypeUnknown;

	while (!textStream.atEnd())
	{
		QString line = textStream.readLine();

		bool isHeader = false;

		if (line.startsWith(DEBUG_PREFIX))
		{
			logType = LogType::LogTypeDebug;
			isHeader = true;
		}
		else if (line.startsWith(INFO_PREFIX))
		{
			logType = LogType::LogTypeInformation;
			isHeader = true;
		}
		else if (line.startsWith(WARN_PREFIX))
		{
			logType = LogType::LogTypeWarning;
			isHeader = true;
		}
		else if (line.startsWith(ERROR_PREFIX))
		{
			logType = LogType::LogTypeError;
			isHeader = true;
		}

		LogLineData* pLogLine = new LogLineData(line, isHeader, logType);
		m_pStorage->addLogLine(pLogLine);
	}

	fireCompleteParse();
}

void LogParser::setListener(ILogParserListener* pListener)
{
	m_pListener = pListener;
}

void LogParser::fireStartParse()
{
	if (m_pListener != NULL)
	{
		m_pListener->onStartParse();
	}
}

void LogParser::fireCompleteParse()
{
	if (m_pListener != NULL)
	{
		m_pListener->onCompleteParse();
	}
}
