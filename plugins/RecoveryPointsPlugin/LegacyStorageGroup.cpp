#include "LegacyStorageGroup.h"


LegacyStorageGroup::LegacyStorageGroup()
{
	QList<LegacyMailStore*>::iterator iter = m_mailStores.begin();
	for (; iter != m_mailStores.end(); iter++)
	{
		LegacyMailStore* pItem = *iter;
		delete pItem;
	}

	m_mailStores.clear();
}


LegacyStorageGroup::~LegacyStorageGroup()
{
}

QString& LegacyStorageGroup::logFilePath()
{
	return m_logFilePath;
}

QString& LegacyStorageGroup::systemPath()
{
	return m_systemPath;
}

QString& LegacyStorageGroup::name()
{
	return m_name;
}

QString& LegacyStorageGroup::logPrefix()
{
	return m_logPrefix;
}

QList<LegacyMailStore*>& LegacyStorageGroup::mailStores()
{
	return m_mailStores;
}
