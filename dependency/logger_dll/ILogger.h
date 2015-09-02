#pragma once

#include <string>
#include <stdarg.h>

class ILogger {
public:
	virtual ~ILogger(){ };

	enum {ERROR_LEVEL = 1, DEBUG_LEVEL = 2, INFO_LEVEL = 4};

	virtual bool Error(char*, ...)=0;
	virtual bool Info(char*, ...)=0;	
	virtual bool Debug(char*, ...)=0;

	virtual bool ErrorV(char*, va_list)=0;
	virtual bool InfoV(char*, va_list)=0;
	virtual bool DebugV(char*, va_list)=0;

	virtual void SetLogLevel(int log_level){
		m_log_level = log_level;
	};

protected:
	virtual bool _LogMessage(char*, char*, va_list)=0;

protected:
	int m_log_level;
};
