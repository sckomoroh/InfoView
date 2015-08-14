#include "RegStorage.h"


RegStorage::RegStorage()
	: m_pRootKey(NULL)
{
}


RegStorage::~RegStorage()
{
	if (m_pRootKey != NULL)
	{
		delete m_pRootKey;
	}
}

void RegStorage::setRootKey(const RegKeyData* pRootKey)
{
	if (m_pRootKey != NULL)
	{
		delete m_pRootKey;
	}

	m_pRootKey = pRootKey;
}

void RegStorage::reset()
{
	delete m_pRootKey;
	m_pRootKey = NULL;
}
