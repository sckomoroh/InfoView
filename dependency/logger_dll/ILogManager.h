#pragma once

class ILogManager
{
public:
	virtual bool Info(char* s_format_str, ...) = 0;
	virtual bool Error(char* s_format_str, ...) = 0;
	virtual bool Debug(char* s_format_str, ...) = 0;
};
