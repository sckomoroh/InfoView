#pragma once

#include <QString>

#include "LogParser.h"

class SearchAllData : public LogLineData
{
private:
	bool	m_bIsTitle;
	int		m_iLogIndex;
	int		m_iLineNumber;
	int		m_iPosition;
	int		m_iLenght;

public:
	SearchAllData();
	~SearchAllData();

	bool	isTitle();
	int		logIndex();
	int		lineNumber();
	int		position();
	int		lenght();

	void	setTitle(bool bTitle);
	void	setLogIndex(int iLogIndex);
	void	setLineNumber(int iLineNumder);
	void	setPosition(int iPosition);
	void	setLenght(int iLength);
};

