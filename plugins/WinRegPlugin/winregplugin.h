#ifndef WINREGPLUGIN_H
#define WINREGPLUGIN_H

#define NEED_PLUGIN_EXPORT
#include "IPlugin.h"
#include "RegWidget.h"

class WinRegPlugin : public IQtPlugin
{
private:
	RegWidget* m_pluginWidget;

public:
	WinRegPlugin();
	~WinRegPlugin();

public:
	virtual wchar_t*	getPluginName();
	virtual wchar_t*	getPluginId();
	virtual void		initPluginData(wchar_t* path);
	virtual void		resetPluginData();

	virtual QWidget*	getPluginWidget();
	virtual QImage*		getPluginIcon();
};

#endif // WINREGPLUGIN_H
