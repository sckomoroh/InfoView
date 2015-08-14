#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QList>
#include <QSettings>
#include <QLibrary>

#include "ui_MainWindow.h"

#include "LogViewForm.h"
#include "AmazonDownloadDialog.h"
#include "IPlugin.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindowClass ui;
	QList<LogViewForm*> m_logForms;
	QStringList			m_recentOpened;
	QSettings			m_applicationSettings;

	AmazonDownloadDialog* m_pDownloadDialog;

	QMap<QString, IPlugin*> m_plugins;
	QMap<QString, QAction*> m_pluginActions;
	QMap<QString, QDockWidget*> m_pluginWidgets;


public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	void updateMenu();
	void openFolder(QString folder);

	void initPlugins();
	void initPlugin(const QString& pluginFileName);
	QDockWidget* createQtPlugin(QLibrary* lib, IPlugin** plugin);

private slots:
	void onOpenAction();
	void onDownloadFromS3Action();

	void onShowSearchResultWindow();

	void onSearchAll(const QString& searchString, bool bCaseSens);

	void onSearchDoubleClicked(CustomTextViewLine* pLine);

	void onRecentClicked();
	void onLogsCompleted();

	void onPluginAction();
};

#endif // MAINWINDOW_H
