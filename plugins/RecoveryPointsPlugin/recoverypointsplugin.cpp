#include "recoverypointsplugin.h"

RecoveryPointsPlugin::RecoveryPointsPlugin()
	: m_pluginWidget(NULL)
{
}

RecoveryPointsPlugin::~RecoveryPointsPlugin()
{
	if (m_pluginWidget != NULL)
	{
		delete m_pluginWidget;
	}
}

QWidget* RecoveryPointsPlugin::getPluginWidget()
{
	if (m_pluginWidget == NULL)
	{
		m_pluginWidget = new RecoveryPointsWidget();
	}

	return m_pluginWidget;
}

wchar_t* RecoveryPointsPlugin::getPluginId()
{
	return L"{D8ACC7F9-6729-4A7E-B3D9-FE1CA2E13E07}";
}

wchar_t* RecoveryPointsPlugin::getPluginName()
{
	return L"Recovery points";
}

void RecoveryPointsPlugin::initPluginData(wchar_t* path)
{
	QString workFolder = QString::fromWCharArray(path, wcslen(path));
	m_pluginWidget->parse(workFolder);
}

void RecoveryPointsPlugin::resetPluginData()
{
	m_pluginWidget->reset();
}

QImage* RecoveryPointsPlugin::getPluginIcon()
{
	return new QImage(":/plugin/images/Resources/rp.png");
}

IPlugin* createQtPlugin()
{
	return new RecoveryPointsPlugin();
}

int isWin32Plugin()
{
	return 0;
}
