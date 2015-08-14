#pragma once

#include <QString>

class ProviderData
{
private:
	QString m_data;
	bool m_bIsChecked;

public:
	ProviderData(const QString& data)
		: m_data(data)
		, m_bIsChecked(true)
	{
	}

	~ProviderData()
	{
	}

	QString& data()
	{
		return m_data;
	}

	bool isChecked()
	{
		return m_bIsChecked;
	}

	void setChecked(bool isChecked)
	{
		m_bIsChecked = isChecked;
	}
};

