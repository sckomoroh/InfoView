#include "CustomTextViewSearchLine.h"


CustomTextViewSearchLine::CustomTextViewSearchLine(const QString& string, uint iLineNumber, uint iPosition, uint iLogId, uint iLenght)
	: m_iLineNumber(iLineNumber)
	, m_iLenght(iLenght)
	, m_iLogId(iLogId)
	, m_iPosition(iPosition)
	, m_string(string)
	, m_bIsTitle(false)
{
}

CustomTextViewSearchLine::~CustomTextViewSearchLine()
{
}

void CustomTextViewSearchLine::setTitle(bool bIsTitle)
{
	m_bIsTitle = bIsTitle;
}
