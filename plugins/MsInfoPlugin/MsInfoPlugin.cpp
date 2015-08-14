#include "msinfoplugin.h"

MsInfoPlugin::MsInfoPlugin()
	: m_pluginWidget(NULL)
{
}

MsInfoPlugin::~MsInfoPlugin()
{
	if (m_pluginWidget != NULL)
	{
		delete m_pluginWidget;
	}
}

QWidget* MsInfoPlugin::getPluginWidget()
{
	if (m_pluginWidget == NULL)
	{
		m_pluginWidget = new MsInfoWidget();
	}

	return m_pluginWidget;
}

wchar_t* MsInfoPlugin::getPluginName()
{
	return L"MS information";
}

wchar_t* MsInfoPlugin::getPluginId()
{
	return L"{C6763A9D-7320-4673-9ADE-3A4927168833}";
}

void MsInfoPlugin::initPluginData(wchar_t* path)
{
	QString workFolder = QString::fromWCharArray(path, wcslen(path));
	m_pluginWidget->parse(workFolder);
}

void MsInfoPlugin::resetPluginData()
{
	m_pluginWidget->reset();
}

QImage* MsInfoPlugin::getPluginIcon()
{
	return new QImage(":/plugin/images/Resources/msinfo.png");
}

IPlugin* createQtPlugin()
{
	return new MsInfoPlugin();
}

int isWin32Plugin()
{
	return 0;
}
