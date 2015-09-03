#ifndef MSINFOWIDGET_H
#define MSINFOWIDGET_H

#include <QWidget>
#include "ui_msinfowidget.h"

#include "MsInfoParserThread.h"
#include "MsInfoCategoryModel.h"
#include "MsInfoDetailModel.h"

class MsInfoWidget : public QWidget
{
	Q_OBJECT
private:
	MsInfoParserThread*		m_pThread;
	MsInfoCategoryModel*	m_pCategoriesModel;
	MsInfoDetailModel*		m_pDetailModel;
	Ui::MsInfoWidget		ui;

public:
	MsInfoWidget(QWidget *parent = 0);
	~MsInfoWidget();

	void parse(const QString& fileName);
	void reset();

private:

private slots :
	void onParsingStart();
	void onParsingComplete();

	void onCategoryChanged(const QModelIndex& index, const QModelIndex& oldIndex);
	void onValueChanged(const QModelIndex& index, const QModelIndex& oldIndex);
};

#endif // MSINFOWIDGET_H
