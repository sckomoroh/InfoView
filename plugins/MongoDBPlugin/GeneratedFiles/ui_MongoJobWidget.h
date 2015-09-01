/********************************************************************************
** Form generated from reading UI file 'MongoJobWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONGOJOBWIDGET_H
#define UI_MONGOJOBWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MongoJobWidget
{
public:
    QVBoxLayout *verticalLayout;
    QProgressBar *loadingProgressBar;
    QHBoxLayout *horizontalLayout;
    QCheckBox *serviceJobCheckBox;
    QCheckBox *userJobCheckBox;
    QCheckBox *successCheckBox;
    QCheckBox *cancelCheckBox;
    QCheckBox *failCheckBox;
    QLineEdit *filterLineEdit;
    QPushButton *applyFilterPushButton;
    QSplitter *splitter;
    QTreeView *jobsTreeView;
    QToolBox *jobDetailsToolBox;
    QWidget *page;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *summaryLineEdit;
    QLineEdit *statusLineEdit;
    QLineEdit *phaseLineEdit;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_9;
    QLineEdit *endLineEdit;
    QLineEdit *creationLineEdit;
    QLineEdit *startLineEdit;
    QLineEdit *idLineEdit;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter_2;
    QTextBrowser *errorDetailsTextBrowser;
    QTextBrowser *errorStackTextBrowser;

    void setupUi(QWidget *MongoJobWidget)
    {
        if (MongoJobWidget->objectName().isEmpty())
            MongoJobWidget->setObjectName(QStringLiteral("MongoJobWidget"));
        MongoJobWidget->resize(981, 781);
        verticalLayout = new QVBoxLayout(MongoJobWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        loadingProgressBar = new QProgressBar(MongoJobWidget);
        loadingProgressBar->setObjectName(QStringLiteral("loadingProgressBar"));
        loadingProgressBar->setValue(0);
        loadingProgressBar->setTextVisible(false);

        verticalLayout->addWidget(loadingProgressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        serviceJobCheckBox = new QCheckBox(MongoJobWidget);
        serviceJobCheckBox->setObjectName(QStringLiteral("serviceJobCheckBox"));
        serviceJobCheckBox->setChecked(true);

        horizontalLayout->addWidget(serviceJobCheckBox);

        userJobCheckBox = new QCheckBox(MongoJobWidget);
        userJobCheckBox->setObjectName(QStringLiteral("userJobCheckBox"));
        userJobCheckBox->setChecked(true);

        horizontalLayout->addWidget(userJobCheckBox);

        successCheckBox = new QCheckBox(MongoJobWidget);
        successCheckBox->setObjectName(QStringLiteral("successCheckBox"));
        successCheckBox->setChecked(true);

        horizontalLayout->addWidget(successCheckBox);

        cancelCheckBox = new QCheckBox(MongoJobWidget);
        cancelCheckBox->setObjectName(QStringLiteral("cancelCheckBox"));
        cancelCheckBox->setChecked(true);

        horizontalLayout->addWidget(cancelCheckBox);

        failCheckBox = new QCheckBox(MongoJobWidget);
        failCheckBox->setObjectName(QStringLiteral("failCheckBox"));
        failCheckBox->setChecked(true);

        horizontalLayout->addWidget(failCheckBox);

        filterLineEdit = new QLineEdit(MongoJobWidget);
        filterLineEdit->setObjectName(QStringLiteral("filterLineEdit"));

        horizontalLayout->addWidget(filterLineEdit);

        applyFilterPushButton = new QPushButton(MongoJobWidget);
        applyFilterPushButton->setObjectName(QStringLiteral("applyFilterPushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/plugin/images/Resources/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        applyFilterPushButton->setIcon(icon);

        horizontalLayout->addWidget(applyFilterPushButton);


        verticalLayout->addLayout(horizontalLayout);

        splitter = new QSplitter(MongoJobWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        jobsTreeView = new QTreeView(splitter);
        jobsTreeView->setObjectName(QStringLiteral("jobsTreeView"));
        jobsTreeView->setAlternatingRowColors(true);
        jobsTreeView->setSortingEnabled(true);
        splitter->addWidget(jobsTreeView);
        jobDetailsToolBox = new QToolBox(splitter);
        jobDetailsToolBox->setObjectName(QStringLiteral("jobDetailsToolBox"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 977, 323));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        summaryLineEdit = new QLineEdit(page);
        summaryLineEdit->setObjectName(QStringLiteral("summaryLineEdit"));
        summaryLineEdit->setReadOnly(true);

        gridLayout->addWidget(summaryLineEdit, 0, 2, 1, 5);

        statusLineEdit = new QLineEdit(page);
        statusLineEdit->setObjectName(QStringLiteral("statusLineEdit"));
        statusLineEdit->setReadOnly(true);

        gridLayout->addWidget(statusLineEdit, 2, 2, 1, 1);

        phaseLineEdit = new QLineEdit(page);
        phaseLineEdit->setObjectName(QStringLiteral("phaseLineEdit"));
        phaseLineEdit->setReadOnly(true);

        gridLayout->addWidget(phaseLineEdit, 2, 4, 1, 3);

        label_8 = new QLabel(page);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 3, 1, 1);

        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_9 = new QLabel(page);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        endLineEdit = new QLineEdit(page);
        endLineEdit->setObjectName(QStringLiteral("endLineEdit"));
        endLineEdit->setReadOnly(true);

        gridLayout->addWidget(endLineEdit, 4, 6, 1, 1);

        creationLineEdit = new QLineEdit(page);
        creationLineEdit->setObjectName(QStringLiteral("creationLineEdit"));
        creationLineEdit->setReadOnly(true);

        gridLayout->addWidget(creationLineEdit, 4, 2, 1, 1);

        startLineEdit = new QLineEdit(page);
        startLineEdit->setObjectName(QStringLiteral("startLineEdit"));
        startLineEdit->setReadOnly(true);

        gridLayout->addWidget(startLineEdit, 4, 4, 1, 1);

        idLineEdit = new QLineEdit(page);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));
        idLineEdit->setReadOnly(true);

        gridLayout->addWidget(idLineEdit, 1, 2, 1, 5);

        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 3, 1, 1);

        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 5, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 4, 1, 1);

        jobDetailsToolBox->addItem(page, QStringLiteral("General information"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 98, 165));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter_2 = new QSplitter(page_2);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        errorDetailsTextBrowser = new QTextBrowser(splitter_2);
        errorDetailsTextBrowser->setObjectName(QStringLiteral("errorDetailsTextBrowser"));
        splitter_2->addWidget(errorDetailsTextBrowser);
        errorStackTextBrowser = new QTextBrowser(splitter_2);
        errorStackTextBrowser->setObjectName(QStringLiteral("errorStackTextBrowser"));
        splitter_2->addWidget(errorStackTextBrowser);

        verticalLayout_2->addWidget(splitter_2);

        jobDetailsToolBox->addItem(page_2, QStringLiteral("Error information"));
        splitter->addWidget(jobDetailsToolBox);

        verticalLayout->addWidget(splitter);


        retranslateUi(MongoJobWidget);

        jobDetailsToolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MongoJobWidget);
    } // setupUi

    void retranslateUi(QWidget *MongoJobWidget)
    {
        MongoJobWidget->setWindowTitle(QApplication::translate("MongoJobWidget", "MongoJobWidget", 0));
        serviceJobCheckBox->setText(QApplication::translate("MongoJobWidget", "Service jobs", 0));
        userJobCheckBox->setText(QApplication::translate("MongoJobWidget", "User jobs", 0));
        successCheckBox->setText(QApplication::translate("MongoJobWidget", "Success", 0));
        cancelCheckBox->setText(QApplication::translate("MongoJobWidget", "Canceled", 0));
        failCheckBox->setText(QApplication::translate("MongoJobWidget", "Failed", 0));
#ifndef QT_NO_TOOLTIP
        applyFilterPushButton->setToolTip(QApplication::translate("MongoJobWidget", "Apply filter", 0));
#endif // QT_NO_TOOLTIP
        applyFilterPushButton->setText(QString());
        label->setText(QApplication::translate("MongoJobWidget", "Summary", 0));
        label_8->setText(QApplication::translate("MongoJobWidget", "Phase", 0));
        label_2->setText(QApplication::translate("MongoJobWidget", "ID", 0));
        label_3->setText(QApplication::translate("MongoJobWidget", "Status", 0));
        label_9->setText(QApplication::translate("MongoJobWidget", "Creation time", 0));
        label_5->setText(QApplication::translate("MongoJobWidget", "Start time", 0));
        label_6->setText(QApplication::translate("MongoJobWidget", "End time", 0));
        jobDetailsToolBox->setItemText(jobDetailsToolBox->indexOf(page), QApplication::translate("MongoJobWidget", "General information", 0));
        jobDetailsToolBox->setItemText(jobDetailsToolBox->indexOf(page_2), QApplication::translate("MongoJobWidget", "Error information", 0));
    } // retranslateUi

};

namespace Ui {
    class MongoJobWidget: public Ui_MongoJobWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONGOJOBWIDGET_H
