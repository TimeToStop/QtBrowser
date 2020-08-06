/********************************************************************************
** Form generated from reading UI file 'openprojectIwczjg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef OPENPROJECTIWCZJG_H
#define OPENPROJECTIWCZJG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OpenProject
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QListWidget *projects;

    void setupUi(QDialog *OpenProject)
    {
        if (OpenProject->objectName().isEmpty())
            OpenProject->setObjectName(QString::fromUtf8("OpenProject"));
        OpenProject->resize(1058, 478);
        horizontalLayout = new QHBoxLayout(OpenProject);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(OpenProject);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        projects = new QListWidget(OpenProject);
        projects->setObjectName(QString::fromUtf8("projects"));

        gridLayout->addWidget(projects, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(OpenProject);

        QMetaObject::connectSlotsByName(OpenProject);
    } // setupUi

    void retranslateUi(QDialog *OpenProject)
    {
        OpenProject->setWindowTitle(QCoreApplication::translate("OpenProject", "OpenProject", nullptr));
        label_2->setText(QCoreApplication::translate("OpenProject", "From Recent:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenProject: public Ui_OpenProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // OPENPROJECTIWCZJG_H
