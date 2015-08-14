#include "winregplugin.h"

WinRegPlugin::WinRegPlugin()
	: m_pluginWidget(NULL)
{
}

WinRegPlugin::~WinRegPlugin()
{
	if (m_pluginWidget != NULL)
	{
		delete m_pluginWidget;
	}
}

QWidget* WinRegPlugin::getPluginWidget()
{
	if (m_pluginWidget == NULL)
	{
		m_pluginWidget = new RegWidget();
	}

	return m_pluginWidget;
}

wchar_t* WinRegPlugin::getPluginName()
{
	return L"Windows registry";
}

wchar_t* WinRegPlugin::getPluginId()
{
	return L"{59C98568-1855-4845-8B62-E518784CB41C}";
}

void WinRegPlugin::initPluginData(wchar_t* path)
{
	QString workFolder = QString::fromWCharArray(path, wcslen(path));
	m_pluginWidget->parse(workFolder);
}

void WinRegPlugin::resetPluginData()
{
	m_pluginWidget->reset();
}

QImage* WinRegPlugin::getPluginIcon()
{
	return new QImage(":/plugin/images/Resources/registry.png");
}

IPlugin* createQtPlugin()
{
	return new WinRegPlugin();
}

int isWin32Plugin()
{
	return 0;
}
