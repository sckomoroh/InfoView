#ifndef REGISTRYVIEWWIDGET_H
#define REGISTRYVIEWWIDGET_H

#include <QWidget>
#include "ui_RegWidget.h"

#include "RegParserThread.h"
#include "RegKeyModel.h"
#include "RegValueModel.h"

class RegWidget : public QWidget
{
	Q_OBJECT
private:
	RegParserThread* m_pParserThread;
	RegKeyModel* m_pKeyModel;
	RegValueModel* m_pValuesModel;
	Ui::RegWidget ui;

public:
	RegWidget(QWidget *parent = 0);
	~RegWidget();

	void parse(const QString& folder);
	void reset();

private slots:
	void onParsingStart();
	void onParsingCompleted();

	void onKeyChanged(const QModelIndex& index, const QModelIndex& oldIndex);
	void onValueChanged(const QModelIndex& index, const QModelIndex& oldIndex);
};

#endif // REGISTRYVIEWWIDGET_H
