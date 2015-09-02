#pragma once

#include <QString>

class AmazonAuthHelper
{
private:
	static const QString m_AWSAccessKeyId;
	static const QString m_AWSSecretAccessKey;
	static const QString m_bucketName;
	static const QString m_amazonAddress;

	QString m_signatureKey;
	QString m_date;

public:
	AmazonAuthHelper();
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

