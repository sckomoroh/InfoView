#ifndef EVENTFILEPARSERTHREAD_H
#define EVENTFILEPARSERTHREAD_H

#include <QThread>

#include "SystemEventParser.h"
#include "ISystemEventParserListener.h"

class SystemEventParserThread
	: public QThread
	, public ISystemEventParserListener
{
	Q_OBJECT
private:
	QString m_fileName;
	SystemEventParser* m_pParser;

public:
	SystemEventParserThread(QObject *parent);
	~SystemEventParserThread();

	virtual void run();

	void setFileName(const QString& fileName);

	SystemEventParser* parser();

private:
	virtual void onEventStartParsing();
	virtual void onEventParsed(uint iCurrent, uint iTotal);
	virtual void onEventCompleteParsing();

signals:
	void eventStartParsing();
	void eventParsed(uint iCurrent, uint iTotal);
	void eventCompleteParsing();
};

#endif // EVENTFILEPARSERTHREAD_H
