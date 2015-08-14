#include "MognoJobParserThread.h"

#include <QDebug>

//#include "LogManager.h"

MognoJobParserThread::MognoJobParserThread(QObject *parent)
	: QThread(parent)
{
	m_pParser = new MongoJobParser;
	m_pParser->addListener(this);
}

MognoJobParserThread::~MognoJobParserThread()
{
	delete m_pParser;
}

void MognoJobParserThread::setFileName(const QString& fileName)
{
	m_fileName = fileName;
}

void MognoJobParserThread::run()
{
	//CLogger::Info("Start parsing Mongo DB jobs");

	m_pParser->parse(m_fileName);

	//CLogger::Info("Complete parsing Mongo DB jobs");
}

MongoJobParser* MognoJobParserThread::parser()
{
	return m_pParser;
}

void MognoJobParserThread::onStartBsonParsing()
{
	qDebug() << "[DEBUG] Emit start BSON parsing";

	emit startParsing();
}

void MognoJobParserThread::onCompleteBsonParsing()
{
	qDebug() << "[DEBUG] Emit complete BSON parsing";

	emit itemParsed(5, 100);
}

void MognoJobParserThread::onStartJobParsing()
{
}

void MognoJobParserThread::onJobParsed(uint iCurrent, uint iTotal)
{
	emit itemParsed(iCurrent + 5, iTotal + 5);
}

void MognoJobParserThread::onCompleteJobParsing()
{
	qDebug() << "[DEBUG] Totally complete parsing";

	emit completeParsing();
}
