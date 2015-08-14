/********************************************************************************
** Form generated from reading UI file 'AmazonDownloadDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMAZONDOWNLOADDIALOG_H
#define UI_AMAZONDOWNLOADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AmazonDownloadDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *phaseLabel;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *linkLineEdit;
    QPushButton *downloadButton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *locationLineEdit;
    QPushButton *browseButton;
    QLabel *label;
    QTreeView *searchResultTreeView;

    void setupUi(QDialog *AmazonDownloadDialog)
    {
        if (AmazonDownloadDialog->objectName().isEmpty())
            AmazonDownloadDialog->setObjectName(QStringLiteral("AmazonDownloadDialog"));
        AmazonDownloadDialog->resize(936, 592);
        AmazonDownloadDialog->setModal(true);
        verticalLayout = new QVBoxLayout(AmazonDownloadDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        phaseLabel = new QLabel(AmazonDownloadDialog);
        phaseLabel->setObjectName(QStringLiteral("phaseLabel"));

        verticalLayout->addWidget(phaseLabel);

        progressBar = new QProgressBar(AmazonDownloadDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        searchLineEdit = new QLineEdit(AmazonDownloadDialog);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);

        searchButton = new QPushButton(AmazonDownloadDialog);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayout->addWidget(searchButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        linkLineEdit = new QLineEdit(AmazonDownloadDialog);
        linkLineEdit->setObjectName(QStringLiteral("linkLineEdit"));

        horizontalLayout_2->addWidget(linkLineEdit);

        downloadButton = new QPushButton(AmazonDownloadDialog);
        downloadButton->setObjectName(QStringLiteral("downloadButton"));

        horizontalLayout_2->addWidget(downloadButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        locationLineEdit = new QLineEdit(AmazonDownloadDialog);
        locationLineEdit->setObjectName(QStringLiteral("locationLineEdit"));

        horizontalLayout_3->addWidget(locationLineEdit);

        browseButton = new QPushButton(AmazonDownloadDialog);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        horizontalLayout_3->addWidget(browseButton);


        verticalLayout->addLayout(horizontalLayout_3);

        label = new QLabel(AmazonDownloadDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        searchResultTreeView = new QTreeView(AmazonDownloadDialog);
        searchResultTreeView->setObjectName(QStringLiteral("searchResultTreeView"));
        searchResultTreeView->setRootIsDecorated(false);
        searchResultTreeView->setItemsExpandable(false);

        verticalLayout->addWidget(searchResultTreeView);


        retranslateUi(AmazonDownloadDialog);

        QMetaObject::connectSlotsByName(AmazonDownloadDialog);
    } // setupUi

    void retranslateUi(QDialog *AmazonDownloadDialog)
    {
        AmazonDownloadDialog->setWindowTitle(QApplication::translate("AmazonDownloadDialog", "Download from Amazon S3", 0));
        phaseLabel->setText(QApplication::translate("AmazonDownloadDialog", "TextLabel", 0));
        searchButton->setText(QApplication::translate("AmazonDownloadDialog", "Search", 0));
        downloadButton->setText(QApplication::translate("AmazonDownloadDialog", "Download", 0));
        browseButton->setText(QApplication::translate("AmazonDownloadDialog", "Browse", 0));
        label->setText(QApplication::translate("AmazonDownloadDialog", "Available items", 0));
    } // retranslateUi

};

namespace Ui {
    class AmazonDownloadDialog: public Ui_AmazonDownloadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMAZONDOWNLOADDIALOG_H
