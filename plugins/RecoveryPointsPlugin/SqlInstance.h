#pragma once

#include <QString>
#include <QList>

#include "SqlDatabase.h"

class RecoveryPointsParser;

class SqlInstance
{
private:
	QString m_name;
	QString m_version;
	QList<SqlDatabase*> m_databases;

public:
	SqlInstance();
	~SqlInstance();

public:
	QString name();

	QString version();

	QList<SqlDatabase*> databases();

private:
	friend class RecoveryPointsParser;
};

