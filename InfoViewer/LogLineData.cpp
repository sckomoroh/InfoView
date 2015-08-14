#include "LogLineData.h"

const QColor LogLineData::m_debugColor = QColor(100, 100, 100);
const QColor LogLineData::m_errorColor = QColor(127, 0, 0);
const QColor LogLineData::m_warnColor = QColor(127, 106, 0);
const QColor LogLineData::m_infoColor = QColor(38, 127, 0);

LogLineData::LogLineData(const QString& content, bool isHeader, LogType logType)
	: CustomTextViewLine(content, isHeader)
	, m_logType(logType)
{
	switch (logType)
	{
		case LogType::LogTypeDebug:
			setColor(&m_debugColor);
			break;
		case LogType::LogTypeError:
		case LogType::LogTypeFatal:
			setColor(&m_errorColor);
			break;
		case LogType::LogTypeInformation:
			setColor(&m_infoColor);
			break;
		case LogType::LogTypeWarning:
			setColor(&m_warnColor);
			break;
		default:
			setColor(&m_debugColor);
	}
}

LogLineData::~LogLineData()
{
}
