/********************************************************************************
** Form generated from reading UI file 'addpageelementQykUWj.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADDPAGEELEMENTQYKUWJ_H
#define ADDPAGEELEMENTQYKUWJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "console.h"

QT_BEGIN_NAMESPACE

class Ui_AddPageElement
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *name;
    QLabel *label_7;
    QCheckBox *redirect;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_2;
    QComboBox *classes;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *tag;
    QLabel *label_3;
    QLineEdit *path;
    QLabel *label_8;
    QLabel *label_4;
    QLineEdit *id;
    Console *inner;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *create;
    QPushButton *exit;

    void setupUi(QDialog *AddPageElement)
    {
        if (AddPageElement->objectName().isEmpty())
            AddPageElement->setObjectName(QString::fromUtf8("AddPageElement"));
        AddPageElement->resize(484, 438);
        horizontalLayout = new QHBoxLayout(AddPageElement);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        name = new QLineEdit(AddPageElement);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        label_7 = new QLabel(AddPageElement);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        redirect = new QCheckBox(AddPageElement);
        redirect->setObjectName(QString::fromUtf8("redirect"));

        gridLayout->addWidget(redirect, 1, 1, 1, 1);

        label = new QLabel(AddPageElement);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);

        groupBox = new QGroupBox(AddPageElement);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        classes = new QComboBox(groupBox);
        classes->setObjectName(QString::fromUtf8("classes"));

        gridLayout_2->addWidget(classes, 3, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout_5, 5, 0, 1, 1);

        tag = new QLineEdit(groupBox);
        tag->setObjectName(QString::fromUtf8("tag"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tag->sizePolicy().hasHeightForWidth());
        tag->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(tag, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        path = new QLineEdit(groupBox);
        path->setObjectName(QString::fromUtf8("path"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(path->sizePolicy().hasHeightForWidth());
        path->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(path, 2, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        id = new QLineEdit(groupBox);
        id->setObjectName(QString::fromUtf8("id"));
        sizePolicy2.setHeightForWidth(id->sizePolicy().hasHeightForWidth());
        id->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(id, 1, 1, 1, 1);

        inner = new Console(groupBox);
        inner->setObjectName(QString::fromUtf8("inner"));

        gridLayout_2->addWidget(inner, 5, 1, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_2);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        create = new QPushButton(AddPageElement);
        create->setObjectName(QString::fromUtf8("create"));

        horizontalLayout_2->addWidget(create);

        exit = new QPushButton(AddPageElement);
        exit->setObjectName(QString::fromUtf8("exit"));

        horizontalLayout_2->addWidget(exit);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(AddPageElement);

        QMetaObject::connectSlotsByName(AddPageElement);
    } // setupUi

    void retranslateUi(QDialog *AddPageElement)
    {
        AddPageElement->setWindowTitle(QCoreApplication::translate("AddPageElement", "AddPageElement", nullptr));
        label_7->setText(QCoreApplication::translate("AddPageElement", "On Click", nullptr));
        redirect->setText(QCoreApplication::translate("AddPageElement", "Wait For Redirection", nullptr));
        label->setText(QCoreApplication::translate("AddPageElement", "Name of Element:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AddPageElement", "Info:", nullptr));
        label_2->setText(QCoreApplication::translate("AddPageElement", "Classes:", nullptr));
        label_5->setText(QCoreApplication::translate("AddPageElement", "Inner:", nullptr));
        label_3->setText(QCoreApplication::translate("AddPageElement", "Tag:", nullptr));
        label_8->setText(QCoreApplication::translate("AddPageElement", "Path:", nullptr));
        label_4->setText(QCoreApplication::translate("AddPageElement", "Id:", nullptr));
        create->setText(QCoreApplication::translate("AddPageElement", "Create", nullptr));
        exit->setText(QCoreApplication::translate("AddPageElement", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPageElement: public Ui_AddPageElement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADDPAGEELEMENTQYKUWJ_H
