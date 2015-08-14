#include "MongoJobWidget.h"

MongoJobWidget::MongoJobWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_pJobsModel = new MongoJobModel(this);
	ui.jobsTreeView->setModel(m_pJobsModel);

	ui.loadingProgressBar->hide();

	m_pJobsParserThread = new MognoJobParserThread(this);

	connect(
		m_pJobsParserThread,
		SIGNAL(startParsing()),
		SLOT(onJobsStartParsing()));

	connect(
		m_pJobsParserThread,
		SIGNAL(itemParsed(uint, uint)),
		SLOT(onJobsItemParsed(uint, uint)));

	connect(
		m_pJobsParserThread,
		SIGNAL(completeParsing()),
		SLOT(onJobsCompleteParsing()));

	connect(
		ui.applyFilterPushButton,
		SIGNAL(clicked()),
		SLOT(onJodApplyFilterClick()));

	QItemSelectionModel* pJobTreeSelectionModel = ui.jobsTreeView->selectionModel();

	connect(
		pJobTreeSelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onCurrentJobChanged(const QModelIndex&, const QModelIndex&)));
}

MongoJobWidget::~MongoJobWidget()
{
}

void MongoJobWidget::reset()
{
	ui.serviceJobCheckBox->setChecked(true);
	ui.userJobCheckBox->setChecked(true);
	ui.successCheckBox->setChecked(true);
	ui.cancelCheckBox->setChecked(true);
	ui.failCheckBox->setChecked(true);

	ui.filterLineEdit->setText("");
	
	ui.summaryLineEdit->setText("");
	ui.idLineEdit->setText("");
	ui.statusLineEdit->setText("");
	ui.phaseLineEdit->setText("");
	ui.creationLineEdit->setText("");
	ui.startLineEdit->setText("");
	ui.endLineEdit->setText("");
	ui.errorDetailsTextBrowser->setText("");
	ui.errorStackTextBrowser->setText("");

	m_pJobsModel->reset();
}

void MongoJobWidget::parseFile(const QString& fileName)
{
	m_pJobsParserThread->setFileName(fileName);
	m_pJobsParserThread->start();
}

void MongoJobWidget::onJodApplyFilterClick()
{
	QString filterString = ui.filterLineEdit->text();
	int iJobTypeFlags = 0;

	if (ui.serviceJobCheckBox->isChecked())
	{
        iJobTypeFlags |= MongoJobType::mjtServiceJob;
	}

	if (ui.userJobCheckBox->isChecked())
	{
        iJobTypeFlags |= MongoJobType::mjtUserJob;
	}

	if (ui.successCheckBox->isChecked())
	{
        iJobTypeFlags |= MongoJobType::mjtSuccess;
	}

	if (ui.cancelCheckBox->isChecked())
	{
        iJobTypeFlags |= MongoJobType::mjtCancel;
	}

	if (ui.failCheckBox->isChecked())
	{
        iJobTypeFlags |= MongoJobType::mjtFail;
	}

	m_pJobsModel->setModelData(m_pJobsParserThread->parser()->storage()->filteredJob((MongoJobType)iJobTypeFlags, filterString));
}

void MongoJobWidget::onCurrentJobChanged(const QModelIndex& index, const QModelIndex& oldIndex)
{
	MongoJobData* pJobObject = m_pJobsModel->rawData(index);

	QString jobStatus;
    if (pJobObject->jobType() & MongoJobType::mjtSuccess)
	{
		jobStatus = "Succeeded";
	}
    else if (pJobObject->jobType() & MongoJobType::mjtFail)
	{
		jobStatus = "Failed";
	}
    else if (pJobObject->jobType() & MongoJobType::mjtCancel)
	{
		jobStatus = "Canceled";
	} 
	else
	{
		jobStatus = "Unknown";
	}

	ui.errorDetailsTextBrowser->setText(pJobObject->errorMessage() + "\r\n" + pJobObject->errorDetails());
	ui.errorStackTextBrowser->setText(pJobObject->errorStackTrace());

	ui.summaryLineEdit->setText(pJobObject->summary());
	ui.idLineEdit->setText(pJobObject->id());
	ui.statusLineEdit->setText(jobStatus);
	ui.phaseLineEdit->setText(pJobObject->phase());
	ui.creationLineEdit->setText(pJobObject->creationTime().toString("yyyy-MM-dd hh:mm"));
	ui.startLineEdit->setText(pJobObject->startTime().toString("yyyy-MM-dd hh:mm"));
	ui.endLineEdit->setText(pJobObject->endTime().toString("yyyy-MM-dd hh:mm"));
}

void MongoJobWidget::onJobsStartParsing()
{
	ui.loadingProgressBar->setMaximum(100);
	ui.loadingProgressBar->setValue(0);
	ui.loadingProgressBar->show();
}

void MongoJobWidget::onJobsItemParsed(uint iCurrent, uint iTotal)
{
	ui.loadingProgressBar->setMaximum(iTotal);
	ui.loadingProgressBar->setValue(iCurrent);
}

void MongoJobWidget::onJobsCompleteParsing()
{
	m_pJobsModel->setModelData(m_pJobsParserThread->parser()->storage()->jobs());
	ui.loadingProgressBar->hide();

	ui.jobsTreeView->resizeColumnToContents(0);
}
