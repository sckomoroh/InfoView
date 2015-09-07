#include "LogParser.h"

#include <QFile>
#include <QTextStream>

#define ERROR_PREFIX    "ERRO"
#define INFO_PREFIX     "INFO"
#define WARN_PREFIX     "WARN"
#define DEBUG_PREFIX    "DEBU"
#define TRACE_PREFIX    "TRAC"
#define FATAL_PREFIX    "FATA"


LogParser::LogParser()
	: m_pListener(NULL)
{
	m_logClient = getLogClientInstance();
	m_pStorage = new LogStorage;
}

LogParser::~LogParser()
{
	delete m_pStorage;
}

void LogParser::parseFile(const QString& fileName)
{
	fireStartParse();

	m_logClient->Info("Start parse file '%s'", fileName.toStdString().c_str());

	QList<LogLineData*> result;

	QFile file(fileName);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text) == false)
	{
		m_logClient->Error("Unable to open file '%s' with error '%s'", fileName.toStdString().c_str(), file.errorString().toStdString().c_str());
		return;
	}

	QTextStream textStream(&file);

	LogLineData::LogType logType = LogLineData::LogTypeUnknown;

	while (!textStream.atEnd())
	{
		QString line = textStream.readLine();

		bool isHeader = false;

		if (line.startsWith(DEBUG_PREFIX))
		{
			logType = LogLineData::LogTypeDebug;
			isHeader = true;
		}
		else if (line.startsWith(INFO_PREFIX))
		{
			logType = LogLineData::LogTypeInformation;
			isHeader = true;
		}
		else if (line.startsWith(WARN_PREFIX))
		{
			logType = LogLineData::LogTypeWarning;
			isHeader = true;
		}
		else if (line.startsWith(ERROR_PREFIX))
		{
			logType = LogLineData::LogTypeError;
			isHeader = true;
		}

		LogLineData* pLogLine = new LogLineData(line, isHeader, logType);
		m_pStorage->addLogLine(pLogLine);
	}

	m_logClient->Info("Parsing file '%s' completed", fileName.toStdString().c_str());

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
