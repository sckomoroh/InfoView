#pragma once

#include <QString>

class AmazonAuthHelper
{
private:
	QString m_AWSAccessKeyId;
	QString m_AWSSecretAccessKey;
	QString m_bucketName;
	QString m_amazonAddress;

	QString m_signatureKey;
	QString m_date;

public:
	AmazonAuthHelper(const QString& accessKey, const QString& secret, const QString& bucketName, const QString& amzAddr);
	~AmazonAuthHelper();

	QString getAuthHeader(QString resource);
	QString date();

	static QString toPercentEncoding(QString str);
	static QString toStrSize(QString size);

private:
	QString getStringToSign(QString resource);
	QString getSignature(QString resource);
	QString getAuthenticationString(QString signature);
};

