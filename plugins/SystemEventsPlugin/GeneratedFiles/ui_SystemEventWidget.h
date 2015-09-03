/********************************************************************************
** Form generated from reading UI file 'SystemEventWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMEVENTWIDGET_H
#define UI_SYSTEMEVENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "systemeventpagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_SystemEventWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    SystemEventPageWidget *applicationEventsWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    SystemEventPageWidget *systemEventsWidget;

    void setupUi(QWidget *SystemEventWidget)
    {
        if (SystemEventWidget->objectName().isEmpty())
            SystemEventWidget->setObjectName(QStringLiteral("SystemEventWidget"));
        SystemEventWidget->resize(1189, 831);
        verticalLayout_3 = new QVBoxLayout(SystemEventWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        tabWidget = new QTabWidget(SystemEventWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        applicationEventsWidget = new SystemEventPageWidget(tab);
        applicationEventsWidget->setObjectName(QStringLiteral("applicationEventsWidget"));

        verticalLayout_2->addWidget(applicationEventsWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        systemEventsWidget = new SystemEventPageWidget(tab_2);
        systemEventsWidget->setObjectName(QStringLiteral("systemEventsWidget"));

        verticalLayout->addWidget(systemEventsWidget);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);


        retranslateUi(SystemEventWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SystemEventWidget);
    } // setupUi

    void retranslateUi(QWidget *SystemEventWidget)
    {
        SystemEventWidget->setWindowTitle(QApplication::translate("SystemEventWidget", "EventsViewWidget", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SystemEventWidget", "Application", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SystemEventWidget", "System", 0));
    } // retranslateUi

};

namespace Ui {
    class SystemEventWidget: public Ui_SystemEventWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMEVENTWIDGET_H
