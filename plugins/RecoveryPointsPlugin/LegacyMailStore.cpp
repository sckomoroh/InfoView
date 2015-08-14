#include "LegacyMailStore.h"


LegacyMailStore::LegacyMailStore()
{
}


LegacyMailStore::~LegacyMailStore()
{
}

QString& LegacyMailStore::name()
{
	return m_name;
}

QString& LegacyMailStore::mailStoreType()
{
	return m_mailStoreType;
}

QString& LegacyMailStore::exchangeDatabasePath()
{
	return m_exchangeDatabasePath;
}

CheckStatesParser::CheckState LegacyMailStore::checkState()
{
	return m_checkState;
}
