#ifndef MongoWidget_H
#define MongoWidget_H

#include <QWidget>
#include "ui_MongoWidget.h"

class MongoWidget : public QWidget
{
	Q_OBJECT
private:
	Ui::MongoWidget ui;

public:
	MongoWidget(QWidget *parent = 0);
	~MongoWidget();

	void parse(const QString& folder);
	void reset();
};

#endif // MongoWidget_H
