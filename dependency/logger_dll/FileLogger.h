#pragma once
#include "ilogger.h"
#include <windows.h>

class CFileLogger : public ILogger {
public:
	virtual bool Error(char*, ...);
	virtual bool Info(char*, ...);
	virtual bool Debug(char*, ...);
	virtual bool Warn(char*, ...);

	virtual bool ErrorV(char*, va_list);
	virtual bool InfoV(char*, va_list);
	virtual bool DebugV(char*, va_list);
	virtual bool WarnV(char*, va_list);

	virtual ~CFileLogger(void);
	CFileLogger(char*);

protected:
	virtual bool _LogMessage(char*, char*, va_list);

protected:
	char* m_s_file_name;

	static CRITICAL_SECTION	m_csWrite;
};
