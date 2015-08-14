#include "LogManager.h"
#include <stdarg.h>

// ---------------------------------------------------------------------------------
CLogManager::CLogManager(void) {
}
// ---------------------------------------------------------------------------------
CLogManager::~CLogManager(void) {
	CLoggerMap::iterator iter = m_loggers.begin();
	while(iter != m_loggers.end()){
		delete iter->second;
		iter++;
	}
}
// ---------------------------------------------------------------------------------
bool CLogManager::RegisterLogger(std::string s_log_id, ILogger* p_logger) {
// 	m_loggers.insert(std::pair<std::string, ILogger*>(s_log_id, p_logger));
	m_loggers[s_log_id] = p_logger;
	return true;
}
// ---------------------------------------------------------------------------------
bool CLogManager::UnregisterLogger(std::string s_log_id) {
	m_loggers.erase(s_log_id);
	return true;
}
// ---------------------------------------------------------------------------------
bool CLogManager::Info(char* s_format_str, ...) {
	va_list arg_list;
	va_start(arg_list, s_format_str);

	CLoggerMap::iterator iter = m_loggers.begin();
	while(iter != m_loggers.end()){
		(iter->second)->InfoV(s_format_str, arg_list);
		iter++;
	}

	va_end(arg_list);

	return true;
}
// ---------------------------------------------------------------------------------
bool CLogManager::Debug(char* s_format_str, ...) {
	va_list arg_list;
	va_start(arg_list, s_format_str);

	CLoggerMap::iterator iter = m_loggers.begin();
	while(iter != m_loggers.end()){
		(iter->second)->DebugV(s_format_str, arg_list);
		iter++;
	}

	va_end(arg_list);

	return true;
}
// ---------------------------------------------------------------------------------
bool CLogManager::Error(char* s_format_str, ...) {
	va_list arg_list;
	va_start(arg_list, s_format_str);

	CLoggerMap::iterator iter = m_loggers.begin();
	while(iter != m_loggers.end()){
		(iter->second)->ErrorV(s_format_str, arg_list);
		iter++;
	}

	va_end(arg_list);

	return true;
}
// ---------------------------------------------------------------------------------
bool CLogManager::ErrorV(char* s_format_str, va_list arg_list) {
	CLoggerMap::iterator iter = m_loggers.begin();
	while(iter != m_loggers.end()){
		(iter->second)->ErrorV(s_format_str, arg_list);
		iter++;
	}
	return true;
}
// ---------------------------------------------------------------------------------
bool CLogManager::InfoV(char* s_format_str, va_list arg_list) {
	CLoggerMap::iterator iter = m_loggers.begin();
	while(iter != m_loggers.end()){
		(iter->second)->InfoV(s_format_str, arg_list);
		iter++;
	}
	return true;
}
// ---------------------------------------------------------------------------------
bool CLogManager::DebugV(char* s_format_str, va_list arg_list) {
	CLoggerMap::iterator iter = m_loggers.begin();
	while(iter != m_loggers.end()){
		(iter->second)->DebugV(s_format_str, arg_list);
		iter++;
	}
	return true;
}
// ---------------------------------------------------------------------------------
ILogger* CLogManager::GetLogger(std::string s_log_id){
	return m_loggers[s_log_id];
}
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
CLogManager* CLogger::m_pLogManager = NULL;
// ---------------------------------------------------------------------------------
CLogManager* CLogger::GetLogger() {
	if(m_pLogManager == NULL) 
		m_pLogManager = new CLogManager;

	return m_pLogManager;
}
// ---------------------------------------------------------------------------------
void CLogger::RegisterLogger(std::string sLoggerName, ILogger* pLogger) {
	if(m_pLogManager == NULL)
		m_pLogManager = new CLogManager;

	m_pLogManager->RegisterLogger(sLoggerName, pLogger);
}
// ---------------------------------------------------------------------------------
void CLogger::Destroy() {
	if(m_pLogManager) {
		delete m_pLogManager;
		m_pLogManager = NULL;
	}
}
// ---------------------------------------------------------------------------------
void CLogger::Info(char* s_format_str, ...) {
	va_list arg_list;
	va_start(arg_list, s_format_str);

	m_pLogManager->InfoV(s_format_str, arg_list);

	va_end(arg_list);
}
// ---------------------------------------------------------------------------------
void CLogger::Error(char* s_format_str, ...) {
	va_list arg_list;
	va_start(arg_list, s_format_str);

	m_pLogManager->ErrorV(s_format_str, arg_list);

	va_end(arg_list);
}
// ---------------------------------------------------------------------------------
void CLogger::Debug(char* s_format_str, ...) {
	va_list arg_list;
	va_start(arg_list, s_format_str);

	m_pLogManager->DebugV(s_format_str, arg_list);

	va_end(arg_list);
}
// ---------------------------------------------------------------------------------
