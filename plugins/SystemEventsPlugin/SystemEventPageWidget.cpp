#include "SystemEventPageWidget.h"

#include <QMenu>

SystemEventPageWidget::SystemEventPageWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_pParserThread = new SystemEventParserThread(this);
	m_pModel = new SystemEventModel(m_pParserThread->parser()->storage(), this);
	m_pProvidersModel = new ProviderModel(this);
	m_pParserThread->parser()->addListener(m_pParserThread->parser()->storage());

	ui.parsingProgressBar->hide();
	ui.eventsTreeView->setModel(m_pModel);
	ui.providersListView->setModel(m_pProvidersModel);

	ui.eventsTreeView->setContextMenuPolicy(Qt::CustomContextMenu);

	QItemSelectionModel* pJobTreeSelectionModel = ui.eventsTreeView->selectionModel();
	QItemSelectionModel* pProvidersSelectionModel = ui.providersListView->selectionModel();

	connect(
		m_pParserThread,
		SIGNAL(eventStartParsing()),
		SLOT(onParsingStarted()));

	connect(
		m_pParserThread,
		SIGNAL(eventParsed(uint, uint)),
		SLOT(onEventParsed(uint, uint)));

	connect(
		m_pParserThread,
		SIGNAL(eventCompleteParsing()),
		SLOT(onParsingCompletes()));

	connect(
		pJobTreeSelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onCurrentJobChanged(const QModelIndex&, const QModelIndex&)));

	connect(
		pProvidersSelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onCurrentProviderChanged(const QModelIndex&, const QModelIndex&)));

	connect(
		ui.applyPushButton,
		SIGNAL(clicked()),
		SLOT(onFilterApplyClicked()));

	connect(
		ui.eventsTreeView, 
		SIGNAL(customContextMenuRequested(QPoint)), 
		SLOT(onTableContextMenu(QPoint)));

	connect(
		ui.selectAllPushButton,
		SIGNAL(clicked()),
		SLOT(onSelectAllProviders()));

	connect(
		ui.selectNonePushButton,
		SIGNAL(clicked()),
		SLOT(onUnselectAllProviders()));
}

SystemEventPageWidget::~SystemEventPageWidget()
{
	delete m_pModel;
	delete m_pProvidersModel;
	delete m_pParserThread;
}

void SystemEventPageWidget::parse(const QString& fileName)
{
	m_pParserThread->setFileName(fileName);
	m_pParserThread->start();
}

void SystemEventPageWidget::onParsingStarted()
{
	ui.parsingProgressBar->show();
}

void SystemEventPageWidget::onEventParsed(uint iCurrent, uint iTotal)
{
	ui.parsingProgressBar->setMaximum(iTotal);
	ui.parsingProgressBar->setValue(iCurrent);
}

void SystemEventPageWidget::onParsingCompletes()
{
	ui.parsingProgressBar->hide();

	m_pProvidersModel->setModelData(m_pParserThread->parser()->storage()->providersNames());

	ui.eventsTreeView->resizeColumnToContents(1);
}

void SystemEventPageWidget::onCurrentJobChanged(const QModelIndex& index, const QModelIndex& oldIndex)
{
	SystemEventData* pRecord = m_pModel->rawData(index);

	if (pRecord == NULL)
	{
		return;
	}

	ui.sourceLineEdit->setText(pRecord->providerName());
	ui.creationTimeLineEdit->setText(pRecord->creationTime().toString("yyyy-MM-dd hh:mm"));
	ui.descriptionTextBrowser->setText(pRecord->description());
}

void SystemEventPageWidget::onCurrentProviderChanged(const QModelIndex& index, const QModelIndex& oldIndex)
{
	if (!index.isValid())
	{
		return;
	}

	ProviderData* pProvider = m_pProvidersModel->rawData(index);

	if (pProvider == NULL)
	{
		return;
	}

	m_pProvidersModel->inverseProvider(index);
	pProvider = m_pProvidersModel->rawData(index);
}

