#ifndef SYSTEMEVENTSPLUGIN_H
#define SYSTEMEVENTSPLUGIN_H

#define NEED_PLUGIN_EXPORT
#include "IPlugin.h"
#include "SystemEventWidget.h"

class SystemEventsPlugin : public IQtPlugin
{
private:
	SystemEventWidget* m_pluginWidget;

public:
	SystemEventsPlugin();
	~SystemEventsPlugin();

public:
	virtual wchar_t*	getPluginName();
	virtual wchar_t*	getPluginId();
	virtual void		initPluginData(wchar_t* path);
	virtual void		resetPluginData();

	virtual QWidget*	getPluginWidget();
	virtual QImage*		getPluginIcon();
};

#endif // SYSTEMEVENTSPLUGIN_H
