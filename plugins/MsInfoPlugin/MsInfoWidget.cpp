#include "msinfowidget.h"

MsInfoWidget::MsInfoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_pCategoriesModel = new MsInfoCategoryModel(this);
	m_pDetailModel = new MsInfoDetailModel(this);
	m_pThread = new MsInfoParserThread(this);

	ui.categoriesTreeView->setModel(m_pCategoriesModel);
	ui.valuesTreeView->setModel(m_pDetailModel);

	ui.parsingProgressBar->hide();

	connect(
		m_pThread,
		SIGNAL(parsingStart()),
		SLOT(onParsingStart()));

	connect(
		m_pThread,
		SIGNAL(parsingComplete()),
		SLOT(onParsingComplete()));

	QItemSelectionModel* pCategorySelectionModel = ui.categoriesTreeView->selectionModel();
	connect(
		pCategorySelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onCategoryChanged(const QModelIndex&, const QModelIndex&)));

	QItemSelectionModel* pValueSelectionModel = ui.valuesTreeView->selectionModel();
	connect(
		pValueSelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onValueChanged(const QModelIndex&, const QModelIndex&)));
}

MsInfoWidget::~MsInfoWidget()
{
}

void MsInfoWidget::parse(const QString& fileName)
{
	m_pThread->setFileName(fileName + "/msinfo.nfo");
	m_pThread->start();
}

void MsInfoWidget::reset()
{
	m_pCategoriesModel->reset();
	m_pDetailModel->reset();

	ui.categoryLineEdit->setText("");
	ui.valueLineEdit->setText("");
}

void MsInfoWidget::onParsingStart()
{
	ui.parsingProgressBar->show();
}

void MsInfoWidget::onParsingComplete()
{
	ui.parsingProgressBar->hide();

	const MsInfoCategory* pRootCategory = m_pThread->parser()->storage()->rootCategory();

	m_pCategoriesModel->setRootCategory(pRootCategory);
}

void MsInfoWidget::onCategoryChanged(const QModelIndex& index, const QModelIndex& oldIndex)
{
	if (index.isValid())
	{
		MsInfoCategory* pCategory = m_pCategoriesModel->rawData(index);

		if (pCategory != NULL)
		{
			ui.categoryLineEdit->setText(pCategory->categoryName());
			m_pDetailModel->setCategory(pCategory);
		}
	}

	ui.valueLineEdit->setText("");
}

void MsInfoWidget::onValueChanged(const QModelIndex& index, const QModelIndex& oldIndex)
{
	if (index.isValid())
	{
		QString value = m_pDetailModel->data(index).toString();
		ui.valueLineEdit->setText(value);
		return;
	}

	ui.valueLineEdit->setText("");
}
