#include "MongoWidget.h"

MongoWidget::MongoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

MongoWidget::~MongoWidget()
{

}

void MongoWidget::parse(const QString& folder)
{
	QString jobInfoFile = folder + "/MongoDBDump/AppAssure/JobInfoRecords.bson";
	QString eventRecordsFile = folder + "/MongoDBDump/AppAssure/EventRecords.bson";

	ui.jobWidget->parseFile(jobInfoFile);
	ui.eventsWidget->parseFile(eventRecordsFile);
}

void MongoWidget::reset()
{
	ui.jobWidget->reset();
	ui.eventsWidget->reset();
}
