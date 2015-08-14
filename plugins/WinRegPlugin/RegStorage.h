#pragma once

#include "RegKeyData.h"

class RegStorage
{
private:
	const RegKeyData* m_pRootKey;

public:
	RegStorage();
	~RegStorage();

	inline const RegKeyData* rootKey() const
	{
		return m_pRootKey;
	}

	void setRootKey(const RegKeyData* pRootKey);
	void reset();
};

