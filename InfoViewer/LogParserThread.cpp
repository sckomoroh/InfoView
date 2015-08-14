#include "logparserthread.h"

LogParserThread::LogParserThread(QObject *parent)
	: QThread(parent)
{
	m_pParser = new LogParser;
	m_pParser->setListener(this);
}

LogParserThread::~LogParserThread()
{
	delete m_pParser;
}

void LogParserThread::run()
{
	m_pParser->parseFile(m_fileName);
}

void LogParserThread::onStartParse()
{
	emit startParse();
}

void LogParserThread::onCompleteParse()
{
	emit completeParse();
}
