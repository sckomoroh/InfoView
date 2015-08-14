#include "systemeventsplugin.h"

SystemEventsPlugin::SystemEventsPlugin()
	: m_pluginWidget(NULL)
{
}

SystemEventsPlugin::~SystemEventsPlugin()
{
	if (m_pluginWidget != NULL)
	{
		delete m_pluginWidget;
		m_pluginWidget = NULL;
	}
}

QWidget* SystemEventsPlugin::getPluginWidget()
{
	if (m_pluginWidget == NULL)
	{
		m_pluginWidget = new SystemEventWidget();
	}

	return m_pluginWidget;
}

wchar_t* SystemEventsPlugin::getPluginId()
{
	return L"{598B60D7-566C-473D-863B-799B775EB283}";
}

wchar_t* SystemEventsPlugin::getPluginName()
{
	return L"System events";
}

void SystemEventsPlugin::initPluginData(wchar_t* path)
{
	QString workFolder = QString::fromWCharArray(path, wcslen(path));
	m_pluginWidget->parse(workFolder);
}

void SystemEventsPlugin::resetPluginData()
{
	m_pluginWidget->reset();
}

QImage* SystemEventsPlugin::getPluginIcon()
{
	return new QImage(":/plugin/images/Resources/sysevent.png");
}

IPlugin* createQtPlugin()
{
	return new SystemEventsPlugin();
}

int isWin32Plugin()
{
	return 0;
}
