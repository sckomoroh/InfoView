#pragma once

#include <QString>

#include "CheckStates.h"

class RecoveryPointsParser;

class MailStore
{
private:
	QString m_exchangeDatabasePath;
	QString m_logFilePath;
	QString m_systemPath;
	QString m_name;
	QString m_logPrefix;
	CheckStatesParser::CheckState m_checkState;

public:
	MailStore();
	~MailStore();

	QString& exchangeDatabasePath();

	QString& logFilePath();

	QString& systemPath();

	QString& name();

	QString& logPrefix();

	CheckStatesParser::CheckState checkState();

private:
	friend class RecoveryPointsParser;
};

