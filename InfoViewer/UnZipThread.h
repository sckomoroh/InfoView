#ifndef UNZUPTHREAD_H
#define UNZUPTHREAD_H

#include <QThread>

#include "IZip.h"
#include "ILogClient.h"

class UnZipThread : public QThread
{
	Q_OBJECT
private:
	IZip* m_pZipInstance;
	QString m_zipFileName;
	QString m_targetFolder;

	ILogClient* m_logClient;

public:
	UnZipThread(QObject *parent);
	~UnZipThread();

	inline void setZipFileName(QString zipFileName)
	{
		m_zipFileName = zipFileName;
	}

	inline void setTargetFolder(QString targetFolder)
	{
		m_targetFolder = targetFolder;
	}

private:
	virtual void run();

signals:
	void unzipStarted();
	void unzipProgress(uint iCurrenty, uint iTotal);
	void unzipComplete();
};

#endif // UNZUPTHREAD_H
