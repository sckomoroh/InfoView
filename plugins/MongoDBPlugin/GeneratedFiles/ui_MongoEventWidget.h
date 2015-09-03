/********************************************************************************
** Form generated from reading UI file 'MongoEventWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONGOEVENTWIDGET_H
#define UI_MONGOEVENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MongoEventWidget
{
public:
    QVBoxLayout *verticalLayout;
    QProgressBar *loadingProgressBar;
    QHBoxLayout *horizontalLayout;
    QCheckBox *infoCheckBox;
    QCheckBox *warningCheckBox;
    QCheckBox *errorCheckBox;
    QCheckBox *alertsCheckBox;
    QCheckBox *eventsCheckBox;
    QLineEdit *filterLineEdit;
    QPushButton *applyPushButton;
    QTreeView *treeView;

    void setupUi(QWidget *MongoEventWidget)
    {
        if (MongoEventWidget->objectName().isEmpty())
            MongoEventWidget->setObjectName(QStringLiteral("MongoEventWidget"));
        MongoEventWidget->resize(964, 542);
        verticalLayout = new QVBoxLayout(MongoEventWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        loadingProgressBar = new QProgressBar(MongoEventWidget);
        loadingProgressBar->setObjectName(QStringLiteral("loadingProgressBar"));
        loadingProgressBar->setValue(0);
        loadingProgressBar->setTextVisible(false);

        verticalLayout->addWidget(loadingProgressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        infoCheckBox = new QCheckBox(MongoEventWidget);
        infoCheckBox->setObjectName(QStringLiteral("infoCheckBox"));
        infoCheckBox->setChecked(true);

        horizontalLayout->addWidget(infoCheckBox);

        warningCheckBox = new QCheckBox(MongoEventWidget);
        warningCheckBox->setObjectName(QStringLiteral("warningCheckBox"));
        warningCheckBox->setChecked(true);

        horizontalLayout->addWidget(warningCheckBox);

        errorCheckBox = new QCheckBox(MongoEventWidget);
        errorCheckBox->setObjectName(QStringLiteral("errorCheckBox"));
        errorCheckBox->setChecked(true);

        horizontalLayout->addWidget(errorCheckBox);

        alertsCheckBox = new QCheckBox(MongoEventWidget);
        alertsCheckBox->setObjectName(QStringLiteral("alertsCheckBox"));
        alertsCheckBox->setChecked(true);

        horizontalLayout->addWidget(alertsCheckBox);

        eventsCheckBox = new QCheckBox(MongoEventWidget);
        eventsCheckBox->setObjectName(QStringLiteral("eventsCheckBox"));
        eventsCheckBox->setChecked(true);

        horizontalLayout->addWidget(eventsCheckBox);

        filterLineEdit = new QLineEdit(MongoEventWidget);
        filterLineEdit->setObjectName(QStringLiteral("filterLineEdit"));

        horizontalLayout->addWidget(filterLineEdit);

        applyPushButton = new QPushButton(MongoEventWidget);
        applyPushButton->setObjectName(QStringLiteral("applyPushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/plugin/images/Resources/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        applyPushButton->setIcon(icon);
        applyPushButton->setFlat(false);

        horizontalLayout->addWidget(applyPushButton);


        verticalLayout->addLayout(horizontalLayout);

        treeView = new QTreeView(MongoEventWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setAlternatingRowColors(true);
        treeView->setRootIsDecorated(false);
        treeView->setItemsExpandable(false);
        treeView->setSortingEnabled(true);

        verticalLayout->addWidget(treeView);


        retranslateUi(MongoEventWidget);

        QMetaObject::connectSlotsByName(MongoEventWidget);
    } // setupUi

    void retranslateUi(QWidget *MongoEventWidget)
    {
        MongoEventWidget->setWindowTitle(QApplication::translate("MongoEventWidget", "EventViewWidget", 0));
        infoCheckBox->setText(QApplication::translate("MongoEventWidget", "Info", 0));
        warningCheckBox->setText(QApplication::translate("MongoEventWidget", "Warning", 0));
        errorCheckBox->setText(QApplication::translate("MongoEventWidget", "Error", 0));
        alertsCheckBox->setText(QApplication::translate("MongoEventWidget", "Alerts", 0));
        eventsCheckBox->setText(QApplication::translate("MongoEventWidget", "Events", 0));
#ifndef QT_NO_TOOLTIP
        applyPushButton->setToolTip(QApplication::translate("MongoEventWidget", "Apply filter", 0));
#endif // QT_NO_TOOLTIP
        applyPushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MongoEventWidget: public Ui_MongoEventWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONGOEVENTWIDGET_H
