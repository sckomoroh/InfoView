#include "MongoEventParserThread.h"

MongoEventParserThread::MongoEventParserThread(QObject *parent)
	: QThread(parent)
{
	m_pParser = new MongoEventParser;
	m_pParser->addListener(this);
}

MongoEventParserThread::~MongoEventParserThread()
{
	delete m_pParser;
}

void MongoEventParserThread::setFileName(const QString& fileName)
{
	m_fileName = fileName;
}

void MongoEventParserThread::run()
{
	m_pParser->parse(m_fileName);
}

MongoEventParser* MongoEventParserThread::parser()
{
	return m_pParser;
}

void MongoEventParserThread::onStartParsingBson()
{
	emit startParsing();
}

void MongoEventParserThread::onCompleteParsingBson()
{
	emit itemParsed(5, 100);
}

void MongoEventParserThread::onStartParsingEvents()
{
}

void MongoEventParserThread::onEventParsed(uint iCurrent, uint iTotal)
{
	emit itemParsed(5 + iCurrent, 5 + iTotal);
}

void MongoEventParserThread::onCompleteParsingEvents()
{
	emit completeParsing();
}
