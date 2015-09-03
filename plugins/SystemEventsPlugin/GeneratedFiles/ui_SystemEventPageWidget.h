/********************************************************************************
** Form generated from reading UI file 'SystemEventPageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMEVENTPAGEWIDGET_H
#define UI_SYSTEMEVENTPAGEWIDGET_H

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
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemEventPageWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QProgressBar *parsingProgressBar;
    QSplitter *splitter_2;
    QTreeView *eventsTreeView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *eventIdLineEdit;
    QPushButton *applyPushButton;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *errorCheckBox;
    QCheckBox *debugCheckBox;
    QCheckBox *fatalCheckBox;
    QCheckBox *infoCheckBox;
    QCheckBox *warnCheckBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *selectAllPushButton;
    QPushButton *selectNonePushButton;
    QSplitter *splitter;
    QListView *providersListView;
    QTextBrowser *descriptionTextBrowser;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLineEdit *sourceLineEdit;
    QLineEdit *creationTimeLineEdit;
    QLabel *label_3;

    void setupUi(QWidget *SystemEventPageWidget)
    {
        if (SystemEventPageWidget->objectName().isEmpty())
            SystemEventPageWidget->setObjectName(QStringLiteral("SystemEventPageWidget"));
        SystemEventPageWidget->resize(1073, 715);
        verticalLayout_2 = new QVBoxLayout(SystemEventPageWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        parsingProgressBar = new QProgressBar(SystemEventPageWidget);
        parsingProgressBar->setObjectName(QStringLiteral("parsingProgressBar"));
        parsingProgressBar->setValue(0);
        parsingProgressBar->setTextVisible(false);

        verticalLayout_2->addWidget(parsingProgressBar);

        splitter_2 = new QSplitter(SystemEventPageWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        eventsTreeView = new QTreeView(splitter_2);
        eventsTreeView->setObjectName(QStringLiteral("eventsTreeView"));
        eventsTreeView->setAlternatingRowColors(true);
        eventsTreeView->setRootIsDecorated(false);
        eventsTreeView->setItemsExpandable(false);
        eventsTreeView->setSortingEnabled(true);
        splitter_2->addWidget(eventsTreeView);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        eventIdLineEdit = new QLineEdit(layoutWidget);
        eventIdLineEdit->setObjectName(QStringLiteral("eventIdLineEdit"));

        horizontalLayout->addWidget(eventIdLineEdit);

        applyPushButton = new QPushButton(layoutWidget);
        applyPushButton->setObjectName(QStringLiteral("applyPushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/plugin/images/Resources/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        applyPushButton->setIcon(icon);

        horizontalLayout->addWidget(applyPushButton);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        errorCheckBox = new QCheckBox(layoutWidget);
        errorCheckBox->setObjectName(QStringLiteral("errorCheckBox"));
        errorCheckBox->setChecked(true);

        horizontalLayout_2->addWidget(errorCheckBox);

        debugCheckBox = new QCheckBox(layoutWidget);
        debugCheckBox->setObjectName(QStringLiteral("debugCheckBox"));
        debugCheckBox->setChecked(true);

        horizontalLayout_2->addWidget(debugCheckBox);

        fatalCheckBox = new QCheckBox(layoutWidget);
        fatalCheckBox->setObjectName(QStringLiteral("fatalCheckBox"));
        fatalCheckBox->setChecked(true);

        horizontalLayout_2->addWidget(fatalCheckBox);

        infoCheckBox = new QCheckBox(layoutWidget);
        infoCheckBox->setObjectName(QStringLiteral("infoCheckBox"));
        infoCheckBox->setChecked(true);

        horizontalLayout_2->addWidget(infoCheckBox);

        warnCheckBox = new QCheckBox(layoutWidget);
        warnCheckBox->setObjectName(QStringLiteral("warnCheckBox"));
        warnCheckBox->setChecked(true);

        horizontalLayout_2->addWidget(warnCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        selectAllPushButton = new QPushButton(layoutWidget);
        selectAllPushButton->setObjectName(QStringLiteral("selectAllPushButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/plugin/images/Resources/selectAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectAllPushButton->setIcon(icon1);

        horizontalLayout_2->addWidget(selectAllPushButton);

        selectNonePushButton = new QPushButton(layoutWidget);
        selectNonePushButton->setObjectName(QStringLiteral("selectNonePushButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/plugin/images/Resources/unselectAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectNonePushButton->setIcon(icon2);

        horizontalLayout_2->addWidget(selectNonePushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        providersListView = new QListView(splitter);
        providersListView->setObjectName(QStringLiteral("providersListView"));
        providersListView->setAlternatingRowColors(true);
        splitter->addWidget(providersListView);
        descriptionTextBrowser = new QTextBrowser(splitter);
        descriptionTextBrowser->setObjectName(QStringLiteral("descriptionTextBrowser"));
        splitter->addWidget(descriptionTextBrowser);

        verticalLayout->addWidget(splitter);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 3, 1, 1);

        sourceLineEdit = new QLineEdit(layoutWidget);
        sourceLineEdit->setObjectName(QStringLiteral("sourceLineEdit"));
        sourceLineEdit->setReadOnly(true);

        gridLayout_2->addWidget(sourceLineEdit, 0, 1, 1, 1);

        creationTimeLineEdit = new QLineEdit(layoutWidget);
        creationTimeLineEdit->setObjectName(QStringLiteral("creationTimeLineEdit"));
        creationTimeLineEdit->setReadOnly(true);

        gridLayout_2->addWidget(creationTimeLineEdit, 0, 4, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        splitter_2->addWidget(layoutWidget);

        verticalLayout_2->addWidget(splitter_2);


        retranslateUi(SystemEventPageWidget);

        QMetaObject::connectSlotsByName(SystemEventPageWidget);
    } // setupUi

    void retranslateUi(QWidget *SystemEventPageWidget)
    {
        SystemEventPageWidget->setWindowTitle(QApplication::translate("SystemEventPageWidget", "SystemEventPageWidget", 0));
        label->setText(QApplication::translate("SystemEventPageWidget", "Event IDs", 0));
#ifndef QT_NO_TOOLTIP
        applyPushButton->setToolTip(QApplication::translate("SystemEventPageWidget", "Apply filter", 0));
#endif // QT_NO_TOOLTIP
        applyPushButton->setText(QString());
        errorCheckBox->setText(QApplication::translate("SystemEventPageWidget", "Error", 0));
        debugCheckBox->setText(QApplication::translate("SystemEventPageWidget", "Debug", 0));
        fatalCheckBox->setText(QApplication::translate("SystemEventPageWidget", "Fatal", 0));
        infoCheckBox->setText(QApplication::translate("SystemEventPageWidget", "Info", 0));
        warnCheckBox->setText(QApplication::translate("SystemEventPageWidget", "Warning", 0));
#ifndef QT_NO_TOOLTIP
        selectAllPushButton->setToolTip(QApplication::translate("SystemEventPageWidget", "Select all", 0));
#endif // QT_NO_TOOLTIP
        selectAllPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        selectNonePushButton->setToolTip(QApplication::translate("SystemEventPageWidget", "Unselect all", 0));
#endif // QT_NO_TOOLTIP
        selectNonePushButton->setText(QString());
        label_6->setText(QApplication::translate("SystemEventPageWidget", "Creation time", 0));
        label_3->setText(QApplication::translate("SystemEventPageWidget", "Source", 0));
    } // retranslateUi

};

namespace Ui {
    class SystemEventPageWidget: public Ui_SystemEventPageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMEVENTPAGEWIDGET_H
