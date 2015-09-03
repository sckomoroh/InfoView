#pragma once

#include "ILogClient.h"

#include "ILogger.h"
#include "FileLogger.h"

class LogClientImpl
	: public ILogClient
{
private:
	ILogger* m_fileLogger;

public:
	LogClientImpl();

	virtual void initLogger(char* fileName);
	virtual void setLogLevel(int level);

	virtual bool Error(char*, ...);
	virtual bool Info(char*, ...);
	virtual bool Debug(char*, ...);
};
