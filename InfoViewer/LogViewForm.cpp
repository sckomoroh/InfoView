#include "LogViewForm.h"

#include <QMessageBox>

#include "logparserthread.h"

LogViewForm::LogViewForm(int iIndex, const QString& title, QWidget *parent)
	: QWidget(parent)
	, m_iIndex(iIndex)
	, m_title(title)
	, m_bDisableSearchNavigate(false)
{
	ui.setupUi(this);
	
	m_pParserThread = new LogParserThread;
	m_pModel = new CustomTextViewModel;

	ui.logViewWidget->setModel(m_pModel);
	ui.logViewWidget->setId(iIndex);

	ui.logViewWidget->setScrollArea(ui.scrollArea);
	ui.searchToolWidget->hide();

	connect(m_pParserThread, SIGNAL(startParse()), SLOT(onStartParse()));
	connect(m_pParserThread, SIGNAL(completeParse()), SLOT(onCompleteParse()));

	connect(ui.m_applyFilterPushButton, SIGNAL(clicked()), SLOT(onApplyButtonClicked()));
	connect(ui.closePushButton, SIGNAL(clicked()), SLOT(onCloseClicked()));
	connect(ui.searchPushButton, SIGNAL(clicked()), SLOT(onSearchClicked()));
	connect(ui.searchAllPushButton, SIGNAL(clicked()), SLOT(onSearchAllClicked()));
	connect(ui.logViewWidget, SIGNAL(showSearchArea()), SLOT(onShowSearchArea()));
}

LogViewForm::~LogViewForm()
{
}

void LogViewForm::setDisableSearchNavigate(bool bDisable)
{
	m_bDisableSearchNavigate = bDisable;
}

void LogViewForm::loadFile(const QString& fileName)
{
	m_pParserThread->setFileName(fileName);
	m_pParserThread->start();
}

void LogViewForm::selectWord(uint iLine, uint iStartPos, uint iEndPos)
{
	if (!m_bDisableSearchNavigate)
	{
		ui.logViewWidget->setSelection(iLine, iStartPos, iEndPos);
	}
}

void LogViewForm::onApplyButtonClicked()
{
	m_bDisableSearchNavigate = true;

	int levelFlags = 0;

	if (ui.m_infoCheckBox->isChecked())
	{
		levelFlags |= LogType::LogTypeInformation;
	}

	if (ui.m_warnCheckBox->isChecked())
	{
		levelFlags |= LogType::LogTypeWarning;
	}

	if (ui.m_debugCheckBox->isChecked())
	{
		levelFlags |= LogType::LogTypeDebug;
	}

	if (ui.m_errorCheckBox->isChecked())
	{
		levelFlags |= LogType::LogTypeError;
	}

	QString filterString = ui.m_filterLineEdit->text();

	QList<CustomTextViewLine*> result = m_pParserThread->parser()->storage()->filteredLines(filterString, levelFlags);
	m_pModel->setModelData(result);
}

void LogViewForm::onSearchClicked()
{
	bool bSearchBack = ui.backCheckBox->isChecked();
	bool bCaseSens = ui.caseSensCheckBox->isChecked();
	QString searchString = ui.seachLineEdit->text();

	if (searchString.isEmpty() || searchString.isNull())
	{
		return;
	}

	if (!ui.logViewWidget->search(searchString, bCaseSens, bSearchBack))
	{
		QMessageBox msgBox;
		msgBox.setText("No more matches");
		msgBox.setIcon(QMessageBox::Information);
		msgBox.exec();
	}
}

void LogViewForm::onSearchAllClicked()
{
	bool bCaseSens = ui.caseSensCheckBox->isChecked();
	QString searchString = ui.seachLineEdit->text();

	emit searchAllRequest(searchString, bCaseSens);
}

void LogViewForm::onCloseClicked()
{
	ui.searchToolWidget->hide();
}

void LogViewForm::onShowSearchArea()
{
	ui.searchToolWidget->show();
}

void LogViewForm::searchAll(const QString& searchString, bool bCaseSens)
{
	m_bDisableSearchNavigate = false;
	emit searchAllComplete(ui.logViewWidget->searchAll(m_title, searchString, bCaseSens));
}

void LogViewForm::onStartParse()
{
}

void LogViewForm::onCompleteParse()
{
	m_pModel->setModelData(m_pParserThread->parser()->storage()->lines());
}
