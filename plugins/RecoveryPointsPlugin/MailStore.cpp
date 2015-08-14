#include "MailStore.h"


MailStore::MailStore()
{
}


MailStore::~MailStore()
{
}

QString& MailStore::exchangeDatabasePath()
{
	return m_exchangeDatabasePath;
}

QString& MailStore::logFilePath()
{
	return m_logFilePath;
}

QString& MailStore::systemPath()
{
	return m_systemPath;
}

QString& MailStore::name()
{
	return m_name;
}

QString& MailStore::logPrefix()
{
	return m_logPrefix;
}

CheckStatesParser::CheckState MailStore::checkState()
{
	return m_checkState;
}
