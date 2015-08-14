#include "SystemEventWidget.h"

#include <QDebug>
#include <QListWidget>

SystemEventWidget::SystemEventWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

}

SystemEventWidget::~SystemEventWidget()
{
}

void SystemEventWidget::parse(const QString& folder)
{
	ui.applicationEventsWidget->parse(folder + "/EventsLogs/Application.xml");
	ui.systemEventsWidget->parse(folder + "/EventsLogs/System.xml");
}

void SystemEventWidget::reset()
{
	ui.applicationEventsWidget->reset();
	ui.systemEventsWidget->reset();
}
