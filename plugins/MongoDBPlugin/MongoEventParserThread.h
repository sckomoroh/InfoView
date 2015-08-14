#ifndef EVENTSPARSERTHREAD_H
#define EVENTSPARSERTHREAD_H

#include <QThread>
#include <QString>

#include "MongoEventParser.h"
#include "IMongoEventParserListener.h"

class MongoEventParserThread
	: public QThread
	, public IMongoEventParserListener
{
	Q_OBJECT
private:
	MongoEventParser* m_pParser;
	QString m_fileName;

public:
	MongoEventParserThread(QObject *parent);
	~MongoEventParserThread();

	void setFileName(const QString& fileName);

	virtual void run();

	MongoEventParser* parser();

private:
	virtual void onStartParsingBson();
	virtual void onCompleteParsingBson();
	virtual void onStartParsingEvents();
	virtual void onEventParsed(uint iCurrent, uint iTotal);
	virtual void onCompleteParsingEvents();

signals:
	void startParsing();
	void itemParsed(uint iCurrent, uint iTotal);
	void completeParsing();
};

#endif // EVENTSPARSERTHREAD_H
