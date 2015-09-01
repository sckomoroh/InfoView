/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "searchresultwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionOpen;
    QAction *actionAbout;
    QAction *actionShowSearchResultWindow;
    QAction *actionDownloadFromS3;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuWindows;
    QMenu *menuPlugins;
    QToolBar *mainToolBar;
    QDockWidget *searchResultDockWidget;
    SearchResultWidget *searchResultWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1445, 848);
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/InfoViewer/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionAbout = new QAction(MainWindowClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionShowSearchResultWindow = new QAction(MainWindowClass);
        actionShowSearchResultWindow->setObjectName(QStringLiteral("actionShowSearchResultWindow"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/InfoViewer/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowSearchResultWindow->setIcon(icon1);
        actionDownloadFromS3 = new QAction(MainWindowClass);
        actionDownloadFromS3->setObjectName(QStringLiteral("actionDownloadFromS3"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/InfoViewer/images/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDownloadFromS3->setIcon(icon2);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        verticalLayout->addWidget(tabWidget);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1445, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuWindows = new QMenu(menuView);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        menuPlugins = new QMenu(menuBar);
        menuPlugins->setObjectName(QStringLiteral("menuPlugins"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy);
        mainToolBar->setLayoutDirection(Qt::LeftToRight);
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::AllToolBarAreas);
        MainWindowClass->addToolBar(Qt::RightToolBarArea, mainToolBar);
        searchResultDockWidget = new QDockWidget(MainWindowClass);
        searchResultDockWidget->setObjectName(QStringLiteral("searchResultDockWidget"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/MainWindow/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchResultDockWidget->setWindowIcon(icon3);
        searchResultWidget = new SearchResultWidget();
        searchResultWidget->setObjectName(QStringLiteral("searchResultWidget"));
        searchResultDockWidget->setWidget(searchResultWidget);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), searchResultDockWidget);
        toolBar = new QToolBar(MainWindowClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        toolBar->setMovable(false);
        MainWindowClass->addToolBar(Qt::LeftToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuPlugins->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionDownloadFromS3);
        menuHelp->addAction(actionAbout);
        menuView->addAction(menuWindows->menuAction());
        menuWindows->addAction(actionShowSearchResultWindow);
        mainToolBar->addAction(actionShowSearchResultWindow);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionDownloadFromS3);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "AAInfo view", 0));
        actionOpen->setText(QApplication::translate("MainWindowClass", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+O", 0));
        actionAbout->setText(QApplication::translate("MainWindowClass", "About", 0));
        actionShowSearchResultWindow->setText(QApplication::translate("MainWindowClass", "Search result", 0));
#ifndef QT_NO_TOOLTIP
        actionShowSearchResultWindow->setToolTip(QApplication::translate("MainWindowClass", "Show search result window", 0));
#endif // QT_NO_TOOLTIP
        actionDownloadFromS3->setText(QApplication::translate("MainWindowClass", "Download from S3", 0));
#ifndef QT_NO_TOOLTIP
        actionDownloadFromS3->setToolTip(QApplication::translate("MainWindowClass", "Download logs from S3 and unpack", 0));
#endif // QT_NO_TOOLTIP
        actionDownloadFromS3->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+D", 0));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindowClass", "Help", 0));
        menuView->setTitle(QApplication::translate("MainWindowClass", "View", 0));
        menuWindows->setTitle(QApplication::translate("MainWindowClass", "Windows", 0));
        menuPlugins->setTitle(QApplication::translate("MainWindowClass", "Plugins", 0));
        searchResultDockWidget->setWindowTitle(QApplication::translate("MainWindowClass", "Search result", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindowClass", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
