#ifndef EVENTVIEWWIDGET_H
#define EVENTVIEWWIDGET_H

#include <QWidget>

#include "ui_mongoeventwidget.h"

#include "MongoEventParserThread.h"
#include "MongoEventModel.h"

class MongoEventWidget : public QWidget
{
	Q_OBJECT
private:
	MongoEventModel*	m_pEventsModel;
	MongoEventParserThread* m_pEventsParserThread;

	Ui::MongoEventWidget ui;

public:
	MongoEventWidget(QWidget *parent = 0);
	~MongoEventWidget();

	void reset();
	void parseFile(const QString& fileName);

private slots:
	void onEventsStartParsing();
	void onEventsItemParsed(uint iCurrent, uint iTotal);
	void onEventsCompleteParsing();

	void onApplyButtonClicked();
};

#endif // EVENTVIEWWIDGET_H
