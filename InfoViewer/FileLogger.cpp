#include "FileLogger.h"
#include <stdarg.h>
#include <stdio.h>

using namespace std;

CRITICAL_SECTION CFileLogger::m_csWrite;

// -------------------------------------------------------------------------------------
CFileLogger::CFileLogger(char* s_file_name) {
	InitializeCriticalSection(&m_csWrite);
	m_s_file_name = new char[strlen(s_file_name) + 1];
	strcpy_s(m_s_file_name, strlen(s_file_name) + 1, s_file_name);
	m_log_level = ERROR_LEVEL | DEBUG_LEVEL | INFO_LEVEL;
}

CFileLogger::~CFileLogger(void) {
	delete[] m_s_file_name;
	DeleteCriticalSection(&m_csWrite);
}
// -------------------------------------------------------------------------------------
bool CFileLogger::InfoV(char* s_format_str, va_list arg_list){
	if(!(m_log_level & INFO_LEVEL))
		return false;

	bool b_result = _LogMessage("[INFO] ", s_format_str, arg_list);

	return b_result;
}
// -------------------------------------------------------------------------------------
bool CFileLogger::DebugV(char* s_format_str, va_list arg_list){
	if(!(m_log_level & DEBUG_LEVEL))
		return false;

	bool b_result = _LogMessage("[DEBUG] ", s_format_str, arg_list);

	return b_result;
}
// -------------------------------------------------------------------------------------
bool CFileLogger::ErrorV(char* s_format_str, va_list arg_list){
	if(!(m_log_level & ERROR_LEVEL))
		return false;

	bool b_result = _LogMessage("[ERROR] ", s_format_str, arg_list);

	return b_result;
}
// -------------------------------------------------------------------------------------
bool CFileLogger::Error(char* s_format_str, ...){
	if(!(m_log_level & ERROR_LEVEL))
		return false;

	va_list arg_list;
	va_start(arg_list, s_format_str);

	bool b_result = _LogMessage("[ERROR] ", s_format_str, arg_list);

	va_end(arg_list);

	return b_result;
}
// -------------------------------------------------------------------------------------
bool CFileLogger::Info(char* s_format_str, ...){
	if(!(m_log_level & INFO_LEVEL))
		return false;

	va_list arg_list;
	va_start(arg_list, s_format_str);

	bool b_result = _LogMessage("[INFO] ", s_format_str, arg_list);

	va_end(arg_list);

	return b_result;
}
// -------------------------------------------------------------------------------------
bool CFileLogger::Debug(char* s_format_str, ...){
	if(!(m_log_level & DEBUG_LEVEL))
		return false;

	va_list arg_list;
	va_start(arg_list, s_format_str);

	bool b_result = _LogMessage("[DEBUG] ", s_format_str, arg_list);

	va_end(arg_list);

	return b_result;
}
// -------------------------------------------------------------------------------------
bool CFileLogger::_LogMessage(char* s_log_str, char* s_format, va_list vlist){
	EnterCriticalSection(&m_csWrite);
	FILE* p_file;
	fopen_s(&p_file, m_s_file_name, "a");
	if(p_file == NULL) {
		LeaveCriticalSection(&m_csWrite);
		return false;
	}

	SYSTEMTIME system_time;
	GetSystemTime(&system_time);

	fprintf(p_file, "%-8s %02d.%02d.%04d-%02d:%02d.%02d-%03d ", s_log_str, 
		system_time.wDay, system_time.wMonth, system_time.wYear,
		system_time.wHour, system_time.wMinute, system_time.wSecond, system_time.wMilliseconds);
	vfprintf(p_file, s_format, vlist);
	fprintf(p_file, "\n");

	fclose(p_file);
	LeaveCriticalSection(&m_csWrite);
	return true;
}
// -------------------------------------------------------------------------------------
