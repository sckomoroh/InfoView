#include "RegParserThread.h"

RegParserThread::RegParserThread(QObject *parent)
	: QThread(parent)
{
	m_pParser = new RegParser;

	m_pParser->setListener(this);
}

RegParserThread::~RegParserThread()
{
	delete m_pParser;
}

void RegParserThread::setFolder(const QString& folderPath)
{
	m_folderPath = folderPath;
}

void RegParserThread::run()
{
	m_pParser->parseFolder(m_folderPath);
}

void RegParserThread::onParsingStart()
{
	emit parsingStarted();
}

void RegParserThread::onParsingComplete()
{
	emit parsingCompleted();
}
