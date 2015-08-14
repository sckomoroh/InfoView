#include "amazon.h"

#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDomDocument>
#include <QDebug>

#include "AmazonAuthHelper.h"

Amazon::Amazon(QObject *parent)
    : QObject(parent)
    , m_pNetReply(NULL)
    , m_pDataStream(NULL)
{

}

Amazon::~Amazon()
{
}

bool Amazon::createFolder(QString folder)
{
    QDir fileFolder(folder);
    if (!fileFolder.exists())
    {
        qDebug() << "[AMAZON] The path '" << folder << "' does not exists. Try to create it.";

        QDir rootFolder(fileFolder.rootPath());
        bool bCreateResult = rootFolder.mkpath(folder);

        if (bCreateResult == false)
        {
            qDebug() << "[AMAZON] Unable to create folder for archive";

            return false;
        }
    }

    return true;
}

bool Amazon::createFile(QString fileName)
{
    qDebug() << "[AMAZON] File name: " << fileName;

    m_file.setFileName(fileName);
    if (!m_file.open(QIODevice::WriteOnly))
    {
        qDebug() << "[AMAZON] Unable to open file.";

        return false;
    }

    if (m_pDataStream != NULL)
    {
        delete m_pDataStream;
    }

    m_pDataStream = new QDataStream(&m_file);

    return true;
}

void Amazon::startDownload(QString resource, QString folder)
{
    emit downloadingStarted();

	qDebug() << "[AMAZON] Star download resource: " << resource;

	if (m_pNetReply != NULL)
	{
		if (!m_pNetReply->isFinished())
		{
			qDebug() << "[AMAZON] Aborting previous request";
			m_pNetReply->abort();
		}
	}

	int index = resource.lastIndexOf("/");
	if (index != -1)
	{
		resource = resource.mid(index + 1).trimmed();
	}

    if (createFolder(folder) == false)
    {
        emit downloadingCompleted();
        return;
    }

	QString fileName = QString("%1/%2").arg(folder).arg(resource);
    if (createFile(fileName) == false)
    {
        emit downloadingCompleted();
        return;
    }

	QString encodedResource = AmazonAuthHelper::toPercentEncoding(resource);

	AmazonAuthHelper awsEngine;
	QString authValue = awsEngine.getAuthHeader(encodedResource);
	std::string stdStr = authValue.toStdString();

	QString date = awsEngine.date();
	std::string stdDate = date.toStdString();

	QString amazonUrl = QString("http://aainfo5.s3.amazonaws.com/%1").arg(resource);
	QUrl url(amazonUrl);

	qDebug() << "[AMAZON] Download URL: " << amazonUrl;

	QNetworkRequest request(url);
	request.setRawHeader(
		QByteArray("Authorization"),
		QByteArray(stdStr.c_str()));

	request.setRawHeader(
		QByteArray("x-amz-date"),
		QByteArray(stdDate.c_str()));

	m_pNetReply = m_networkManager.get(request);

	connect(m_pNetReply, SIGNAL(readyRead()), SLOT(onDownloadReadyRead()));
	connect(m_pNetReply, SIGNAL(finished()), SLOT(onDownloadFinished()));
	connect(m_pNetReply, SIGNAL(downloadProgress(qint64, qint64)), SLOT(onDownloadProgress(qint64, qint64)));
}

void Amazon::startListObjects()
{
	emit startRetrievingList();

	QUrl url("http://aainfo5.s3.amazonaws.com/?delimiter=%2F");
	QNetworkRequest request(url);

	m_pNetReply = m_networkManager.get(request);

	m_getListContent.clear();

	connect(m_pNetReply, SIGNAL(readyRead()), SLOT(onGetListReadyRead()));
	connect(m_pNetReply, SIGNAL(finished()), SLOT(onGetListFinished()));
}

void Amazon::startGetNextObjects(QString nextMarker)
{
	QUrl url(QString("http://aainfo5.s3.amazonaws.com/?delimiter=%2F&marker=%1").arg(nextMarker));
	QNetworkRequest request(url);

	m_pNetReply = m_networkManager.get(request);

	m_getListContent.clear();

	connect(m_pNetReply, SIGNAL(readyRead()), SLOT(onGetListReadyRead()));
	connect(m_pNetReply, SIGNAL(finished()), SLOT(onGetListFinished()));
}

void Amazon::parseObjects()
{
	QDomDocument doc;
	doc.setContent(m_getListContent);

	QDomElement rootElement = doc.documentElement();
	QDomNodeList nodeList = rootElement.elementsByTagName("Contents");

	for (int i = 0; i < nodeList.count(); i++)
	{
		QDomElement element = nodeList.at(i).toElement();

		AmazonObject object;
		object.link = element.firstChildElement("Key").text();
		object.size = AmazonAuthHelper::toStrSize(element.firstChildElement("Size").text());

		m_objects.append(object);
	}

	QDomElement marker = rootElement.firstChildElement("NextMarker");
	QString nextMarker = marker.text();

	if (nextMarker.isNull() || nextMarker.isEmpty())
	{
		emit objectListRetrieved(m_objects);
	}
	else
	{
		startGetNextObjects(nextMarker);
	}
}

void Amazon::onGetListReadyRead()
{
	QNetworkReply* pReply = (QNetworkReply*)sender();
	m_getListContent += pReply->readAll();
}

void Amazon::onGetListFinished()
{
	parseObjects();
}

void Amazon::onDownloadProgress(qint64 iCurrent, qint64 iTotal)
{
	emit downloadingProgress(iCurrent, iTotal);
}

void Amazon::onDownloadFinished()
{
	m_file.close();

	emit downloadingCompleted();
}

void Amazon::onDownloadReadyRead()
{
	QNetworkReply* pReply = (QNetworkReply*)sender();
	QByteArray data = pReply->readAll();
	QString response = data;
	char* pRawData = data.data();

	m_pDataStream->writeRawData(pRawData, data.length());
}
