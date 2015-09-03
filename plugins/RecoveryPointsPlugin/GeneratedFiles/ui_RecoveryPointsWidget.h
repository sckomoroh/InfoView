/********************************************************************************
** Form generated from reading UI file 'RecoveryPointsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOVERYPOINTSWIDGET_H
#define UI_RECOVERYPOINTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecoveryPointsWidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QProgressBar *folderProgressBar;
    QProgressBar *agentProgressBar;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeView;
    QLineEdit *recoveryPointLineEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *agentIdLineEdit;
    QLineEdit *rpIdLineEdit;
    QLineEdit *volumeIdLineEdit;
    QLineEdit *prevEpochLineEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QTreeView *sqlTreeView;
    QLineEdit *sqlLineEdit;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *exchangeVersionLabel;
    QLabel *exchangeNameLabel;
    QTreeView *exchangeTreeView;
    QLineEdit *exchageLineEdit;

    void setupUi(QWidget *RecoveryPointsWidget)
    {
        if (RecoveryPointsWidget->objectName().isEmpty())
            RecoveryPointsWidget->setObjectName(QStringLiteral("RecoveryPointsWidget"));
        RecoveryPointsWidget->resize(1149, 736);
        verticalLayout_5 = new QVBoxLayout(RecoveryPointsWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 2, 2, 2);
        folderProgressBar = new QProgressBar(RecoveryPointsWidget);
        folderProgressBar->setObjectName(QStringLiteral("folderProgressBar"));
        folderProgressBar->setValue(0);
        folderProgressBar->setTextVisible(false);

        verticalLayout_5->addWidget(folderProgressBar);

        agentProgressBar = new QProgressBar(RecoveryPointsWidget);
        agentProgressBar->setObjectName(QStringLiteral("agentProgressBar"));
        agentProgressBar->setValue(0);
        agentProgressBar->setTextVisible(false);

        verticalLayout_5->addWidget(agentProgressBar);

        splitter = new QSplitter(RecoveryPointsWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(verticalLayoutWidget_2);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setAlternatingRowColors(true);
        treeView->setSortingEnabled(true);

        verticalLayout_2->addWidget(treeView);

        recoveryPointLineEdit = new QLineEdit(verticalLayoutWidget_2);
        recoveryPointLineEdit->setObjectName(QStringLiteral("recoveryPointLineEdit"));
        recoveryPointLineEdit->setReadOnly(true);

        verticalLayout_2->addWidget(recoveryPointLineEdit);

        splitter->addWidget(verticalLayoutWidget_2);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        agentIdLineEdit = new QLineEdit(verticalLayoutWidget);
        agentIdLineEdit->setObjectName(QStringLiteral("agentIdLineEdit"));

        verticalLayout->addWidget(agentIdLineEdit);

        rpIdLineEdit = new QLineEdit(verticalLayoutWidget);
        rpIdLineEdit->setObjectName(QStringLiteral("rpIdLineEdit"));

        verticalLayout->addWidget(rpIdLineEdit);

        volumeIdLineEdit = new QLineEdit(verticalLayoutWidget);
        volumeIdLineEdit->setObjectName(QStringLiteral("volumeIdLineEdit"));
        volumeIdLineEdit->setReadOnly(true);

        verticalLayout->addWidget(volumeIdLineEdit);

        prevEpochLineEdit = new QLineEdit(verticalLayoutWidget);
        prevEpochLineEdit->setObjectName(QStringLiteral("prevEpochLineEdit"));
        prevEpochLineEdit->setReadOnly(true);

        verticalLayout->addWidget(prevEpochLineEdit);

        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        sqlTreeView = new QTreeView(tab);
        sqlTreeView->setObjectName(QStringLiteral("sqlTreeView"));
        sqlTreeView->setAlternatingRowColors(true);

        verticalLayout_3->addWidget(sqlTreeView);

        sqlLineEdit = new QLineEdit(tab);
        sqlLineEdit->setObjectName(QStringLiteral("sqlLineEdit"));
        sqlLineEdit->setReadOnly(true);

        verticalLayout_3->addWidget(sqlLineEdit);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        exchangeVersionLabel = new QLabel(tab_2);
        exchangeVersionLabel->setObjectName(QStringLiteral("exchangeVersionLabel"));

        verticalLayout_4->addWidget(exchangeVersionLabel);

        exchangeNameLabel = new QLabel(tab_2);
        exchangeNameLabel->setObjectName(QStringLiteral("exchangeNameLabel"));

        verticalLayout_4->addWidget(exchangeNameLabel);

        exchangeTreeView = new QTreeView(tab_2);
        exchangeTreeView->setObjectName(QStringLiteral("exchangeTreeView"));
        exchangeTreeView->setAlternatingRowColors(true);

        verticalLayout_4->addWidget(exchangeTreeView);

        exchageLineEdit = new QLineEdit(tab_2);
        exchageLineEdit->setObjectName(QStringLiteral("exchageLineEdit"));
        exchageLineEdit->setReadOnly(true);

        verticalLayout_4->addWidget(exchageLineEdit);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        splitter->addWidget(verticalLayoutWidget);

        verticalLayout_5->addWidget(splitter);


        retranslateUi(RecoveryPointsWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RecoveryPointsWidget);
    } // setupUi

    void retranslateUi(QWidget *RecoveryPointsWidget)
    {
        RecoveryPointsWidget->setWindowTitle(QApplication::translate("RecoveryPointsWidget", "RecoveryPointsWidget", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("RecoveryPointsWidget", "SQL information", 0));
        exchangeVersionLabel->setText(QApplication::translate("RecoveryPointsWidget", "Exchange version", 0));
        exchangeNameLabel->setText(QApplication::translate("RecoveryPointsWidget", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("RecoveryPointsWidget", "Exchange information", 0));
    } // retranslateUi

};

namespace Ui {
    class RecoveryPointsWidget: public Ui_RecoveryPointsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOVERYPOINTSWIDGET_H
