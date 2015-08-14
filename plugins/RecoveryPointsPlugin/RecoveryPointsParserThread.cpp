#include "RecoveryPointsParserThread.h"

RecoveryPointsParserThread::RecoveryPointsParserThread(QObject *parent)
	: QThread(parent)
{
	m_pParser = new RecoveryPointsParser;
	m_pParser->setListener(this);
}

RecoveryPointsParserThread::~RecoveryPointsParserThread()
{
}

void RecoveryPointsParserThread::run()
{
	m_pParser->parse(m_folder);
}

RecoveryPointsParser* RecoveryPointsParserThread::parser()
{
	return m_pParser;
}

void RecoveryPointsParserThread::setFolder(const QString& folder)
{
	m_folder = folder;
}

void RecoveryPointsParserThread::onStartParsing()
{
	emit parsingStarted();
}

void RecoveryPointsParserThread::onCompleteParsing()
{
	emit parsingCompleted();
}

void RecoveryPointsParserThread::onAgentParsed(unsigned int current, unsigned int total)
{
	emit agentParsed(current, total);
}

void RecoveryPointsParserThread::onRecoveryPointParsed(unsigned int current, unsigned int total)
{
	emit recoveryPointParsed(current, total);
}
