#ifndef REGISTRYPARSERTHREAD_H
#define REGISTRYPARSERTHREAD_H

#include <QThread>

#include "RegParser.h"
#include "IRegParserListener.h"

class RegParserThread
	: public QThread
	, public IRegParserListener
{
	Q_OBJECT
private:
	QString m_folderPath;
	RegParser* m_pParser;

public:
	RegParserThread(QObject *parent);
	~RegParserThread();

	inline const RegParser* parser() const
	{
		return m_pParser;
	}

	void setFolder(const QString& folderPath);

	virtual void run();

private:
	virtual void onParsingStart();
	virtual void onParsingComplete();

signals:
	void parsingStarted();
	void parsingCompleted();
};

#endif // REGISTRYPARSERTHREAD_H
