	#include "MainWindow.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QAction>
#include <QMessageBox>
#include <QDomDocument>
#include <QtWin>

#include "SearchLineData.h"

#include "FileLogger.h"
#include "LogManager.h"

#define RECENT_OPENED_NAME "recentOpened"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, m_applicationSettings(QSettings::NativeFormat, QSettings::UserScope, "SelfProduction", "Info view")
{
	ILogger* pFileLogger = new CFileLogger("SFInfoView.log");
	CLogger::RegisterLogger("FILE", pFileLogger);

	ui.setupUi(this);

	m_pDownloadDialog = new AmazonDownloadDialog(this);

	m_recentOpened = m_applicationSettings.value(RECENT_OPENED_NAME).toStringList();
	if (!m_recentOpened.isEmpty())
	{
		updateMenu();
	}

	ui.searchResultDockWidget->hide();

	connect(ui.actionDownloadFromS3,			SIGNAL(triggered()), SLOT(onDownloadFromS3Action()));
	connect(ui.actionOpen,						SIGNAL(triggered()), SLOT(onOpenAction()));
	connect(ui.actionShowSearchResultWindow,	SIGNAL(triggered()), SLOT(onShowSearchResultWindow()));
	connect(ui.searchResultWidget, SIGNAL(doubleCLicked(CustomTextViewLine*)), SLOT(onSearchDoubleClicked(CustomTextViewLine*)));
	connect(m_pDownloadDialog, SIGNAL(logsCompleted()), SLOT(onLogsCompleted()));

	initPlugins();
	initActiveXPlugins();
}

MainWindow::~MainWindow()
{
	delete m_pDownloadDialog;
}

void MainWindow::onOpenAction()
{
	QString folder = QFileDialog::getExistingDirectory();

	if (folder.isEmpty() || folder.isNull())
	{
		return;
	}

	m_recentOpened.insert(0, folder);
	if (m_recentOpened.count() > 10)
	{
		m_recentOpened.removeAt(10);
	}

	updateMenu();

	openFolder(folder);
}

void MainWindow::openFolder(QString folder)
{
	for each (LogViewForm* pLogViewForm in m_logForms)
	{
		delete pLogViewForm;
		ui.tabWidget->removeTab(0);
	}

	m_logForms.clear();
	
	QDir logsFolder(folder + "\\AppRecoveryLogs\\", "*.log");
	if (!logsFolder.exists())
	{
		QMessageBox msgBox;
		msgBox.setText("The folder does not exists");
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.exec();

		m_recentOpened.removeAll(folder);
		updateMenu();

		return;
	}

	wchar_t folderBuffer[1024] = { 0 };
	folder.toWCharArray(folderBuffer);
	QMap<QString, IPlugin*>::iterator pluginIter = m_plugins.begin();
	for (; pluginIter != m_plugins.end(); ++pluginIter)
	{
		IPlugin* pluginInst = *pluginIter;
		pluginInst->resetPluginData();
		pluginInst->initPluginData(folderBuffer);
	}

	QVariant folderVar(folder);
	QMap<QString, QAxWidget*>::iterator winPluginIter = m_winPlugins.begin();
	for (; winPluginIter != m_winPlugins.end(); ++winPluginIter)
	{
		QAxWidget* winPluginInst = *winPluginIter;
		winPluginInst->dynamicCall("ResetPluginData()");
		winPluginInst->dynamicCall("InitPluginData(BSTR)", folderVar);
	}

	QFileInfoList logFiles = logsFolder.entryInfoList();
	int iLogFormIndex = 0;
	foreach(QFileInfo fileInfo, logFiles)
	{
		QString logFileName = fileInfo.absoluteFilePath();
		QString logTitle = fileInfo.fileName();

		LogViewForm* pLogViewForm = new LogViewForm(iLogFormIndex++, logTitle, this);
		ui.tabWidget->addTab(pLogViewForm, logTitle);
		pLogViewForm->loadFile(logFileName);

		m_logForms.append(pLogViewForm);

		connect(pLogViewForm, SIGNAL(searchAllRequest(const QString&, bool)), SLOT(onSearchAll(const QString&, bool)));
		connect(pLogViewForm, SIGNAL(searchAllComplete(QList<CustomTextViewSearchLine*>)), ui.searchResultWidget, SLOT(onSeachResult(QList<CustomTextViewSearchLine*>)));
	}

	setWindowTitle("AAInfo view: " + folder);
}

