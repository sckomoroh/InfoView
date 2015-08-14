#ifndef LOGPARSERTHREAD_H
#define LOGPARSERTHREAD_H

#include <QThread>

#include "LogParser.h"

class LogParserThread 
	: public QThread
	, public ILogParserListener
{
	Q_OBJECT
private:
	QString		m_fileName;
	LogParser*	m_pParser;

public:
	LogParserThread(QObject *parent = 0);
	~LogParserThread();

	inline void setFileName(const QString& fileName)
	{
		m_fileName = fileName;
	}

	inline LogParser* parser()
	{
		return m_pParser;
	}

protected:
	virtual void run();

private:
	virtual void onStartParse();
	virtual void onCompleteParse();

signals:
	void startParse();
	void completeParse();
};

#endif // LOGPARSERTHREAD_H
