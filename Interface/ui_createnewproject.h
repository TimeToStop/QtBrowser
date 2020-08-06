/********************************************************************************
** Form generated from reading UI file 'createnewprojectDzUpGZ.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATENEWPROJECTDZUPGZ_H
#define CREATENEWPROJECTDZUPGZ_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateNewProject
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *project_name;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *project_dir;
    QSpacerItem *verticalSpacer;
    QPushButton *browse;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *accept;
    QPushButton *exit;

    void setupUi(QDialog *CreateNewProject)
    {
        if (CreateNewProject->objectName().isEmpty())
            CreateNewProject->setObjectName(QString::fromUtf8("CreateNewProject"));
        CreateNewProject->resize(562, 208);
        horizontalLayout = new QHBoxLayout(CreateNewProject);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(CreateNewProject);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        project_name = new QLineEdit(widget);
        project_name->setObjectName(QString::fromUtf8("project_name"));

        gridLayout->addWidget(project_name, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        project_dir = new QLineEdit(widget);
        project_dir->setObjectName(QString::fromUtf8("project_dir"));

        gridLayout->addWidget(project_dir, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        browse = new QPushButton(widget);
        browse->setObjectName(QString::fromUtf8("browse"));

        gridLayout->addWidget(browse, 0, 2, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        verticalLayout->addWidget(widget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        accept = new QPushButton(CreateNewProject);
        accept->setObjectName(QString::fromUtf8("accept"));

        horizontalLayout_2->addWidget(accept);

        exit = new QPushButton(CreateNewProject);
        exit->setObjectName(QString::fromUtf8("exit"));

        horizontalLayout_2->addWidget(exit);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(CreateNewProject);

        QMetaObject::connectSlotsByName(CreateNewProject);
    } // setupUi

    void retranslateUi(QDialog *CreateNewProject)
    {
        CreateNewProject->setWindowTitle(QCoreApplication::translate("CreateNewProject", "CreateNewProject", nullptr));
        label_2->setText(QCoreApplication::translate("CreateNewProject", "Project name:", nullptr));
        label->setText(QCoreApplication::translate("CreateNewProject", "Project directory:", nullptr));
        browse->setText(QCoreApplication::translate("CreateNewProject", "Browse", nullptr));
        accept->setText(QCoreApplication::translate("CreateNewProject", "Accept", nullptr));
        exit->setText(QCoreApplication::translate("CreateNewProject", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateNewProject: public Ui_CreateNewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATENEWPROJECTDZUPGZ_H
