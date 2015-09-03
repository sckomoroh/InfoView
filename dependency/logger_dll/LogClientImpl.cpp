#include "stdafx.h"

#include "LogClientImpl.h"
#include "LogManager.h"

#include <stdarg.h>

#define FILE_LOGGER_NAME	"FILE_LOGGER"

ILogClient* g_dll_impl = NULL;

ILogClient* getLogClientInstance()
{
	if (g_dll_impl == NULL)
	{
		g_dll_impl = new LogClientImpl();
	}

	return g_dll_impl;
}

LogClientImpl::LogClientImpl()
: m_fileLogger(NULL)
{
}

void LogClientImpl::initLogger(char* fileName)
{
	if (m_fileLogger != NULL)
	{
		return;
	}

	m_fileLogger = new CFileLogger(fileName);
	CLogger::RegisterLogger(FILE_LOGGER_NAME, m_fileLogger);
}

void LogClientImpl::setLogLevel(int level)
{
	if (m_fileLogger == NULL)
	{
		return;
	}

	m_fileLogger->SetLogLevel(level);
}

bool LogClientImpl::Error(char* format, ...)
{
	if (m_fileLogger == NULL)
	{
		return false;
	}

	va_list arg_list;
	va_start(arg_list, format);

	bool result = CLogger::GetLogger()->ErrorV(format, arg_list);

	va_end(arg_list);

	return result;
}

bool LogClientImpl::Info(char* format, ...)
{
	if (m_fileLogger == NULL)
	{
		return false;
	}

	va_list arg_list;
	va_start(arg_list, format);

	bool result = CLogger::GetLogger()->InfoV(format, arg_list);

	va_end(arg_list);

	return result;
}

bool LogClientImpl::Debug(char* format, ...)
{
	if (m_fileLogger == NULL)
	{
		return false;
	}

	va_list arg_list;
	va_start(arg_list, format);

	bool result = CLogger::GetLogger()->DebugV(format, arg_list);

	va_end(arg_list);

	return result;
}
