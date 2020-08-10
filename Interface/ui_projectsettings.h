/********************************************************************************
** Form generated from reading UI file 'projectsettingsuKxNTJ.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PROJECTSETTINGSUKXNTJ_H
#define PROJECTSETTINGSUKXNTJ_H

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

class Ui_ProjectSettings
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *path_to_properties;
    QLabel *label_2;
    QLineEdit *path_to_port;
    QLineEdit *path_to_elements_meta;
    QPushButton *browse_properties;
    QPushButton *browse_port;
    QPushButton *browse_page_elements;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *accept;
    QPushButton *exit;

    void setupUi(QDialog *ProjectSettings)
    {
        if (ProjectSettings->objectName().isEmpty())
            ProjectSettings->setObjectName(QString::fromUtf8("ProjectSettings"));
        ProjectSettings->resize(600, 136);
        horizontalLayout = new QHBoxLayout(ProjectSettings);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(ProjectSettings);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(ProjectSettings);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        path_to_properties = new QLineEdit(ProjectSettings);
        path_to_properties->setObjectName(QString::fromUtf8("path_to_properties"));

        gridLayout->addWidget(path_to_properties, 0, 1, 1, 1);

        label_2 = new QLabel(ProjectSettings);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        path_to_port = new QLineEdit(ProjectSettings);
        path_to_port->setObjectName(QString::fromUtf8("path_to_port"));

        gridLayout->addWidget(path_to_port, 1, 1, 1, 1);

        path_to_elements_meta = new QLineEdit(ProjectSettings);
        path_to_elements_meta->setObjectName(QString::fromUtf8("path_to_elements_meta"));

        gridLayout->addWidget(path_to_elements_meta, 2, 1, 1, 1);

        browse_properties = new QPushButton(ProjectSettings);
        browse_properties->setObjectName(QString::fromUtf8("browse_properties"));

        gridLayout->addWidget(browse_properties, 0, 2, 1, 1);

        browse_port = new QPushButton(ProjectSettings);
        browse_port->setObjectName(QString::fromUtf8("browse_port"));

        gridLayout->addWidget(browse_port, 1, 2, 1, 1);

        browse_page_elements = new QPushButton(ProjectSettings);
        browse_page_elements->setObjectName(QString::fromUtf8("browse_page_elements"));

        gridLayout->addWidget(browse_page_elements, 2, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        accept = new QPushButton(ProjectSettings);
        accept->setObjectName(QString::fromUtf8("accept"));

        horizontalLayout_3->addWidget(accept);

        exit = new QPushButton(ProjectSettings);
        exit->setObjectName(QString::fromUtf8("exit"));

        horizontalLayout_3->addWidget(exit);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(ProjectSettings);

        QMetaObject::connectSlotsByName(ProjectSettings);
    } // setupUi

    void retranslateUi(QDialog *ProjectSettings)
    {
        ProjectSettings->setWindowTitle(QCoreApplication::translate("ProjectSettings", "ProjectSettings", nullptr));
        label_3->setText(QCoreApplication::translate("ProjectSettings", "Path To Page Elements", nullptr));
        label->setText(QCoreApplication::translate("ProjectSettings", "Path To Properties", nullptr));
        label_2->setText(QCoreApplication::translate("ProjectSettings", "Path To Port", nullptr));
        browse_properties->setText(QCoreApplication::translate("ProjectSettings", "Browse", nullptr));
        browse_port->setText(QCoreApplication::translate("ProjectSettings", "Browse", nullptr));
        browse_page_elements->setText(QCoreApplication::translate("ProjectSettings", "Browse", nullptr));
        accept->setText(QCoreApplication::translate("ProjectSettings", "Accept", nullptr));
        exit->setText(QCoreApplication::translate("ProjectSettings", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectSettings: public Ui_ProjectSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PROJECTSETTINGSUKXNTJ_H
