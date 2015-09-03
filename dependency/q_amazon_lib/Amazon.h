#ifndef AMAZON_H
#define AMAZON_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QList>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDataStream>
#include <QNetworkReply>
#include "IAmazon.h"

class Amazon 
	: public QObject
	, public IAmazon
{
	Q_OBJECT
private:
    QNetworkAccessManager   m_networkManager;
    QString                 m_getListContent;
    QList<AmazonObject>     m_objects;
    QFile                   m_file;
    QDataStream*            m_pDataStream;
    QNetworkReply*          m_pNetReply;
	QList<IAmazonListener*>	m_listeners;

	QString m_firstMarkerUrl;
	QString m_nextMarkerUrl;
	QString m_downloadBucketUrl;
	QString m_accessKey;
	QString m_secret;
	QString m_bucketName;
	QString m_amzAddress;

public:
	Amazon(QObject *parent);
	~Amazon();

	virtual void startDownload(QString resource, QString folder);
	virtual void startListObjects();

	virtual QString fileName();
	virtual QString baseFileName();
	virtual QString fileFolder();
	virtual void addListener(IAmazonListener* listener);
	virtual void refreshConfig();

private:
	void parseObjects();
	void startGetNextObjects(QString nextMarker);
    bool createFolder(QString folder);
    bool createFile(QString fileName);

	void readConfiguration();

private:
	void fireStartRetrievingList();
	void fireObjectListRetrieved(const QList<AmazonObject>& objects);
	void fireDownloadingStarted();
	void fireDownloadingProgress(qint64 iCurrent, qint64 iTotal);
	void fireDownloadingCompleted();

private slots:
	void onGetListReadyRead();
	void onGetListFinished();

	void onDownloadProgress(qint64 iCurrent, qint64 iTotal);
	void onDownloadReadyRead();
	void onDownloadFinished();

	void onNetworkError(QNetworkReply::NetworkError networkError);
	void onSllError(const QList<QSslError>& errors);
};

#endif // AMAZON_H
