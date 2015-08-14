#pragma once

#include <QString>

class CustomTextViewSearchLine
{
private:
	uint m_iLineNumber;
	uint m_iPosition;
	uint m_iLogId;
	uint m_iLenght;
	QString m_string;
	bool m_bIsTitle;

public:
	CustomTextViewSearchLine(const QString& string, uint iLineNumber, uint iPosition, uint iLogId, uint iLenght);
	virtual ~CustomTextViewSearchLine();

	inline uint	lineNumber()
	{
		return m_iLineNumber;
	}

	inline uint	position()
	{
		return m_iPosition;
	}

	inline uint	logId()
	{
		return m_iLogId;
	}

	inline uint	lenght()
	{
		return m_iLenght;
	}

	inline const QString& string() const
	{
		return m_string;
	}

	inline bool	isTitle()
	{
		return m_bIsTitle;
	}

	void setTitle(bool bIsTitle);
};