void MainWindow::onShowSearchResultWindow()
{
	ui.searchResultDockWidget->show();
	ui.searchResultDockWidget->raise();
}

void MainWindow::onSearchAll(const QString& searchString, bool bCaseSens)
{
	ui.searchResultWidget->clearResults();

	for each (LogViewForm* pLogViewForm in m_logForms)
	{
		pLogViewForm->searchAll(searchString, bCaseSens);
	}

	onShowSearchResultWindow();
}

void MainWindow::onSearchDoubleClicked(CustomTextViewLine* pLine)
{
	SearchLineData* pSearchLine = dynamic_cast<SearchLineData*>(pLine);

	ui.tabWidget->setCurrentIndex(pSearchLine->logId());

	LogViewForm* pLogForm = m_logForms.at(pSearchLine->logId());
	pLogForm->selectWord(
		pSearchLine->lineNumber(), 
		pSearchLine->position(),
		pSearchLine->position() + pSearchLine->lenght());
}

void MainWindow::updateMenu()
{
	QVariant value(m_recentOpened);
	m_applicationSettings.setValue(RECENT_OPENED_NAME, value);

	ui.menuFile->clear();
	ui.menuFile->addAction(ui.actionOpen);
	ui.menuFile->addAction(ui.actionDownloadFromS3);
	ui.menuFile->addSeparator();

	for each (QString recentOpened in m_recentOpened)
	{
		QAction* pAction = new QAction(recentOpened, ui.menuFile);
		ui.menuFile->addAction(pAction);

		connect(pAction, SIGNAL(triggered()), SLOT(onRecentClicked()));
	}
}

void MainWindow::onRecentClicked()
{
	QAction* pAction = (QAction*)sender();
	QString folder = pAction->text();

	m_recentOpened.removeAll(folder);
	m_recentOpened.insert(0, folder);

	updateMenu();

	openFolder(folder);
}

void MainWindow::onDownloadFromS3Action()
{
	m_pDownloadDialog->show();
}

void MainWindow::onLogsCompleted()
{
	m_pDownloadDialog->hide();

	openFolder(m_pDownloadDialog->targetFolder());
}

void MainWindow::initPlugins()
{
	QString path = QCoreApplication::applicationDirPath() + "/plugins";

	QDir dir(path);
	QStringList filters;
	filters.append("*Plugin.dll");
	QStringList pluginsNames = dir.entryList(filters);

	QStringList::iterator iter = pluginsNames.begin();
	for (; iter != pluginsNames.end(); ++iter)
	{
		QString pluginName = *iter;
		initPlugin(path + "/" + pluginName);
	}
}

void MainWindow::initPlugin(const QString& pluginFileName)
{
	QLibrary* pluginLib = new QLibrary(pluginFileName, this);
	if (pluginLib->load())
	{
		isWin32FuncPtr isWin32Func = (isWin32FuncPtr)pluginLib->resolve("isWin32Plugin");

		if (isWin32Func != NULL)
		{
			QDockWidget* pDocPluginWidget = NULL;
			if (isWin32Func() == 0)
			{
				pDocPluginWidget = createQtPlugin(pluginLib);
			}

			if (pDocPluginWidget != NULL)
			{
				this->tabifyDockWidget(ui.searchResultDockWidget, pDocPluginWidget);
			}
		}
	}
	else
	{
		qDebug() << "Unable to load plugin DLL. Error: " << pluginLib->errorString();
	}
}

