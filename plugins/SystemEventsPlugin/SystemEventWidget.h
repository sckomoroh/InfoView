#ifndef EVENTSVIEWWIDGET_H
#define EVENTSVIEWWIDGET_H

#include <QWidget>

#include "ui_SystemEventWidget.h"

class SystemEventWidget : public QWidget
{
	Q_OBJECT
private:
	Ui::SystemEventWidget ui;

public:
	SystemEventWidget(QWidget *parent = 0);
	~SystemEventWidget();

	void parse(const QString& folderName);
	void reset();
};

#endif // EVENTSVIEWWIDGET_H
