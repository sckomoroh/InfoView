#include "MsInfoStorage.h"


MsInfoStorage::MsInfoStorage()
	: m_pRootCategory(NULL)
{
}


MsInfoStorage::~MsInfoStorage()
{
	reset();
}

void MsInfoStorage::setRootCategory(MsInfoCategory* pRootCategory)
{
	reset();

	m_pRootCategory = pRootCategory;
}

void MsInfoStorage::reset()
{
	if (m_pRootCategory != NULL)
	{
		delete m_pRootCategory;
	}

	m_pRootCategory = NULL;
}
