#include "RegKeyData.h"

RegKeyData::RegKeyData()
	: m_pParent(NULL)
{
}

RegKeyData::~RegKeyData()
{
	for each (RegValueData* pRegValue in m_values)
	{
		delete pRegValue;
	}

	for each (RegKeyData* pRegKey in m_childrenKeys)
	{
		delete pRegKey;
	}
}

void RegKeyData::addKey(RegKeyData* key)
{
	m_childrenKeys.append(key);
}

void RegKeyData::addValue(RegValueData* value)
{
	m_values.append(value);
}

QString RegKeyData::shortName()
{
	int index = m_fullName.lastIndexOf('\\') + 1;
	QString result = m_fullName.mid(index, m_fullName.length() - index);

	return result;
}

void RegKeyData::setFullName(const QString& fullName)
{
	m_fullName = fullName;
}

void RegKeyData::setParent(RegKeyData* pParent)
{
	m_pParent = pParent;
}
