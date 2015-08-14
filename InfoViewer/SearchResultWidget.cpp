#include "SearchResultWidget.h"

#include "CustomTextViewLine.h"
#include "SearchLineData.h"

SearchResultWidget::SearchResultWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_pModel = new CustomTextViewModel;
	ui.searchResultViewWidget->setModel(m_pModel);
	ui.searchResultViewWidget->setScrollArea(ui.searchScrollArea);
	ui.searchResultViewWidget->setSelectOnDoubleClick(false);
	ui.searchResultViewWidget->setHighlightWords(false);

	connect(ui.searchResultViewWidget, SIGNAL(doubleClicked(CustomTextViewLine*)), SLOT(onDoubleClicked(CustomTextViewLine*)));
	connect(ui.clearPushButton, SIGNAL(clicked()), SLOT(onClearResults()));
}

SearchResultWidget::~SearchResultWidget()
{
	delete m_pModel;
}

void SearchResultWidget::clearResults()
{
	m_pModel->clear();
}

void SearchResultWidget::onSeachResult(QList<CustomTextViewSearchLine*> searchStrings)
{
	QList<CustomTextViewLine*> lines;

	for each (CustomTextViewSearchLine* pSearchString in searchStrings)
	{
		CustomTextViewLine* pLine = new SearchLineData(pSearchString, pSearchString->isTitle());
		lines.append(pLine);

		delete pSearchString;
	}

	m_pModel->appendModelData(lines);
}

void SearchResultWidget::onDoubleClicked(CustomTextViewLine* pLine)
{
	emit doubleCLicked(pLine);
}

void SearchResultWidget::onClearResults()
{
	m_pModel->clear();
}
