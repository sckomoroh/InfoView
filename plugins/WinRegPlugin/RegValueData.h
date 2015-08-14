#pragma once

#include <QString>

class RegParser;

enum RegValueDataType
{
	RegString,
	RegDWord,
	RegBinary,
	RegUnknown
};

class RegValueData
{
private:
	QString m_valueName;
	QString m_value;
	RegValueDataType m_valueType;

public:
	RegValueData();
	~RegValueData();

	inline const QString& name() const
	{
		return m_valueName;
	}

	inline const QString& value() const
	{
		return m_value;
	}

	inline const RegValueDataType valueType() const
	{
		return m_valueType;
	}

	QString valueTypeToString();

private:
	void addValueLine(const QString& line);

	friend class RegParser;
};

