#ifndef RECOVERYPOINTSWIDGET_H
#define RECOVERYPOINTSWIDGET_H

#include <QWidget>

#include "ui_RecoveryPointsWidget.h"

#include "AgentsTreeModel.h"
#include "exchangetreemodel.h"
#include "sqltreemodel.h"
#include "RecoveryPointsParserThread.h"

class RecoveryPointsWidget : public QWidget
{
	Q_OBJECT
private:
	Ui::RecoveryPointsWidget ui;

	AgentsTreeModel*	m_pAgentsModel;
	SqlTreeModel*		m_pSqlTreeModel;
	ExchangeTreeModel*	m_pExchangeTreeModel;

	RecoveryPointsParserThread			m_parserThread;

public:
	RecoveryPointsWidget(QWidget *parent = 0);
	~RecoveryPointsWidget();

	void clearUiControls();

	void parse(const QString& folder);
	void reset();

private slots:
	void onAgentCurrentChanged(const QModelIndex&, const QModelIndex&);
	void onExchangeCurrentChanged(const QModelIndex&, const QModelIndex&);
	void onSqlCurrentChanged(const QModelIndex&, const QModelIndex&);

	void onStartParsing();
	void onCompleteParsing();
	void onAgentParsed(uint current, uint total);
	void onRecoveryPointParsed(uint current, uint total);
};

#endif // RECOVERYPOINTSWIDGET_H
