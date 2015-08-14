#ifndef MSINFOPLUGIN_H
#define MSINFOPLUGIN_H

#include "IPlugin.h"
#include "MsInfoWidget.h"

class MsInfoPlugin : public IQtPlugin
{
private:
	MsInfoWidget* m_pluginWidget;

public:
	MsInfoPlugin();
	~MsInfoPlugin();

	// Implementation of the IPlugin
public:
	virtual wchar_t*	getPluginName();
	virtual wchar_t*	getPluginId();
	virtual void		initPluginData(wchar_t* path);
	virtual void		resetPluginData();

	virtual QWidget*	getPluginWidget();
	virtual QImage*		getPluginIcon() ;
};

#endif // MSINFOPLUGIN_H
