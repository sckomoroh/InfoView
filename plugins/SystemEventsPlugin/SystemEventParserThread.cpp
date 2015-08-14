#include "SystemEventParserThread.h"

SystemEventParserThread::SystemEventParserThread(QObject *parent)
	: QThread(parent)
{
	m_pParser = new SystemEventParser;
	m_pParser->addListener(this);
}

SystemEventParserThread::~SystemEventParserThread()
{
	delete m_pParser;
}

void SystemEventParserThread::run()
{
	m_pParser->parseFile(m_fileName);
}

void SystemEventParserThread::setFileName(const QString& fileName)
{
	m_fileName = fileName;
}

SystemEventParser* SystemEventParserThread::parser()
{
	return m_pParser;
}

void SystemEventParserThread::onEventStartParsing()
{
	emit eventStartParsing();
}

void SystemEventParserThread::onEventParsed(uint iCurrent, uint iTotal)
{
	emit eventParsed(iCurrent, iTotal);
}

void SystemEventParserThread::onEventCompleteParsing()
{
	emit eventCompleteParsing();
}
