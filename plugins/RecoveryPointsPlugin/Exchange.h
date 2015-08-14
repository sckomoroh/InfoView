#pragma once

#include <QString>
#include <QList>

#include "MailStore.h"
#include "LegacyStorageGroup.h"

class RecoveryPointsParser;

class Exchange
{
private:
	QString m_version;
	QString m_displayName;
	QList<MailStore*> m_mailStores;
	QList<LegacyStorageGroup*> m_legacyStorageGroups;

public:
	Exchange();
	~Exchange();

public:
	QString& version();

	QString& displayName();

	QList<MailStore*>& mailStores();
	QList<LegacyStorageGroup*>& legacyStorageGroups();

private:
	friend class RecoveryPointsParser;
};

