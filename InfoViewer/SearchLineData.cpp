#include "SearchLineData.h"


SearchLineData::SearchLineData(CustomTextViewSearchLine* pSearchLine, bool bIsTitle)
	: CustomTextViewLine(pSearchLine->string(), bIsTitle)
	, m_iLogId(pSearchLine->logId())
	, m_iLenght(pSearchLine->lenght())
	, m_iLine(pSearchLine->lineNumber())
	, m_iPosition(pSearchLine->position())
{
}

SearchLineData::SearchLineData(CustomTextViewSearchLine* pSearchLine)
	: CustomTextViewLine(pSearchLine->string(), false)
	, m_iLogId(pSearchLine->logId())
	, m_iLenght(pSearchLine->lenght())
	, m_iLine(pSearchLine->lineNumber())
	, m_iPosition(pSearchLine->position())
{
}

SearchLineData::~SearchLineData()
{
}

uint SearchLineData::lineNumber()
{
	return m_iLine;
}

uint SearchLineData::position()
{
	return m_iPosition;
}

uint SearchLineData::lenght()
{
	return m_iLenght;
}

uint SearchLineData::logId()
{
	return m_iLogId;
}

bool SearchLineData::isTitle()
{
	return isBold();
}
