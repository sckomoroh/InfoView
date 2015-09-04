#pragma once

#include <map>
#include <string>
#include "ILogger.h"
#include "ILogManager.h"

typedef std::map<std::string, ILogger*> CLoggerMap;

class CLogManager 
: public ILogManager {
public:
	CLogManager(void);
	~CLogManager(void);

public:
	bool RegisterLogger(std::string, ILogger*);
	bool UnregisterLogger(std::string);

	bool Info(char* s_format_str, ...);
	bool Error(char* s_format_str, ...);
	bool Debug(char* s_format_str, ...);
	bool Warn(char* s_format_str, ...);

	bool InfoV(char* s_format_str, va_list arg_list);
	bool ErrorV(char* s_format_str, va_list arg_list);
	bool DebugV(char* s_format_str, va_list arg_list);
	bool WarnV(char* s_format_str, va_list arg_list);

	// For logging in the separate logger
	ILogger* GetLogger(std::string);
	
protected:
	CLoggerMap m_loggers;
};

class CLogger {
protected:
	CLogger() {}
	CLogger(CLogger&) {}

public:
	static CLogManager*	GetLogger();
	static void	RegisterLogger(std::string sLoggerName, ILogger* pLogger);	
	static void Destroy();

	static void Info(char* s_format_str, ...);
	static void Error(char* s_format_str, ...);
	static void Debug(char* s_format_str, ...);
	static void Warn(char* s_format_str, ...);

private:
	static CLogManager*	m_pLogManager;
};
