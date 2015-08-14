/********************************************************************************
** Form generated from reading UI file 'MongoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONGOWIDGET_H
#define UI_MONGOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MongoJobWidget.h"
#include "mongoeventwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MongoWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *jobsInfoTab;
    QVBoxLayout *verticalLayout_3;
    MongoJobWidget *jobWidget;
    QWidget *eventsInfoTab;
    QVBoxLayout *verticalLayout_4;
    MongoEventWidget *eventsWidget;

    void setupUi(QWidget *MongoWidget)
    {
        if (MongoWidget->objectName().isEmpty())
            MongoWidget->setObjectName(QStringLiteral("MongoWidget"));
        MongoWidget->resize(1029, 300);
        verticalLayout = new QVBoxLayout(MongoWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        tabWidget = new QTabWidget(MongoWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        jobsInfoTab = new QWidget();
        jobsInfoTab->setObjectName(QStringLiteral("jobsInfoTab"));
        verticalLayout_3 = new QVBoxLayout(jobsInfoTab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        jobWidget = new MongoJobWidget(jobsInfoTab);
        jobWidget->setObjectName(QStringLiteral("jobWidget"));

        verticalLayout_3->addWidget(jobWidget);

        tabWidget->addTab(jobsInfoTab, QString());
        eventsInfoTab = new QWidget();
        eventsInfoTab->setObjectName(QStringLiteral("eventsInfoTab"));
        verticalLayout_4 = new QVBoxLayout(eventsInfoTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        eventsWidget = new MongoEventWidget(eventsInfoTab);
        eventsWidget->setObjectName(QStringLiteral("eventsWidget"));

        verticalLayout_4->addWidget(eventsWidget);

        tabWidget->addTab(eventsInfoTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MongoWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MongoWidget);
    } // setupUi

    void retranslateUi(QWidget *MongoWidget)
    {
        MongoWidget->setWindowTitle(QApplication::translate("MongoWidget", "MongoWidget", 0));
        tabWidget->setTabText(tabWidget->indexOf(jobsInfoTab), QApplication::translate("MongoWidget", "Jobs information", 0));
        tabWidget->setTabText(tabWidget->indexOf(eventsInfoTab), QApplication::translate("MongoWidget", "Events/Alerts information", 0));
    } // retranslateUi

};

namespace Ui {
    class MongoWidget: public Ui_MongoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONGOWIDGET_H