void SystemEventPageWidget::onFilterApplyClicked()
{
	int iEventsLevel = 0;
	if (ui.debugCheckBox->isChecked())
	{
		iEventsLevel |= SystemEventStorage::Verbose;
	}
	if (ui.errorCheckBox->isChecked())
	{
		iEventsLevel |= SystemEventStorage::Error;
	}
	if (ui.warnCheckBox->isChecked())
	{
		iEventsLevel |= SystemEventStorage::Warning;
	}
	if (ui.infoCheckBox->isChecked())
	{
		iEventsLevel |= SystemEventStorage::Information;
	}
	if (ui.fatalCheckBox->isChecked())
	{
		iEventsLevel |= SystemEventStorage::Critical;
	}

	QList<int> eventIdsList;
	QString eventIdsStr = ui.eventIdLineEdit->text();
	QStringList eventIds = eventIdsStr.split(",");
	QStringList providers = m_pProvidersModel->enabledProviders();

	for each (QString strEventId in eventIds)
	{
		int eventId = strEventId.toInt();

		if (eventId)
		{
			eventIdsList.append(eventId);
		}
	}

	m_pParserThread->parser()->storage()->filterRecords(eventIdsList, providers, iEventsLevel);
}

void SystemEventPageWidget::reset()
{
	m_pProvidersModel->reset();
	m_pModel->reset();

	ui.eventIdLineEdit->setText("");
	ui.creationTimeLineEdit->setText("");
	ui.sourceLineEdit->setText("");
	ui.descriptionTextBrowser->setText("");

	ui.errorCheckBox->setChecked(true);
	ui.debugCheckBox->setChecked(true);
	ui.warnCheckBox->setChecked(true);
	ui.infoCheckBox->setChecked(true);
	ui.fatalCheckBox->setChecked(true);
}

void SystemEventPageWidget::onTableContextMenu(QPoint point)
{
	QAction* pIncludeAction = new QAction("Include event ID", this);
	QAction* pExcludeAction = new QAction("Exclude event ID", this);

	connect(
		pIncludeAction,
		SIGNAL(triggered()),
		SLOT(onIncludeEvent()));

	connect(
		pExcludeAction,
		SIGNAL(triggered()),
		SLOT(onExcludeEvent()));

	QMenu *pMenu = new QMenu(this);
	pMenu->addAction(pIncludeAction);
	pMenu->addAction(pExcludeAction);
	pMenu->popup(ui.eventsTreeView->viewport()->mapToGlobal(point));
}

void SystemEventPageWidget::onIncludeEvent()
{
	QModelIndex index = ui.eventsTreeView->currentIndex();
	SystemEventData* pEvent = m_pModel->rawData(index);
	if (pEvent == NULL)
	{
		return;
	}

	int iEventId = pEvent->eventId();
	QString eventIds = ui.eventIdLineEdit->text();
	ui.eventIdLineEdit->setText(eventIdString(eventIds, iEventId));
}

void SystemEventPageWidget::onExcludeEvent()
{
	QModelIndex index = ui.eventsTreeView->currentIndex();
	SystemEventData* pEvent = m_pModel->rawData(index);
	if (pEvent == NULL)
	{
		return;
	}

	int iEventId = -pEvent->eventId();
	QString eventIds = ui.eventIdLineEdit->text();
	ui.eventIdLineEdit->setText(eventIdString(eventIds, iEventId));
}

QString SystemEventPageWidget::eventIdString(const QString& eventIds, int iEventId)
{
	QString result = "";
	QStringList eventIdList = eventIds.split(",");
	for each (QString eventId in eventIdList)
	{
		if (eventId.isEmpty())
		{
			continue;
		}

		int iCurrentEventId = eventId.toInt();
		if (iEventId == -iCurrentEventId || iEventId == iCurrentEventId)
		{
			continue;
		}

		result += QString::number(iCurrentEventId) + ",";
	}

	result += QString::number(iEventId);

	return result;
}

void SystemEventPageWidget::onSelectAllProviders()
{
	m_pProvidersModel->selectAll();
}

void SystemEventPageWidget::onUnselectAllProviders()
{
	m_pProvidersModel->unselectAll();
}
