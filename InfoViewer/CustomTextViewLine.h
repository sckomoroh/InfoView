#pragma once

#include <QString>
#include <QColor>

class CustomTextViewLine
{
private:
	static const QColor* m_pDefaultColor;

private:
	const QColor*	m_pColor;
	const QString	m_string;
	const bool		m_bBold;

public:
	CustomTextViewLine(const QString& str, const QColor* color, const bool isBold);
	CustomTextViewLine(const QString& str, const QColor* color);
	CustomTextViewLine(const QString& str);
	CustomTextViewLine(const QString& str, const bool isBold);

	virtual ~CustomTextViewLine();

	inline const QString& string() const
	{
		return m_string;
	}

	inline bool isBold()
	{
		return m_bBold;
	}

	inline const QColor* color()
	{
		return m_pColor;
	}

	inline void setColor(const QColor* pColor)
	{
		m_pColor = pColor;
	}
};

