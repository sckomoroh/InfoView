#include "SqlDatabase.h"


SqlDatabase::SqlDatabase()
{
}


SqlDatabase::~SqlDatabase()
{
	{
		QList<SqlFileGroup*>::iterator iter = m_fileGroups.begin();
		for (; iter != m_fileGroups.end(); iter++)
		{
			SqlFileGroup* pSqlFileGroup = *iter;
			delete pSqlFileGroup;
		}

		m_fileGroups.clear();
	}

	{
		QList<SqlLogFile*>::iterator iter = m_logFiles.begin();
		for (; iter != m_logFiles.end(); iter++)
		{
			SqlLogFile* pSqlLogFile = *iter;
			delete pSqlLogFile;
		}

		m_logFiles.clear();
	}
}

QString SqlDatabase::name()
{
	return m_name;
}

bool SqlDatabase::IsOnline()
{
	return m_bIsOnline;
}

QList<SqlFileGroup*> SqlDatabase::fileGroups()
{
	return m_fileGroups;
}

QList<SqlLogFile*> SqlDatabase::logFiles()
{
	return m_logFiles;
}

CheckState SqlDatabase::checkState()
{
	return m_checkState;
}
