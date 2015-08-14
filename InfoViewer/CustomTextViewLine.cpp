#include "CustomTextViewLine.h"

const QColor* CustomTextViewLine::m_pDefaultColor = new QColor(0, 0, 0);

CustomTextViewLine::CustomTextViewLine(const QString& str, const QColor* pColor, const bool isBold)
	: m_bBold(isBold)
	, m_pColor(pColor)
	, m_string(str)
{
}

CustomTextViewLine::CustomTextViewLine(const QString& str, const QColor* pColor)
	: m_bBold(false)
	, m_pColor(pColor)
	, m_string(str)
{
}

CustomTextViewLine::CustomTextViewLine(const QString& str)
	: m_bBold(false)
	, m_pColor(m_pDefaultColor)
	, m_string(str)
{
}

CustomTextViewLine::CustomTextViewLine(const QString& str, const bool isBold)
	: m_bBold(isBold)
	, m_pColor(m_pDefaultColor)
	, m_string(str)
{
}

CustomTextViewLine::~CustomTextViewLine()
{
}
