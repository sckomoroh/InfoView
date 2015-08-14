#pragma once

#include "MsInfoCategory.h"

class MsInfoStorage
{
private:
	MsInfoCategory* m_pRootCategory;

public:
	MsInfoStorage();
	~MsInfoStorage();

	void setRootCategory(MsInfoCategory* pRootCategory);

	inline const MsInfoCategory* rootCategory() const
	{
		return m_pRootCategory;
	}

	void reset();
};

