/********************************************************************************
** Form generated from reading UI file 'addarrayelementBRmJhp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADDARRAYELEMENTBRMJHP_H
#define ADDARRAYELEMENTBRMJHP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddArrayElement
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLineEdit *name;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *path;
    QComboBox *type;
    QCheckBox *wait_for_redirect;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *add;
    QPushButton *exit;

    void setupUi(QDialog *AddArrayElement)
    {
        if (AddArrayElement->objectName().isEmpty())
            AddArrayElement->setObjectName(QString::fromUtf8("AddArrayElement"));
        AddArrayElement->resize(334, 150);
        horizontalLayout = new QHBoxLayout(AddArrayElement);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        name = new QLineEdit(AddArrayElement);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 0, 2, 1, 1);

        label = new QLabel(AddArrayElement);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(AddArrayElement);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(AddArrayElement);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        path = new QLineEdit(AddArrayElement);
        path->setObjectName(QString::fromUtf8("path"));
        path->setReadOnly(true);

        gridLayout->addWidget(path, 3, 2, 1, 1);

        type = new QComboBox(AddArrayElement);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName(QString::fromUtf8("type"));

        gridLayout->addWidget(type, 1, 2, 1, 1);

        wait_for_redirect = new QCheckBox(AddArrayElement);
        wait_for_redirect->setObjectName(QString::fromUtf8("wait_for_redirect"));

        gridLayout->addWidget(wait_for_redirect, 2, 2, 1, 1);

        label_3 = new QLabel(AddArrayElement);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        add = new QPushButton(AddArrayElement);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_2->addWidget(add);

        exit = new QPushButton(AddArrayElement);
        exit->setObjectName(QString::fromUtf8("exit"));

        horizontalLayout_2->addWidget(exit);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(AddArrayElement);

        QMetaObject::connectSlotsByName(AddArrayElement);
    } // setupUi

    void retranslateUi(QDialog *AddArrayElement)
    {
        AddArrayElement->setWindowTitle(QCoreApplication::translate("AddArrayElement", "AddArrayElement", nullptr));
        label->setText(QCoreApplication::translate("AddArrayElement", "Name:", nullptr));
        label_4->setText(QCoreApplication::translate("AddArrayElement", "Path:", nullptr));
        label_2->setText(QCoreApplication::translate("AddArrayElement", "Type:", nullptr));
        type->setItemText(0, QCoreApplication::translate("AddArrayElement", "TextInput", nullptr));
        type->setItemText(1, QCoreApplication::translate("AddArrayElement", "Readable", nullptr));
        type->setItemText(2, QCoreApplication::translate("AddArrayElement", "Clickable", nullptr));

        wait_for_redirect->setText(QCoreApplication::translate("AddArrayElement", "Wait For Redirect", nullptr));
        label_3->setText(QCoreApplication::translate("AddArrayElement", "Redirect:", nullptr));
        add->setText(QCoreApplication::translate("AddArrayElement", "Add", nullptr));
        exit->setText(QCoreApplication::translate("AddArrayElement", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddArrayElement: public Ui_AddArrayElement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADDARRAYELEMENTBRMJHP_H
