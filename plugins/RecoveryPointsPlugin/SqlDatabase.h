#pragma once

#include <QString>
#include <QList>

#include "SqlFileGroup.h"
#include "SqlLogFile.h"
#include "CheckStates.h"

class RecoveryPointsParser;

class SqlDatabase
{
private:
	QString m_name;
	bool m_bIsOnline;
	QList<SqlFileGroup*> m_fileGroups;
	QList<SqlLogFile*> m_logFiles;
	CheckState m_checkState;

public:
	SqlDatabase();
	~SqlDatabase();

public:
	QString name();

	bool IsOnline();

	QList<SqlFileGroup*> fileGroups();

	QList<SqlLogFile*> logFiles();

	CheckState checkState();

private:
	friend class RecoveryPointsParser;
};

