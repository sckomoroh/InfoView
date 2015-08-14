#pragma once

#include <QWidget>

#include "msinfoplugin_global.h"

class PLUGIN_EXPORT IPlugin
{
public:
	virtual wchar_t*	getPluginName() = 0;
	virtual wchar_t*	getPluginId() = 0;
	virtual void		initPluginData(wchar_t* path) = 0;
	virtual void		resetPluginData() = 0;
};

class PLUGIN_EXPORT IQtPlugin : public IPlugin
{
public:
	virtual QWidget*	getPluginWidget() = 0;
	virtual QImage*		getPluginIcon() = 0;
};

extern "C" PLUGIN_EXPORT IPlugin* createQtPlugin();
extern "C" PLUGIN_EXPORT int isWin32Plugin();
