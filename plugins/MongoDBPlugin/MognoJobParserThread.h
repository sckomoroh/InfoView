#ifndef MognoJobParserThread_H
#define MognoJobParserThread_H

#include <QThread>
#include <QList>

#include "MongoJobParser.h"

class MognoJobParserThread 
	: public QThread
	, public IJobsParserListener
{
	Q_OBJECT
private:
	MongoJobParser* m_pParser;
	QString m_fileName;

public:
	MognoJobParserThread(QObject *parent);
	~MognoJobParserThread();

	void setFileName(const QString& fileName);

	virtual void run();

	MongoJobParser* parser();

private:
	virtual void onStartBsonParsing();
	virtual void onCompleteBsonParsing();
	virtual void onStartJobParsing();
	virtual void onJobParsed(uint iCurrent, uint iTotal);
	virtual void onCompleteJobParsing();

signals:
	void startParsing();
	void itemParsed(uint iCurrent, uint iTotal);
	void completeParsing();
};

#endif // MognoJobParserThread_H
