/********************************************************************************
** Form generated from reading UI file 'MsInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSINFOWIDGET_H
#define UI_MSINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsInfoWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QProgressBar *parsingProgressBar;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTreeView *categoriesTreeView;
    QLineEdit *categoryLineEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QTreeView *valuesTreeView;
    QLineEdit *valueLineEdit;

    void setupUi(QWidget *MsInfoWidget)
    {
        if (MsInfoWidget->objectName().isEmpty())
            MsInfoWidget->setObjectName(QStringLiteral("MsInfoWidget"));
        MsInfoWidget->resize(1132, 735);
        verticalLayout_3 = new QVBoxLayout(MsInfoWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        parsingProgressBar = new QProgressBar(MsInfoWidget);
        parsingProgressBar->setObjectName(QStringLiteral("parsingProgressBar"));
        parsingProgressBar->setMaximum(0);
        parsingProgressBar->setValue(0);
        parsingProgressBar->setTextVisible(false);

        verticalLayout_3->addWidget(parsingProgressBar);

        splitter = new QSplitter(MsInfoWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        categoriesTreeView = new QTreeView(layoutWidget);
        categoriesTreeView->setObjectName(QStringLiteral("categoriesTreeView"));
        categoriesTreeView->setAlternatingRowColors(true);

        verticalLayout->addWidget(categoriesTreeView);

        categoryLineEdit = new QLineEdit(layoutWidget);
        categoryLineEdit->setObjectName(QStringLiteral("categoryLineEdit"));
        categoryLineEdit->setReadOnly(true);

        verticalLayout->addWidget(categoryLineEdit);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        valuesTreeView = new QTreeView(layoutWidget1);
        valuesTreeView->setObjectName(QStringLiteral("valuesTreeView"));
        valuesTreeView->setAlternatingRowColors(true);
        valuesTreeView->setRootIsDecorated(false);
        valuesTreeView->setItemsExpandable(false);
        valuesTreeView->setSortingEnabled(true);

        verticalLayout_2->addWidget(valuesTreeView);

        valueLineEdit = new QLineEdit(layoutWidget1);
        valueLineEdit->setObjectName(QStringLiteral("valueLineEdit"));
        valueLineEdit->setReadOnly(true);

        verticalLayout_2->addWidget(valueLineEdit);

        splitter->addWidget(layoutWidget1);

        verticalLayout_3->addWidget(splitter);


        retranslateUi(MsInfoWidget);

        QMetaObject::connectSlotsByName(MsInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *MsInfoWidget)
    {
        MsInfoWidget->setWindowTitle(QApplication::translate("MsInfoWidget", "MsInfoWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class MsInfoWidget: public Ui_MsInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSINFOWIDGET_H
