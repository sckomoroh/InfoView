#ifndef SYSTEMEVENTPAGEWIDGET_H
#define SYSTEMEVENTPAGEWIDGET_H

#include <QWidget>
#include "ui_SystemEventPageWidget.h"

#include "SystemEventParserThread.h"
#include "SystemEventModel.h"
#include "ProviderModel.h"

class SystemEventPageWidget : public QWidget
{
	Q_OBJECT
private:
	Ui::SystemEventPageWidget	ui;
	SystemEventModel*			m_pModel;
	ProviderModel*				m_pProvidersModel;
	SystemEventParserThread*	m_pParserThread;

public:
	SystemEventPageWidget(QWidget *parent = 0);
	~SystemEventPageWidget();

	void parse(const QString& fileName);
	void reset();

private:
	QString eventIdString(const QString& eventIds, int iEventId);
	
private slots:
	void onParsingStarted();
	void onEventParsed(uint iCurent, uint iTotal);
	void onParsingCompletes();

	void onCurrentJobChanged(const QModelIndex& index, const QModelIndex& oldIndex);
	void onCurrentProviderChanged(const QModelIndex& index, const QModelIndex& oldIndex);

	void onFilterApplyClicked();

	void onTableContextMenu(QPoint point);

	void onIncludeEvent();
	void onExcludeEvent();

	void onSelectAllProviders();
	void onUnselectAllProviders();
};

#endif // SYSTEMEVENTPAGEWIDGET_H