QDockWidget* MainWindow::createQtPlugin(QLibrary* lib)
{
	createPluginFuncPtr pluginCreateFunc = (createPluginFuncPtr)lib->resolve("createQtPlugin");

	if (pluginCreateFunc != NULL)
	{
		IQtPlugin* pluginInst = (IQtPlugin*)pluginCreateFunc();
		if (pluginInst == NULL)
		{
			return NULL;
		}

		wchar_t* szPluginId = pluginInst->getPluginId();
		QString pluginId = QString::fromWCharArray(szPluginId, wcslen(szPluginId));

		wchar_t* szPluginName = pluginInst->getPluginName();
		QString pluginName = QString::fromWCharArray(szPluginName, wcslen(szPluginName));
		QWidget* pluginWidget = pluginInst->getPluginWidget();
		QDockWidget* pluginDockWidget = new QDockWidget(pluginName, this);
		pluginDockWidget->setWidget(pluginWidget);

		qDebug() << "Init " << pluginName;

		QImage* pluginImage = pluginInst->getPluginIcon();
		QIcon pluginIcon(QPixmap::fromImage(*pluginImage));

		QAction* pluginAction = new QAction(pluginIcon, pluginName, this);

		m_pluginActions[pluginId] = pluginAction;
		m_pluginWidgets[pluginId] = pluginDockWidget;
		m_plugins[pluginId] = pluginInst;

		connect(pluginAction, SIGNAL(triggered()), SLOT(onPluginAction()));

		ui.mainToolBar->addAction(pluginAction);
		ui.menuPlugins->addAction(pluginAction);

		return pluginDockWidget;
	}

	return NULL;
}

void MainWindow::onPluginAction()
{
	QAction* action = (QAction*)sender();
	QString pluginId;

	QMapIterator<QString, QAction*> iter(m_pluginActions);
	while(iter.hasNext())
	{
		iter.next();
		QAction* iterAction = iter.value();
		if (iterAction == action)
		{
			pluginId = iter.key();
			break;
		}
	}

	QMap<QString, QDockWidget*>::iterator findIter = m_pluginWidgets.find(pluginId);
	if (findIter != m_pluginWidgets.end())
	{
		QDockWidget* dockWidget = *findIter;
		dockWidget->show();
		dockWidget->raise();
	}
}

void MainWindow::initActiveXPlugins()
{
	QString folder = QApplication::applicationDirPath();
	QString fileName = folder + "/plugins.xml";

	QDomDocument document;
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly))
	{
		return;
	}

	if (!document.setContent(&file)) 
	{
		file.close();
		return;
	}

	file.close();

	QDomElement rootElement = document.documentElement();
	QDomNodeList pluginElements = rootElement.elementsByTagName("plugin");
	for (int i=0; i<pluginElements.count(); i++)
	{
		QDomNode pluginNode = pluginElements.at(i);
		if (pluginNode.isElement())
		{
			QDomElement pluginElement = pluginNode.toElement();
			QString pluginInstanceName = pluginElement.attribute("InstanceName");

			if (!pluginInstanceName.isNull() && !pluginInstanceName.isEmpty())
			{
				QDockWidget* pluginDockWidget = createActiveXPlugin(pluginInstanceName);
				if (pluginDockWidget != NULL)
				{
					this->tabifyDockWidget(ui.searchResultDockWidget, pluginDockWidget);
				}
			}
		}
	}
}

QDockWidget* MainWindow::createActiveXPlugin(QString pluginInstanceName)
{
	QAxWidget* axWidget = new QAxWidget(this);
	if (axWidget->setControl("VersionInfo.InfoViewPlugin") == false)
	{
		delete axWidget;
		return NULL;
	}

	QVariant pluginNameVar = axWidget->dynamicCall("GetPluginName()");
	QVariant pluginIconVar = axWidget->dynamicCall("GetPluginIcon()");
	QVariant pluginIdVar = axWidget->dynamicCall("GetPluginId()");

	if (pluginNameVar.isNull())
	{
		delete axWidget;
		return NULL;
	}

	if (pluginIconVar.isNull())
	{
		delete axWidget;
		return NULL;
	}

	if (pluginIdVar.isNull())
	{
		delete axWidget;
		return NULL;
	}

	QString pluginName = pluginNameVar.toString();
	QString pluginId = pluginIdVar.toString();
	HBITMAP hBitmap = (HBITMAP)pluginIconVar.toInt();

	QPixmap pixmap = QtWin::fromHBITMAP(hBitmap);
	QAction* pluginAction = new QAction(QIcon(pixmap), pluginName, this);

	QDockWidget* pluginDockWidget = new QDockWidget(pluginName, this);
	pluginDockWidget->setWidget(axWidget);

	m_pluginActions[pluginId] = pluginAction;
	m_pluginWidgets[pluginId] = pluginDockWidget;
	m_winPlugins[pluginId] = axWidget;

	connect(pluginAction, SIGNAL(triggered()), SLOT(onPluginAction()));

	ui.mainToolBar->addAction(pluginAction);
	ui.menuPlugins->addAction(pluginAction);

	return pluginDockWidget;
}

