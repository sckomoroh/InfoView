#pragma once

#include <QList>
#include <QString>

#include "RegValueData.h"

class RegKeyData
{
private:
	QList<RegKeyData*>		m_childrenKeys;
	QList<RegValueData*>	m_values;
	QString					m_fullName;
	RegKeyData*				m_pParent;

public:
	RegKeyData();
	~RegKeyData();

	inline const QString& fullName() const
	{
		return m_fullName;
	}

	inline const QList<RegKeyData*>& keys() const
	{
		return m_childrenKeys;
	}

	inline const QList<RegValueData*>& values() const
	{
		return m_values;
	}

	inline RegKeyData* parent()
	{
		return m_pParent;
	}

	QString shortName();

	void setFullName(const QString& name);

	void addKey(RegKeyData* key);
	void addValue(RegValueData* value);

	void setParent(RegKeyData* pParent);
};

