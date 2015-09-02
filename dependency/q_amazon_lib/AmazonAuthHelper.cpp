#include "AmazonAuthHelper.h"


#include <QDateTime>
#include <QUrl>
#include <QNetworkRequest>
#include <QDebug>

#include "amazon_utils_c.h"

QString sizes[] =
{
	"bytes",
	"KB",
	"MB",
	"GB",
	"TB"
};

const QString AmazonAuthHelper::m_AWSAccessKeyId = "";
const QString AmazonAuthHelper::m_AWSSecretAccessKey = "";
const QString AmazonAuthHelper::m_bucketName = "";
const QString AmazonAuthHelper::m_amazonAddress = "";

AmazonAuthHelper::AmazonAuthHelper()
{
}

AmazonAuthHelper::~AmazonAuthHelper()
{
}

QString AmazonAuthHelper::getAuthHeader(QString resource)
{
	QString strUlr = QString("http://%1/%2").arg(AmazonAuthHelper::m_amazonAddress).arg(resource);
	QString signature = getSignature(resource);
	QString authHeader = getAuthenticationString(signature);

	return authHeader;
}

QString AmazonAuthHelper::toPercentEncoding(QString str)
{
	QString result = str.replace(" ", "%20");

	return result;
}

QString AmazonAuthHelper::getAuthenticationString(QString signature)
{
	QString result =
		QString("AWS %1:%2")
		.arg(AmazonAuthHelper::m_AWSAccessKeyId)
		.arg(signature);

	return result;
}

QString AmazonAuthHelper::getSignature(QString resource)
{
	QString stringToSign = getStringToSign(resource);
	std::string stdStrToSign = stringToSign.toStdString();
	const char* sStrToSign = stdStrToSign.c_str();

	std::string accessKey = m_AWSSecretAccessKey.toStdString();
	const char* sAccessKey = accessKey.c_str();

	unsigned char sHmacBuffer[22] = { 0 };
	amazon_HMAC_SHA1(
		sHmacBuffer,
		(unsigned char*)sAccessKey,
		strlen(sAccessKey),
		(unsigned char*)sStrToSign,
		strlen(sStrToSign));

	char sBase64AuthString[256] = { 0 };
	amazon_base64Encode(
		sHmacBuffer,
		strlen((char*)sHmacBuffer),
		sBase64AuthString);

	return QString(sBase64AuthString);
}

QString AmazonAuthHelper::getStringToSign(QString resource)
{
	QDateTime nowDateTime = QDateTime::currentDateTime().toUTC();
	m_date = nowDateTime.toString("ddd, dd MMM yyyy hh:mm:ss +0000");

	QString stringToSign =
		QString("GET\n\n\n\nx-amz-date:%1\n/%2/%3")
		.arg(m_date)
		.arg(AmazonAuthHelper::m_bucketName)
		.arg(resource);

	//qDebug() << "String to sign:\n" << stringToSign;

	return stringToSign;
}

QString AmazonAuthHelper::date()
{
	return m_date;
}

QString AmazonAuthHelper::toStrSize(QString size)
{
	ulong iSize = size.toULong();
	double fSize = iSize;
	int index = 0;
	while (fSize > 1024)
	{
		fSize /= 1024;
		index++;
	}

	QString result = QString("%1 %2").arg(QString::number(fSize, 'f', 2)).arg(sizes[index]);

	return result;
}
