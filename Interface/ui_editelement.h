/********************************************************************************
** Form generated from reading UI file 'editelementAKcRdF.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef EDITELEMENTAKCRDF_H
#define EDITELEMENTAKCRDF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditElement
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *name;
    QLabel *label_3;
    QComboBox *type;
    QLabel *label;
    QCheckBox *redirect;
    QCheckBox *is_array;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *apply;
    QPushButton *exit;

    void setupUi(QWidget *EditElement)
    {
        if (EditElement->objectName().isEmpty())
            EditElement->setObjectName(QString::fromUtf8("EditElement"));
        EditElement->resize(359, 162);
        horizontalLayout = new QHBoxLayout(EditElement);
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
        label_2 = new QLabel(EditElement);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        name = new QLineEdit(EditElement);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        label_3 = new QLabel(EditElement);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        type = new QComboBox(EditElement);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName(QString::fromUtf8("type"));

        gridLayout->addWidget(type, 1, 1, 1, 1);

        label = new QLabel(EditElement);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        redirect = new QCheckBox(EditElement);
        redirect->setObjectName(QString::fromUtf8("redirect"));

        gridLayout->addWidget(redirect, 2, 1, 1, 1);

        is_array = new QCheckBox(EditElement);
        is_array->setObjectName(QString::fromUtf8("is_array"));
        is_array->setEnabled(false);
        is_array->setCheckable(true);

        gridLayout->addWidget(is_array, 3, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        apply = new QPushButton(EditElement);
        apply->setObjectName(QString::fromUtf8("apply"));

        horizontalLayout_2->addWidget(apply);

        exit = new QPushButton(EditElement);
        exit->setObjectName(QString::fromUtf8("exit"));

        horizontalLayout_2->addWidget(exit);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(EditElement);

        QMetaObject::connectSlotsByName(EditElement);
    } // setupUi

    void retranslateUi(QWidget *EditElement)
    {
        EditElement->setWindowTitle(QCoreApplication::translate("EditElement", "EditElement", nullptr));
        label_2->setText(QCoreApplication::translate("EditElement", "Type:", nullptr));
        label_3->setText(QCoreApplication::translate("EditElement", "Redirect:", nullptr));
        type->setItemText(0, QCoreApplication::translate("EditElement", "TextInput", nullptr));
        type->setItemText(1, QCoreApplication::translate("EditElement", "Readable", nullptr));
        type->setItemText(2, QCoreApplication::translate("EditElement", "Clickable", nullptr));

        label->setText(QCoreApplication::translate("EditElement", "Name:", nullptr));
        redirect->setText(QCoreApplication::translate("EditElement", "Wait For Redirection", nullptr));
        is_array->setText(QCoreApplication::translate("EditElement", "Is Array", nullptr));
        apply->setText(QCoreApplication::translate("EditElement", "Apply", nullptr));
        exit->setText(QCoreApplication::translate("EditElement", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditElement: public Ui_EditElement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDITELEMENTAKCRDF_H
