#pragma once

#include <QList>

#include "LogLineData.h"

class LogStorage
{
private:
	QList<CustomTextViewLine*> m_data;

public:
	LogStorage();
	~LogStorage();

	void addLogLine(LogLineData* pLogLine);
	QList<CustomTextViewLine*>& lines();

	QList<CustomTextViewLine*> filteredLines(const QString& filterString, int iLevelFlag);
};

