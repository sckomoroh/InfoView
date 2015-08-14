#pragma once

#include "CustomTextViewLine.h"

enum LogType
{
	LogTypeDebug		= 0x1,
	LogTypeInformation	= 0x2,
	LogTypeError		= 0x4,
	LogTypeWarning		= 0x8,
	LogTypeFatal		= 0x10,
	LogTypeTrace		= 0x20,
	LogTypeUnknown		= 0x40
};


class LogLineData : public CustomTextViewLine
{
private:
	static const QColor m_debugColor;
	static const QColor m_errorColor;
	static const QColor m_warnColor;
	static const QColor m_infoColor;

private:
	LogType m_logType;

public:
	LogLineData(const QString& content, bool isHeader, LogType logType);
	~LogLineData();

	inline LogType logType()
	{
		return m_logType;
	}

	bool isHeader()
	{
		return isBold();
	}
};

