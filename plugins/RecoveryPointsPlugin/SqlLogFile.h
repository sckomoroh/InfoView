#pragma once

#include <QString>

class RecoveryPointsParser;

class SqlLogFile
{
private:
	QString m_fileName;
	qlonglong m_iSize;

public:
	SqlLogFile();
	~SqlLogFile();

	QString fileName();

	qlonglong size();

private:
	friend class RecoveryPointsParser;
};

