#include "mongodbplugin.h"

MongoDBPlugin::MongoDBPlugin()
	: m_pluginWidget(NULL)
{
}

MongoDBPlugin::~MongoDBPlugin()
{
	if (m_pluginWidget != NULL)
	{
		delete m_pluginWidget;
	}
}

QWidget* MongoDBPlugin::getPluginWidget()
{
	if (m_pluginWidget == NULL)
	{
		m_pluginWidget = new MongoWidget();
	}

	return m_pluginWidget;
}

wchar_t* MongoDBPlugin::getPluginName()
{
	return L"Mongo database";
}

void MongoDBPlugin::initPluginData(wchar_t* path)
{
	QString workFolder = QString::fromWCharArray(path, wcslen(path));
	m_pluginWidget->parse(workFolder);
}

void MongoDBPlugin::resetPluginData()
{
	m_pluginWidget->reset();
}

wchar_t* MongoDBPlugin::getPluginId()
{
	return L"{AA0EFD7F-2432-479A-9015-8BC809407AC8}";
}

QImage* MongoDBPlugin::getPluginIcon()
{
	return new QImage(":/plugin/images/Resources/mongo.png");
}

IPlugin* createQtPlugin()
{
	return new MongoDBPlugin();
}

int isWin32Plugin()
{
	return 0;
}
