/********************************************************************************
** Form generated from reading UI file 'SearchResultWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHRESULTWIDGET_H
#define UI_SEARCHRESULTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CustomTextViewWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SearchResultWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearPushButton;
    QScrollArea *searchScrollArea;
    CustomTextViewWidget *searchResultViewWidget;

    void setupUi(QWidget *SearchResultWidget)
    {
        if (SearchResultWidget->objectName().isEmpty())
            SearchResultWidget->setObjectName(QStringLiteral("SearchResultWidget"));
        SearchResultWidget->resize(918, 716);
        verticalLayout = new QVBoxLayout(SearchResultWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearPushButton = new QPushButton(SearchResultWidget);
        clearPushButton->setObjectName(QStringLiteral("clearPushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/InfoViewer/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearPushButton->setIcon(icon);

        horizontalLayout->addWidget(clearPushButton);


        verticalLayout->addLayout(horizontalLayout);

        searchScrollArea = new QScrollArea(SearchResultWidget);
        searchScrollArea->setObjectName(QStringLiteral("searchScrollArea"));
        searchScrollArea->setWidgetResizable(false);
        searchResultViewWidget = new CustomTextViewWidget();
        searchResultViewWidget->setObjectName(QStringLiteral("searchResultViewWidget"));
        searchResultViewWidget->setGeometry(QRect(0, 0, 912, 682));
        searchScrollArea->setWidget(searchResultViewWidget);

        verticalLayout->addWidget(searchScrollArea);


        retranslateUi(SearchResultWidget);

        QMetaObject::connectSlotsByName(SearchResultWidget);
    } // setupUi

    void retranslateUi(QWidget *SearchResultWidget)
    {
        SearchResultWidget->setWindowTitle(QApplication::translate("SearchResultWidget", "SearchResultWidget", 0));
#ifndef QT_NO_TOOLTIP
        clearPushButton->setToolTip(QApplication::translate("SearchResultWidget", "Clear search results", 0));
#endif // QT_NO_TOOLTIP
        clearPushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SearchResultWidget: public Ui_SearchResultWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRESULTWIDGET_H
