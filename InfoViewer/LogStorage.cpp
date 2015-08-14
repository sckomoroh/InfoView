#include "LogStorage.h"


LogStorage::LogStorage()
{
}


LogStorage::~LogStorage()
{
	for each (LogLineData* pLine in m_data)
	{
		delete pLine;
	}
}

void LogStorage::addLogLine(LogLineData* pLogLine)
{
	m_data.append(pLogLine);
}

QList<CustomTextViewLine*>& LogStorage::lines()
{
	return m_data;
}

QList<CustomTextViewLine*> LogStorage::filteredLines(const QString& filterString, int iLevelFlag)
{
	QList<CustomTextViewLine*> result;
	bool bAddLine = false;

	for each (CustomTextViewLine* pLine in m_data)
	{
		LogLineData* pLogLine = (LogLineData*)pLine;
		int iLogLevel = (int)pLogLine->logType();
		if ((iLogLevel & iLevelFlag) == 0)
		{
			continue;
		}

		if (!filterString.isEmpty())
		{
			if (pLogLine->isHeader())
			{
				if (pLogLine->string().contains(filterString, Qt::CaseInsensitive))
				{
					result.append(pLine);
					bAddLine = true;
				}
				else
				{
					bAddLine = false;
				}
			}
			else if (bAddLine)
			{
				result.append(pLine);
			}
		}
		else
		{
			result.append(pLine);
		}
	}

	return result;
}
