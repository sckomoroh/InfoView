#ifndef MSINFOPARSERTHREAD_H
#define MSINFOPARSERTHREAD_H

#include <QThread>

#include "IMsInfoParserListener.h"
#include "MsInfoParser.h"

class MsInfoParserThread 
	: public QThread
	, public IMsInfoParserListener
{
	Q_OBJECT
private:
	QString m_fileName;
	MsInfoParser* m_pParser;

public:
	MsInfoParserThread(QObject *parent);
	~MsInfoParserThread();

	void setFileName(const QString& fileName);

	virtual void run();

	inline const MsInfoParser* parser()
	{
		return m_pParser;
	}

private:
	virtual void onParsingStart();
	virtual void onParsingComplete();

signals:
	void parsingStart();
	void parsingComplete();
};

#endif // MSINFOPARSERTHREAD_H
