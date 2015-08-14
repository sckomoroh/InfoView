/********************************************************************************
** Form generated from reading UI file 'LogViewForm.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGVIEWFORM_H
#define UI_LOGVIEWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CustomTextViewWidget.h"

QT_BEGIN_NAMESPACE

class Ui_LogViewForm
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *searchToolWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *seachLineEdit;
    QCheckBox *caseSensCheckBox;
    QCheckBox *backCheckBox;
    QPushButton *searchPushButton;
    QPushButton *searchAllPushButton;
    QPushButton *closePushButton;
    QScrollArea *scrollArea;
    CustomTextViewWidget *logViewWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *m_debugCheckBox;
    QCheckBox *m_infoCheckBox;
    QCheckBox *m_warnCheckBox;
    QCheckBox *m_errorCheckBox;
    QLineEdit *m_filterLineEdit;
    QPushButton *m_applyFilterPushButton;

    void setupUi(QWidget *LogViewForm)
    {
        if (LogViewForm->objectName().isEmpty())
            LogViewForm->setObjectName(QStringLiteral("LogViewForm"));
        LogViewForm->resize(1069, 633);
        verticalLayout = new QVBoxLayout(LogViewForm);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        searchToolWidget = new QWidget(LogViewForm);
        searchToolWidget->setObjectName(QStringLiteral("searchToolWidget"));
        horizontalLayout_2 = new QHBoxLayout(searchToolWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        seachLineEdit = new QLineEdit(searchToolWidget);
        seachLineEdit->setObjectName(QStringLiteral("seachLineEdit"));

        horizontalLayout_2->addWidget(seachLineEdit);

        caseSensCheckBox = new QCheckBox(searchToolWidget);
        caseSensCheckBox->setObjectName(QStringLiteral("caseSensCheckBox"));

        horizontalLayout_2->addWidget(caseSensCheckBox);

        backCheckBox = new QCheckBox(searchToolWidget);
        backCheckBox->setObjectName(QStringLiteral("backCheckBox"));

        horizontalLayout_2->addWidget(backCheckBox);

        searchPushButton = new QPushButton(searchToolWidget);
        searchPushButton->setObjectName(QStringLiteral("searchPushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/InfoViewer/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchPushButton->setIcon(icon);

        horizontalLayout_2->addWidget(searchPushButton);

        searchAllPushButton = new QPushButton(searchToolWidget);
        searchAllPushButton->setObjectName(QStringLiteral("searchAllPushButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/InfoViewer/images/searchAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchAllPushButton->setIcon(icon1);

        horizontalLayout_2->addWidget(searchAllPushButton);

        closePushButton = new QPushButton(searchToolWidget);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closePushButton->sizePolicy().hasHeightForWidth());
        closePushButton->setSizePolicy(sizePolicy);
        closePushButton->setMinimumSize(QSize(32, 0));
        closePushButton->setMaximumSize(QSize(32, 16777215));
        closePushButton->setFlat(true);

        horizontalLayout_2->addWidget(closePushButton);


        verticalLayout->addWidget(searchToolWidget);

        scrollArea = new QScrollArea(LogViewForm);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(false);
        logViewWidget = new CustomTextViewWidget();
        logViewWidget->setObjectName(QStringLiteral("logViewWidget"));
        logViewWidget->setGeometry(QRect(0, 0, 720, 497));
        logViewWidget->setFocusPolicy(Qt::WheelFocus);
        scrollArea->setWidget(logViewWidget);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_debugCheckBox = new QCheckBox(LogViewForm);
        m_debugCheckBox->setObjectName(QStringLiteral("m_debugCheckBox"));
        m_debugCheckBox->setChecked(true);

        horizontalLayout->addWidget(m_debugCheckBox);

        m_infoCheckBox = new QCheckBox(LogViewForm);
        m_infoCheckBox->setObjectName(QStringLiteral("m_infoCheckBox"));
        m_infoCheckBox->setChecked(true);

        horizontalLayout->addWidget(m_infoCheckBox);

        m_warnCheckBox = new QCheckBox(LogViewForm);
        m_warnCheckBox->setObjectName(QStringLiteral("m_warnCheckBox"));
        m_warnCheckBox->setChecked(true);

        horizontalLayout->addWidget(m_warnCheckBox);

        m_errorCheckBox = new QCheckBox(LogViewForm);
        m_errorCheckBox->setObjectName(QStringLiteral("m_errorCheckBox"));
        m_errorCheckBox->setChecked(true);

        horizontalLayout->addWidget(m_errorCheckBox);

        m_filterLineEdit = new QLineEdit(LogViewForm);
        m_filterLineEdit->setObjectName(QStringLiteral("m_filterLineEdit"));

        horizontalLayout->addWidget(m_filterLineEdit);

        m_applyFilterPushButton = new QPushButton(LogViewForm);
        m_applyFilterPushButton->setObjectName(QStringLiteral("m_applyFilterPushButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MainWindow/images/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_applyFilterPushButton->setIcon(icon2);

        horizontalLayout->addWidget(m_applyFilterPushButton);

        horizontalLayout->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LogViewForm);

        QMetaObject::connectSlotsByName(LogViewForm);
    } // setupUi

    void retranslateUi(QWidget *LogViewForm)
    {
        LogViewForm->setWindowTitle(QApplication::translate("LogViewForm", "Form", 0));
        caseSensCheckBox->setText(QApplication::translate("LogViewForm", "Case sensivity", 0));
        backCheckBox->setText(QApplication::translate("LogViewForm", "Seach backward", 0));
#ifndef QT_NO_TOOLTIP
        searchPushButton->setToolTip(QApplication::translate("LogViewForm", "Search", 0));
#endif // QT_NO_TOOLTIP
        searchPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        searchAllPushButton->setToolTip(QApplication::translate("LogViewForm", "Search all", 0));
#endif // QT_NO_TOOLTIP
        searchAllPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        closePushButton->setToolTip(QApplication::translate("LogViewForm", "Hide panel", 0));
#endif // QT_NO_TOOLTIP
        closePushButton->setText(QApplication::translate("LogViewForm", "X", 0));
        m_debugCheckBox->setText(QApplication::translate("LogViewForm", "Debug", 0));
        m_infoCheckBox->setText(QApplication::translate("LogViewForm", "Information", 0));
        m_warnCheckBox->setText(QApplication::translate("LogViewForm", "Warning", 0));
        m_errorCheckBox->setText(QApplication::translate("LogViewForm", "Error", 0));
#ifndef QT_NO_TOOLTIP
        m_applyFilterPushButton->setToolTip(QApplication::translate("LogViewForm", "Apply filter", 0));
#endif // QT_NO_TOOLTIP
        m_applyFilterPushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LogViewForm: public Ui_LogViewForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGVIEWFORM_H
