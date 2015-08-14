#include "RegWidget.h"

RegWidget::RegWidget(QWidget *parent)
	: QWidget(parent)
{
	m_pParserThread = new RegParserThread(this);
	m_pKeyModel = new RegKeyModel(this);
	m_pValuesModel = new RegValueModel(this);

	ui.setupUi(this);

	ui.loadingProgressBar->hide();
	ui.keysTreeView->setModel(m_pKeyModel);
	ui.valueTreeView->setModel(m_pValuesModel);

	connect(
		m_pParserThread,
		SIGNAL(parsingStarted()),
		SLOT(onParsingStart()));

	connect(
		m_pParserThread,
		SIGNAL(parsingCompleted()),
		SLOT(onParsingCompleted()));

	QItemSelectionModel* pKeySelectionModel = ui.keysTreeView->selectionModel();
	QItemSelectionModel* pValueSelectionModel = ui.valueTreeView->selectionModel();

	connect(
		pKeySelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onKeyChanged(const QModelIndex&, const QModelIndex&)));

	connect(
		pValueSelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onValueChanged(const QModelIndex&, const QModelIndex&)));
}

RegWidget::~RegWidget()
{

}

void RegWidget::reset()
{
	m_pKeyModel->reset();
	m_pValuesModel->reset();

	ui.keyLineEdit->setText("");
	ui.valueTextBrowser->setText("");
}

void RegWidget::onParsingStart()
{
	ui.loadingProgressBar->show();
}

void RegWidget::onParsingCompleted()
{
	ui.loadingProgressBar->hide();
	const RegKeyData* pRegistryKey = m_pParserThread->parser()->storage()->rootKey();
	m_pKeyModel->setModelData(pRegistryKey);
}

void RegWidget::parse(const QString& folder)
{
	m_pParserThread->setFolder(folder + "/RegistryInfo");
	m_pParserThread->start();
}

void RegWidget::onKeyChanged(const QModelIndex& index, const QModelIndex& oldIndex)
{
	RegKeyData* pKey = m_pKeyModel->rawData(index);
	m_pValuesModel->setModelData(pKey->values());

	ui.keyLineEdit->setText(pKey->fullName());

	ui.valueTreeView->resizeColumnToContents(0);
}

void RegWidget::onValueChanged(const QModelIndex& index, const QModelIndex& oldIndex)
{
	QString value = m_pValuesModel->rawData(index);
	ui.valueTextBrowser->setText(value);
}
