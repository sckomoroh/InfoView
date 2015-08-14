#ifndef RECOVERYPOINTSPLUGIN_H
#define RECOVERYPOINTSPLUGIN_H

#include "IPlugin.h"
#include "RecoveryPointsWidget.h"

class RecoveryPointsPlugin : public IQtPlugin
{
private:
	RecoveryPointsWidget* m_pluginWidget;

public:
	RecoveryPointsPlugin();
	~RecoveryPointsPlugin();

public:
	virtual wchar_t*	getPluginName();
	virtual wchar_t*	getPluginId();
	virtual void		initPluginData(wchar_t* path);
	virtual void		resetPluginData();

public:
	virtual QWidget*	getPluginWidget();
	virtual QImage*		getPluginIcon();
};

#endif // RECOVERYPOINTSPLUGIN_H
