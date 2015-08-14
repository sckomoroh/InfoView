#include "MsInfoParserThread.h"

MsInfoParserThread::MsInfoParserThread(QObject *parent)
	: QThread(parent)
{
	m_pParser = new MsInfoParser;
	m_pParser->setListener(this);
}

MsInfoParserThread::~MsInfoParserThread()
{
	delete m_pParser;
}

void MsInfoParserThread::setFileName(const QString& fileName)
{
	m_fileName = fileName;
}

void MsInfoParserThread::run()
{
	m_pParser->parseFile(m_fileName);
}

void MsInfoParserThread::onParsingStart()
{
	emit parsingStart();
}

void MsInfoParserThread::onParsingComplete()
{
	emit parsingComplete();
}
