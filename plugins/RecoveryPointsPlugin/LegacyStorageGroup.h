#pragma once

#include <QString>
#include <QList>

#include "LegacyMailStore.h"

class RecoveryPointsParser;

class LegacyStorageGroup
{
private:
	QString m_logFilePath;
	QString m_systemPath;
	QString m_name;
	QString m_logPrefix;
	QList<LegacyMailStore*> m_mailStores;

public:
	LegacyStorageGroup();
	~LegacyStorageGroup();

	QString& logFilePath();
	QString& systemPath();
	QString& name();
	QString& logPrefix();
	QList<LegacyMailStore*>& mailStores();

private:
	friend class RecoveryPointsParser;
};

