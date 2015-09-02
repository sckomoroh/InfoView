#pragma once

#ifdef NEED_TO_EXPORT
#define LOG_CLIENT_EXPORT_DLL __declspec(dllexport)
#else
#define LOG_CLIENT_EXPORT_DLL __declspec(dllimport)
#endif

class LOG_CLIENT_EXPORT_DLL ILogClient
{
public:
	virtual void initLogger(char* fileName) = 0;
	virtual void setLogLevel(int level	) = 0;

	virtual bool Error(char*, ...) = 0;
	virtual bool Info(char*, ...) = 0;
	virtual bool Debug(char*, ...) = 0;
};

LOG_CLIENT_EXPORT_DLL ILogClient* getLogClientInstance();
