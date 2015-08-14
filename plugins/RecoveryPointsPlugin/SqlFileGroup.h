#pragma once

#include <QString>
#include <QList>

#include "SqlDataFile.h"

class RecoveryPointsParser;

class SqlFileGroup
{
private:
	QString m_name;
	bool m_bIsFileStream;
	QList<SqlDataFile*> m_dataFiles;

public:
	SqlFileGroup();
	~SqlFileGroup();

	QString name();

	bool isFileStream();

	QList<SqlDataFile*> dataFiles();

private:
	friend class RecoveryPointsParser;
};

