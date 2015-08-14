#ifndef MongoJobWidget_H
#define MongoJobWidget_H

#include <QWidget>

#include "ui_MongoJobWidget.h"

#include "MognoJobParserThread.h"
#include "MongoJobModel.h"

class MongoJobWidget : public QWidget
{
	Q_OBJECT
private:
	MognoJobParserThread*	m_pJobsParserThread;
	MongoJobModel*			m_pJobsModel;

	Ui::MongoJobWidget	ui;

public:
	MongoJobWidget(QWidget *parent = 0);
	~MongoJobWidget();

	void reset();
	void parseFile(const QString& fileName);

private slots:
	void onJobsStartParsing();
	void onJobsItemParsed(uint iCurrent, uint iTotal);
	void onJobsCompleteParsing();

	void onCurrentJobChanged(const QModelIndex& index, const QModelIndex& oldIndex);
	void onJodApplyFilterClick();
};

#endif // MongoJobWidget_H
