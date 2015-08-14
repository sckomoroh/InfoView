#include "SqlFileGroup.h"


SqlFileGroup::SqlFileGroup()
{
	QList<SqlDataFile*>::iterator iter = m_dataFiles.begin();
	for (; iter != m_dataFiles.end(); iter++)
	{
		SqlDataFile* pSqlDataFile = *iter;
		delete pSqlDataFile;
	}

	m_dataFiles.clear();
}

SqlFileGroup::~SqlFileGroup()
{
}

QString SqlFileGroup::name()
{
	return m_name;
}

bool SqlFileGroup::isFileStream()
{
	return m_bIsFileStream;
}

QList<SqlDataFile*> SqlFileGroup::dataFiles()
{
	return m_dataFiles;
}
