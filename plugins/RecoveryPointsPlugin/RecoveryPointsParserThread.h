#ifndef PARSETHREAD_H
#define PARSETHREAD_H

#include <QThread>

#include "IRecoveryPointsParserListener.h"
#include "RecoveryPointsParser.h"

class RecoveryPointsParserThread
	: public QThread
	, public IRecoveryPointsParserListener
{
	Q_OBJECT
private:
	QString m_folder;
	RecoveryPointsParser* m_pParser;

public:
	RecoveryPointsParserThread(QObject *parent);
	~RecoveryPointsParserThread();

	void setFolder(const QString& folder);

	RecoveryPointsParser* parser();

	virtual void run();

public:
	virtual void onStartParsing();
	virtual void onCompleteParsing();
	virtual void onAgentParsed(unsigned int current, unsigned int total);
	virtual void onRecoveryPointParsed(unsigned int current, unsigned int total);

signals:
	void parsingStarted();
	void parsingCompleted();
	
	void agentParsed(uint current, uint total);
	
	void recoveryPointParsed(uint current, uint total);
};

#endif // PARSETHREAD_H
