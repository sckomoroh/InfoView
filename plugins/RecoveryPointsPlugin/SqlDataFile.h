#pragma once

#include <QString>

class RecoveryPointsParser;

class SqlDataFile
{
private:
	QString m_fileName;
	qlonglong m_iSize;

public:
	SqlDataFile();
	~SqlDataFile();

	QString fileName();

	qlonglong size();

private:
	friend class RecoveryPointsParser;
};

