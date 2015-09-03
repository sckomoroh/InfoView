/********************************************************************************
** Form generated from reading UI file 'RegWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWIDGET_H
#define UI_REGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QProgressBar *loadingProgressBar;
    QSplitter *splitter_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTreeView *keysTreeView;
    QLineEdit *keyLineEdit;
    QSplitter *splitter;
    QTreeView *valueTreeView;
    QTextBrowser *valueTextBrowser;

    void setupUi(QWidget *RegWidget)
    {
        if (RegWidget->objectName().isEmpty())
            RegWidget->setObjectName(QStringLiteral("RegWidget"));
        RegWidget->resize(1158, 716);
        verticalLayout_2 = new QVBoxLayout(RegWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        loadingProgressBar = new QProgressBar(RegWidget);
        loadingProgressBar->setObjectName(QStringLiteral("loadingProgressBar"));
        loadingProgressBar->setMaximum(0);
        loadingProgressBar->setValue(0);
        loadingProgressBar->setTextVisible(false);

        verticalLayout_2->addWidget(loadingProgressBar);

        splitter_2 = new QSplitter(RegWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        keysTreeView = new QTreeView(verticalLayoutWidget);
        keysTreeView->setObjectName(QStringLiteral("keysTreeView"));
        keysTreeView->setAlternatingRowColors(true);
        keysTreeView->setHeaderHidden(true);

        verticalLayout->addWidget(keysTreeView);

        keyLineEdit = new QLineEdit(verticalLayoutWidget);
        keyLineEdit->setObjectName(QStringLiteral("keyLineEdit"));
        keyLineEdit->setReadOnly(true);

        verticalLayout->addWidget(keyLineEdit);

        splitter_2->addWidget(verticalLayoutWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        valueTreeView = new QTreeView(splitter);
        valueTreeView->setObjectName(QStringLiteral("valueTreeView"));
        valueTreeView->setRootIsDecorated(false);
        valueTreeView->setItemsExpandable(false);
        valueTreeView->setWordWrap(true);
        splitter->addWidget(valueTreeView);
        valueTextBrowser = new QTextBrowser(splitter);
        valueTextBrowser->setObjectName(QStringLiteral("valueTextBrowser"));
        splitter->addWidget(valueTextBrowser);
        splitter_2->addWidget(splitter);

        verticalLayout_2->addWidget(splitter_2);


        retranslateUi(RegWidget);

        QMetaObject::connectSlotsByName(RegWidget);
    } // setupUi

    void retranslateUi(QWidget *RegWidget)
    {
        RegWidget->setWindowTitle(QApplication::translate("RegWidget", "RegistryViewWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class RegWidget: public Ui_RegWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWIDGET_H
