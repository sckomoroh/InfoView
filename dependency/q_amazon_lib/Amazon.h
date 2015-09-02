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

typedef struct
{
	QString link;
	QString size;
} AmazonObject;

class Amazon : public QObject
{
	Q_OBJECT
private:
    QNetworkAccessManager   m_networkManager;
    QString                 m_getListContent;
    QList<AmazonObject>     m_objects;
    QFile                   m_file;
    QDataStream*            m_pDataStream;
    QNetworkReply*          m_pNetReply;

public:
	Amazon(QObject *parent);
	~Amazon();

	void startDownload(QString resource, QString folder);
	void startListObjects();

    inline QString fileName()
    {
        return m_file.fileName();
    }

    inline QString baseFileName()
    {
        return QFileInfo(m_file).completeBaseName();
    }

	inline QString fileFolder()
	{
        return QFileInfo(m_file).absoluteDir().path();
	}

private:
	void parseObjects();
	void startGetNextObjects(QString nextMarker);
    bool createFolder(QString folder);
    bool createFile(QString fileName);

signals:
	void startRetrievingList();
	void objectListRetrieved(const QList<AmazonObject>& objects);

	void downloadingStarted();
	void downloadingProgress(qint64 iCurrent, qint64 iTotal);
	void downloadingCompleted();

private slots:
	void onGetListReadyRead();
	void onGetListFinished();

	void onDownloadProgress(qint64 iCurrent, qint64 iTotal);
	void onDownloadReadyRead();
	void onDownloadFinished();
};

#endif // AMAZON_H
