#include "RecoveryPointsWidget.h"

RecoveryPointsWidget::RecoveryPointsWidget(QWidget *parent)
	: QWidget(parent)
	, m_pAgentsModel(NULL)
	, m_pSqlTreeModel(NULL)
	, m_pExchangeTreeModel(NULL)
	, m_parserThread(this)
{
	ui.setupUi(this);

	ui.folderProgressBar->hide();
	ui.agentProgressBar->hide();

	m_pExchangeTreeModel = new ExchangeTreeModel(this);
	m_pSqlTreeModel = new SqlTreeModel(this);
	m_pAgentsModel = new AgentsTreeModel(this);

	ui.exchangeTreeView->setModel(m_pExchangeTreeModel);
	ui.sqlTreeView->setModel(m_pSqlTreeModel);
	ui.treeView->setModel(m_pAgentsModel);

	QItemSelectionModel* pExchangeSelectionModel = ui.exchangeTreeView->selectionModel();
	QItemSelectionModel* pSqlSelectionModel = ui.sqlTreeView->selectionModel();
	QItemSelectionModel* pAgentsSelectionModel = ui.treeView->selectionModel();

	connect(
		pAgentsSelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onAgentCurrentChanged(const QModelIndex&, const QModelIndex&)));

	connect(
		pExchangeSelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onExchangeCurrentChanged(const QModelIndex&, const QModelIndex&)));

	connect(
		pSqlSelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onSqlCurrentChanged(const QModelIndex&, const QModelIndex&)));

	connect(
		&m_parserThread,
		SIGNAL(parsingStarted()),
		SLOT(onStartParsing()));

	connect(
		&m_parserThread,
		SIGNAL(parsingCompleted()),
		SLOT(onCompleteParsing()));

	connect(
		&m_parserThread,
		SIGNAL(agentParsed(uint, uint)),
		SLOT(onAgentParsed(uint, uint)));

	connect(
		&m_parserThread,
		SIGNAL(recoveryPointParsed(uint, uint)),
		SLOT(onRecoveryPointParsed(uint, uint)));
}

RecoveryPointsWidget::~RecoveryPointsWidget()
{

}

void RecoveryPointsWidget::onAgentCurrentChanged(const QModelIndex& current, const QModelIndex&)
{
	clearUiControls();

	QString selectedText = m_pAgentsModel->data(current, Qt::DisplayRole).toString();
	ui.recoveryPointLineEdit->setText(selectedText);

	BaseModelItem* pModelItem = m_pAgentsModel->dataItem(current);
	VolumeModelItem* pVolumeModelItem = dynamic_cast<VolumeModelItem*>(pModelItem);
	if (pVolumeModelItem != NULL)
	{
		RecoveryPointModelItem* pRecoveryPointItem = (RecoveryPointModelItem*)pVolumeModelItem->parent();
		ui.rpIdLineEdit->setText(pRecoveryPointItem->id());

		AgentModelItem* pAgentItem = (AgentModelItem*)pRecoveryPointItem->parent();
		ui.agentIdLineEdit->setText(pAgentItem->id());

		ui.prevEpochLineEdit->setText(QString("%1").arg(pVolumeModelItem->previousEpochNumber()));
		ui.volumeIdLineEdit->setText(pVolumeModelItem->volumeId());

		if (pVolumeModelItem->exchange())
		{
			ui.exchangeVersionLabel->setText(pVolumeModelItem->exchange()->version());
			ui.exchangeNameLabel->setText(pVolumeModelItem->exchange()->displayName());
			m_pExchangeTreeModel->buildModel(pVolumeModelItem->exchange());
			ui.exchangeTreeView->reset();
		}

		if (pVolumeModelItem->sqlInstances().count() > 0)
		{
			m_pSqlTreeModel->buildModel(pVolumeModelItem->sqlInstances());
			ui.sqlTreeView->reset();
		}

		return;
	}

	RecoveryPointModelItem* pRecoveryPointItem = dynamic_cast<RecoveryPointModelItem*>(pModelItem);
	if (pRecoveryPointItem != NULL)
	{
		ui.rpIdLineEdit->setText(pRecoveryPointItem->id());

		AgentModelItem* pAgentItem = (AgentModelItem*)pRecoveryPointItem->parent();
		ui.agentIdLineEdit->setText(pAgentItem->id());

		return;
	}

	AgentModelItem* pAgentItem = dynamic_cast<AgentModelItem*>(pModelItem);
	if (pAgentItem != NULL)
	{
		ui.agentIdLineEdit->setText(pAgentItem->id());
	}
}

void RecoveryPointsWidget::reset()
{
	clearUiControls();

	if (m_pAgentsModel != NULL)
	{
		m_pAgentsModel->reset();
	}
}

void RecoveryPointsWidget::clearUiControls()
{
	ui.agentIdLineEdit->setText("NO AGENT ID");
	ui.rpIdLineEdit->setText("NO RECOVERY POINT");
	ui.prevEpochLineEdit->setText("NO PREVIOUS EPOCH");
	ui.volumeIdLineEdit->setText("NO VOLUME ID");
	ui.exchangeVersionLabel->setText("NO EXCHANGE");
	ui.exchangeNameLabel->setText("NO EXCHANGE");
	ui.recoveryPointLineEdit->setText("");
	ui.exchageLineEdit->setText("");

	if (m_pExchangeTreeModel)
	{
		m_pExchangeTreeModel->reset();
	}

	if (m_pSqlTreeModel)
	{
		m_pSqlTreeModel->reset();
	}
}

void RecoveryPointsWidget::parse(const QString& folder)
{
	m_parserThread.setFolder(folder + "/RecoveryPoints");
	m_parserThread.start();
}

void RecoveryPointsWidget::onExchangeCurrentChanged(const QModelIndex& current, const QModelIndex&)
{
	if (!current.isValid())
	{
		return;
	}

	if (m_pExchangeTreeModel != NULL)
	{
		QString selectionText = m_pExchangeTreeModel->data(current, Qt::DisplayRole).toString();
		ui.exchageLineEdit->setText(selectionText);
	}
}

void RecoveryPointsWidget::onSqlCurrentChanged(const QModelIndex& current, const QModelIndex&)
{
	if (!current.isValid())
	{
		return;
	}

	if (m_pSqlTreeModel != NULL)
	{
		QString selectionText = m_pSqlTreeModel->data(current, Qt::DisplayRole).toString();
		ui.sqlLineEdit->setText(selectionText);
	}
}

void RecoveryPointsWidget::onStartParsing()
{
	ui.folderProgressBar->show();
	ui.agentProgressBar->show();
}

void RecoveryPointsWidget::onCompleteParsing()
{
	ui.folderProgressBar->hide();
	ui.agentProgressBar->hide();
	m_pAgentsModel->setRootItem(m_parserThread.parser()->storage()->rootItem());

	ui.treeView->resizeColumnToContents(0);
}

void RecoveryPointsWidget::onAgentParsed(uint current, uint total)
{
	ui.agentProgressBar->setMaximum(total);
	ui.agentProgressBar->setValue(current);
}

void RecoveryPointsWidget::onRecoveryPointParsed(uint current, uint total)
{
	ui.folderProgressBar->setMaximum(total);
	ui.folderProgressBar->setValue(current);
}

