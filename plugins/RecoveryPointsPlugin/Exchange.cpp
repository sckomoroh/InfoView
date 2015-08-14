#include "Exchange.h"


Exchange::Exchange()
{

}

Exchange::~Exchange()
{
	{
		QList<MailStore*>::iterator iter = m_mailStores.begin();
		for (; iter != m_mailStores.end(); iter++)
		{
			MailStore* pMailStores = *iter;
			delete pMailStores;
		}

		m_mailStores.clear();
	}

	{
		QList<LegacyStorageGroup*>::iterator iter = m_legacyStorageGroups.begin();
		for (; iter != m_legacyStorageGroups.end(); iter++)
		{
			LegacyStorageGroup* pItem = *iter;
			delete pItem;
		}

		m_legacyStorageGroups.clear();
	}
}

QString& Exchange::version()
{
	return m_version;
}

QString& Exchange::displayName()
{
	return m_displayName;
}

QList<MailStore*>& Exchange::mailStores()
{
	return m_mailStores;
}

QList<LegacyStorageGroup*>& Exchange::legacyStorageGroups()
{
	return m_legacyStorageGroups;
}
