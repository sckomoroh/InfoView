#include "amazon.h"

#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDomDocument>
#include <QCoreApplication>
#include <QDebug>

#include "AmazonAuthHelper.h"

IAmazon* g_dll_instance = NULL;

IAmazon* getAmazonInstance()
{
	if (g_dll_instance == NULL)
	{
		g_dll_instance = new Amazon(NULL);
	}

	return g_dll_instance;
}

Amazon::Amazon(QObject *parent)
    : QObject(parent)
    , m_pNetReply(NULL)
    , m_pDataStream(NULL)
{
}

Amazon::~Amazon()
{
}

void Amazon::refreshConfig()
{
	readConfiguration();
}

QString Amazon::fileName()
{
	return m_file.fileName();
}

QString Amazon::baseFileName()
{
	return QFileInfo(m_file).completeBaseName();
}

QString Amazon::fileFolder()
{
	return QFileInfo(m_file).absoluteDir().path();
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
    fireDownloadingStarted();

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
        fireDownloadingCompleted();
        return;
    }

	QString fileName = QString("%1/%2").arg(folder).arg(resource);
    if (createFile(fileName) == false)
    {
        fireDownloadingCompleted();
        return;
    }

	QString encodedResource = AmazonAuthHelper::toPercentEncoding(resource);

	AmazonAuthHelper awsEngine(m_accessKey, m_secret, m_bucketName, m_amzAddress);
	QString authValue = awsEngine.getAuthHeader(encodedResource);
	std::string stdStr = authValue.toStdString();

	QString date = awsEngine.date();
	std::string stdDate = date.toStdString();

	QString amazonUrl = QString(m_downloadBucketUrl).arg(resource);
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
	connect(m_pNetReply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(onNetworkError(QNetworkReply::NetworkError)));
	connect(m_pNetReply, SIGNAL(sslErrors(const QList<QSslError>&)), SLOT(onSllError(const QList<QSslError>&)));
}

void Amazon::startListObjects()
{
	fireStartRetrievingList();

	QUrl url(m_firstMarkerUrl);
	QNetworkRequest request(url);

	m_pNetReply = m_networkManager.get(request);

	m_getListContent.clear();

	connect(m_pNetReply, SIGNAL(readyRead()), SLOT(onGetListReadyRead()));
	connect(m_pNetReply, SIGNAL(finished()), SLOT(onGetListFinished()));
}

void Amazon::startGetNextObjects(QString nextMarker)
{
	QUrl url(QString(m_nextMarkerUrl).arg(nextMarker));
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
		fireObjectListRetrieved(m_objects);
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
	fireDownloadingProgress(iCurrent, iTotal);
}

void Amazon::onDownloadFinished()
{
	m_file.close();

	fireDownloadingCompleted();
}

void Amazon::onDownloadReadyRead()
{
	QNetworkReply* pReply = (QNetworkReply*)sender();
	QByteArray data = pReply->readAll();
	QString response = data;
	char* pRawData = data.data();

	m_pDataStream->writeRawData(pRawData, data.length());
}

void Amazon::addListener(IAmazonListener* listener)
{
	m_listeners.append(listener);
}

void Amazon::fireStartRetrievingList()
{
	QList<IAmazonListener*>::iterator iter = m_listeners.begin();
	for (; iter != m_listeners.end(); ++iter)
	{
		IAmazonListener* listener = *iter;
		listener->onStartRetrievingList();
	}
}

void Amazon::fireObjectListRetrieved(const QList<AmazonObject>& objects)
{
	QList<IAmazonListener*>::iterator iter = m_listeners.begin();
	for (; iter != m_listeners.end(); ++iter)
	{
		IAmazonListener* listener = *iter;
		listener->onObjectListRetrieved(objects);
	}
}

void Amazon::fireDownloadingStarted()
{
	QList<IAmazonListener*>::iterator iter = m_listeners.begin();
	for (; iter != m_listeners.end(); ++iter)
	{
		IAmazonListener* listener = *iter;
		listener->onDownloadingStarted();
	}
}

void Amazon::fireDownloadingProgress(qint64 iCurrent, qint64 iTotal)
{
	QList<IAmazonListener*>::iterator iter = m_listeners.begin();
	for (; iter != m_listeners.end(); ++iter)
	{
		IAmazonListener* listener = *iter;
		listener->onDownloadingProgress(iCurrent, iTotal);
	}
}

void Amazon::fireDownloadingCompleted()
{
	QList<IAmazonListener*>::iterator iter = m_listeners.begin();
	for (; iter != m_listeners.end(); ++iter)
	{
		IAmazonListener* listener = *iter;
		listener->onDownloadingCompleted();
	}
}

void Amazon::readConfiguration()
{
	QString binConfigFileName = QCoreApplication::applicationDirPath() + "/amazon.bin";
	QFile configFile(binConfigFileName);

	if (!configFile.open(QIODevice::ReadOnly))
	{
		qDebug() << "Unable to open cfg file";
		return;
	}

	QByteArray base64Content = configFile.readAll();
	QByteArray encryptedContent = QByteArray::fromBase64(base64Content);
	for (int i = 0; i < encryptedContent.size(); i++)
	{
		encryptedContent[i] = encryptedContent[i] ^ 123;
	}

	QDomDocument cfgDoc;
	if (!cfgDoc.setContent(encryptedContent))
	{
		qDebug() << "Unable to parse decrypted XML";
		return;
	}

	QDomElement rootElement = cfgDoc.documentElement();
	QDomElement firstMarkerUrlElement = rootElement.firstChildElement("firstMarkerUrl");
	QDomElement nextMarkerUrlElement = rootElement.firstChildElement("nextMarkerUrl");
	QDomElement downloadBucketUrlElement = rootElement.firstChildElement("downloadBucketUrl");
	QDomElement accessKeyElement = rootElement.firstChildElement("amazonAccessKeyId");
	QDomElement secretElement = rootElement.firstChildElement("amazonSecret");
	QDomElement bucketNameElement = rootElement.firstChildElement("bucketName");
	QDomElement amzAddrElement = rootElement.firstChildElement("amazonAddress");


	if (firstMarkerUrlElement.isNull() || nextMarkerUrlElement.isNull() || downloadBucketUrlElement.isNull() || accessKeyElement.isNull() || secretElement.isNull() || bucketNameElement.isNull() || amzAddrElement.isNull())
	{
		return;
	}

	m_accessKey = accessKeyElement.attribute("value");
	m_secret = secretElement.attribute("value");
	m_bucketName = bucketNameElement.attribute("value");
	m_amzAddress = amzAddrElement.attribute("value");

	QDomCDATASection firstMarkerUrlcData = firstMarkerUrlElement.firstChild().toCDATASection();
	if (firstMarkerUrlcData.isNull())
	{
		return;
	}
	m_firstMarkerUrl = firstMarkerUrlcData.nodeValue();

	QDomCDATASection nextMarkerUrlcData = nextMarkerUrlElement.firstChild().toCDATASection();
	if (nextMarkerUrlcData.isNull())
	{
		return;
	}
	m_nextMarkerUrl = nextMarkerUrlcData.nodeValue();

	QDomCDATASection downloadBucketUrlcData = downloadBucketUrlElement.firstChild().toCDATASection();
	if (downloadBucketUrlcData.isNull())
	{
		return;
	}
	m_downloadBucketUrl = downloadBucketUrlcData.nodeValue();
}

void Amazon::onNetworkError(QNetworkReply::NetworkError networkError)
{
	int a = 0;
}

void Amazon::onSllError(const QList<QSslError>& errors)
{
	int a = 0;
}
