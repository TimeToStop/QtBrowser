/********************************************************************************
** Form generated from reading UI file 'createnewprojectQUqLjC.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CREATENEWPROJECTQUQLJC_H
#define CREATENEWPROJECTQUQLJC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateNewProject
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *project_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *project_path;
    QPushButton *browse;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *create;
    QPushButton *exit;

    void setupUi(QDialog *CreateNewProject)
    {
        if (CreateNewProject->objectName().isEmpty())
            CreateNewProject->setObjectName(QString::fromUtf8("CreateNewProject"));
        CreateNewProject->resize(557, 104);
        horizontalLayout = new QHBoxLayout(CreateNewProject);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(CreateNewProject);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        project_name = new QLineEdit(CreateNewProject);
        project_name->setObjectName(QString::fromUtf8("project_name"));

        horizontalLayout_2->addWidget(project_name);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(CreateNewProject);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        project_path = new QLineEdit(CreateNewProject);
        project_path->setObjectName(QString::fromUtf8("project_path"));

        horizontalLayout_4->addWidget(project_path);

        browse = new QPushButton(CreateNewProject);
        browse->setObjectName(QString::fromUtf8("browse"));

        horizontalLayout_4->addWidget(browse);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        create = new QPushButton(CreateNewProject);
        create->setObjectName(QString::fromUtf8("create"));

        horizontalLayout_3->addWidget(create);

        exit = new QPushButton(CreateNewProject);
        exit->setObjectName(QString::fromUtf8("exit"));

        horizontalLayout_3->addWidget(exit);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(CreateNewProject);

        QMetaObject::connectSlotsByName(CreateNewProject);
    } // setupUi

    void retranslateUi(QDialog *CreateNewProject)
    {
        CreateNewProject->setWindowTitle(QCoreApplication::translate("CreateNewProject", "Create New Project", nullptr));
        label->setText(QCoreApplication::translate("CreateNewProject", "Project Name", nullptr));
        label_2->setText(QCoreApplication::translate("CreateNewProject", "Project Path  ", nullptr));
        browse->setText(QCoreApplication::translate("CreateNewProject", "Browse", nullptr));
        create->setText(QCoreApplication::translate("CreateNewProject", "Create", nullptr));
        exit->setText(QCoreApplication::translate("CreateNewProject", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateNewProject: public Ui_CreateNewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CREATENEWPROJECTQUQLJC_H
