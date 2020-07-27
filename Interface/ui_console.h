/********************************************************************************
** Form generated from reading UI file 'consoleUKpchy.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONSOLEUKPCHY_H
#define CONSOLEUKPCHY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "consoleview.h"

QT_BEGIN_NAMESPACE

class Ui_Console
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    ConsoleView *console_view;
    QScrollBar *vertical;
    QScrollBar *horizontal;

    void setupUi(QWidget *Console)
    {
        if (Console->objectName().isEmpty())
            Console->setObjectName(QString::fromUtf8("Console"));
        Console->resize(1052, 553);
        horizontalLayout = new QHBoxLayout(Console);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        console_view = new ConsoleView(Console);
        console_view->setObjectName(QString::fromUtf8("console_view"));

        horizontalLayout_2->addWidget(console_view);

        vertical = new QScrollBar(Console);
        vertical->setObjectName(QString::fromUtf8("vertical"));
        vertical->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(vertical);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontal = new QScrollBar(Console);
        horizontal->setObjectName(QString::fromUtf8("horizontal"));
        horizontal->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontal);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Console);

        QMetaObject::connectSlotsByName(Console);
    } // setupUi

    void retranslateUi(QWidget *Console)
    {
        Console->setWindowTitle(QCoreApplication::translate("Console", "Console", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Console: public Ui_Console {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONSOLEUKPCHY_H
