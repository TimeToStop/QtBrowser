/********************************************************************************
** Form generated from reading UI file 'registerpagegpzRVE.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef REGISTERPAGEGPZRVE_H
#define REGISTERPAGEGPZRVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterPage
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLineEdit *name;
    QLineEdit *request;
    QLineEdit *target;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *create;
    QPushButton *exit;

    void setupUi(QDialog *RegisterPage)
    {
        if (RegisterPage->objectName().isEmpty())
            RegisterPage->setObjectName(QString::fromUtf8("RegisterPage"));
        RegisterPage->resize(632, 127);
        horizontalLayout = new QHBoxLayout(RegisterPage);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        name = new QLineEdit(RegisterPage);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        request = new QLineEdit(RegisterPage);
        request->setObjectName(QString::fromUtf8("request"));

        gridLayout->addWidget(request, 1, 1, 1, 1);

        target = new QLineEdit(RegisterPage);
        target->setObjectName(QString::fromUtf8("target"));

        gridLayout->addWidget(target, 2, 1, 1, 1);

        label = new QLabel(RegisterPage);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(RegisterPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(RegisterPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        create = new QPushButton(RegisterPage);
        create->setObjectName(QString::fromUtf8("create"));

        horizontalLayout_2->addWidget(create);

        exit = new QPushButton(RegisterPage);
        exit->setObjectName(QString::fromUtf8("exit"));

        horizontalLayout_2->addWidget(exit);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(RegisterPage);

        QMetaObject::connectSlotsByName(RegisterPage);
    } // setupUi

    void retranslateUi(QDialog *RegisterPage)
    {
        RegisterPage->setWindowTitle(QCoreApplication::translate("RegisterPage", "RegisterPage", nullptr));
        label->setText(QCoreApplication::translate("RegisterPage", "Page Name:", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterPage", "Request URL:", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterPage", "Target URL:", nullptr));
        create->setText(QCoreApplication::translate("RegisterPage", "Create", nullptr));
        exit->setText(QCoreApplication::translate("RegisterPage", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterPage: public Ui_RegisterPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // REGISTERPAGEGPZRVE_H
