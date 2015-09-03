#ifndef MONGODBPLUGIN_H
#define MONGODBPLUGIN_H

#define NEED_PLUGIN_EXPORT
#include "IPlugin.h"

#include "MongoWidget.h"

class MongoDBPlugin : public IQtPlugin
{
private:
	MongoWidget* m_pluginWidget;

public:
	MongoDBPlugin();
	~MongoDBPlugin();

	// Implementation of the IPlugin
public:
	virtual wchar_t*	getPluginName();
	virtual wchar_t*	getPluginId();
	virtual void		initPluginData(wchar_t* path);
	virtual void		resetPluginData();

	virtual QWidget*	getPluginWidget();
	virtual QImage*		getPluginIcon();
};

#endif // MONGODBPLUGIN_H
