#ifndef SEARCHRESULTWIDGET_H
#define SEARCHRESULTWIDGET_H

#include <QWidget>
#include "ui_SearchResultWidget.h"

#include "CustomTextViewModel.h"

class SearchResultWidget : public QWidget
{
	Q_OBJECT
private:
	CustomTextViewModel* m_pModel;

public:
	SearchResultWidget(QWidget *parent = 0);
	~SearchResultWidget();

private:
	Ui::SearchResultWidget ui;

public slots:
	void onSeachResult(QList<CustomTextViewSearchLine*> searchStrings);
	void clearResults();

private slots:
	void onDoubleClicked(CustomTextViewLine* pLine);
	void onClearResults();

signals:
	void doubleCLicked(CustomTextViewLine* pLine);
};

#endif // SEARCHRESULTWIDGET_H
