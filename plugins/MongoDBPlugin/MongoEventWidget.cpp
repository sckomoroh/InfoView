#include "MongoEventWidget.h"

#include <QImage>

MongoEventWidget::MongoEventWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_pEventsParserThread = new MongoEventParserThread(this);
	m_pEventsModel = new MongoEventModel(m_pEventsParserThread->parser()->storage(), this);

	ui.treeView->setModel(m_pEventsModel);
	ui.loadingProgressBar->hide();

	connect(
		m_pEventsParserThread,
		SIGNAL(startParsing()),
		SLOT(onEventsStartParsing()));

	connect(
		m_pEventsParserThread,
		SIGNAL(itemParsed(uint, uint)),
		SLOT(onEventsItemParsed(uint, uint)));

	connect(
		m_pEventsParserThread,
		SIGNAL(completeParsing()),
		SLOT(onEventsCompleteParsing()));

	connect(
		ui.applyPushButton,
		SIGNAL(clicked()),
		SLOT(onApplyButtonClicked()));
}

MongoEventWidget::~MongoEventWidget()
{

}

void MongoEventWidget::reset()
{
	ui.infoCheckBox->setChecked(true);
	ui.warningCheckBox->setChecked(true);
	ui.errorCheckBox->setChecked(true);
	ui.alertsCheckBox->setChecked(true);
	ui.eventsCheckBox->setChecked(true);

	ui.filterLineEdit->setText("");
}

void MongoEventWidget::parseFile(const QString& fileName)
{
	m_pEventsParserThread->setFileName(fileName);
	m_pEventsParserThread->start();
}

void MongoEventWidget::onEventsStartParsing()
{
	ui.loadingProgressBar->show();
}

void MongoEventWidget::onEventsItemParsed(uint iCurrent, uint iTotal)
{
	ui.loadingProgressBar->setMaximum(iTotal);
	ui.loadingProgressBar->setValue(iCurrent);
}

void MongoEventWidget::onEventsCompleteParsing()
{
	ui.loadingProgressBar->hide();

	ui.treeView->resizeColumnToContents(0);
}

void MongoEventWidget::onApplyButtonClicked()
{
	QList<MongoEventData*> result;
	QString filterString = ui.filterLineEdit->text();

	int iFilteredFlags = 0;
	if (ui.alertsCheckBox->isChecked())
	{
		iFilteredFlags |= MongoEventData::EventAlert;
	}

	if (ui.errorCheckBox->isChecked())
	{
		iFilteredFlags |= MongoEventData::EventError;
	}

	if (ui.eventsCheckBox->isChecked())
	{
		iFilteredFlags |= MongoEventData::EventEvent;
	}

	if (ui.infoCheckBox->isChecked())
	{
		iFilteredFlags |= MongoEventData::EventInformation;
	}

	if (ui.warningCheckBox->isChecked())
	{
		iFilteredFlags |= MongoEventData::EventWarning;
	}

	m_pEventsParserThread->parser()->storage()->filterEvents(filterString, iFilteredFlags);
}
