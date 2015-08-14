#include "SqlInstance.h"


SqlInstance::SqlInstance()
{
	QList<SqlDatabase*>::iterator iter = m_databases.begin();
	for (; iter != m_databases.end(); iter++)
	{
		SqlDatabase* pSqlDatabase = *iter;
		delete pSqlDatabase;
	}

	m_databases.clear();
}


SqlInstance::~SqlInstance()
{
}

QString SqlInstance::name()
{
	return m_name;
}

QString SqlInstance::version()
{
	return m_version;
}

QList<SqlDatabase*> SqlInstance::databases()
{
	return m_databases;
}
