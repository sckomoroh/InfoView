#pragma once

#include "CustomTextViewLine.h"
#include "CustomTextViewSearchLine.h"

class SearchLineData : public CustomTextViewLine
{
private:
	uint m_iLine;
	uint m_iPosition;
	uint m_iLenght;
	uint m_iLogId;

public:
	SearchLineData(CustomTextViewSearchLine* pSearchLine);
	SearchLineData(CustomTextViewSearchLine* pSearchLine, bool bIsTitle);

	virtual ~SearchLineData();

	const QString& string() const
	{
		return CustomTextViewLine::string();
	}

	uint lineNumber();
	uint position();
	uint lenght();
	uint logId();
	bool isTitle();
};

