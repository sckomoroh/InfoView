#pragma once

#include <QString>

#include "CheckStates.h"

class RecoveryPointsParser;

class LegacyMailStore
{
private:
	QString m_name;
	QString m_mailStoreType;
	QString m_exchangeDatabasePath;
	CheckStatesParser::CheckState m_checkState;

public:
	LegacyMailStore();
	~LegacyMailStore();

	QString& name();
	QString& mailStoreType();
	CheckStatesParser::CheckState checkState();
	QString& exchangeDatabasePath();

private:
	friend class RecoveryPointsParser;
};

