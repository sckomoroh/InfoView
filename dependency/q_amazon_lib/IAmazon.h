#pragma once

#include <QObject>
#include <QString>
#include <QList>

#ifdef Q_AMAZON_LIB_LIB
#define AMAZON_DLL_EXPORT __declspec(dllexport)
#else
#define AMAZON_DLL_EXPORT __declspec(dllimport)
#endif

typedef struct AMAZON_DLL_EXPORT
{
	QString link;
	QString size;
} AmazonObject;

class AMAZON_DLL_EXPORT IAmazonListener
{
public:
	virtual void onStartRetrievingList() = 0;
	virtual void onObjectListRetrieved(const QList<AmazonObject>& objects) = 0;
	virtual void onDownloadingStarted() = 0;
	virtual void onDownloadingProgress(qint64 iCurrent, qint64 iTotal) = 0;
	virtual void onDownloadingCompleted() = 0;
};

class AMAZON_DLL_EXPORT IAmazon
{
public:
	virtual void startDownload(QString resource, QString folder) = 0;
	virtual void startListObjects() = 0;
	virtual QString fileName() = 0;
	virtual QString baseFileName() = 0;
	virtual QString fileFolder() = 0;
	virtual void addListener(IAmazonListener* listener) = 0;
	virtual void refreshConfig() = 0;
};

AMAZON_DLL_EXPORT IAmazon* getAmazonInstance();
