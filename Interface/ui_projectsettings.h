/********************************************************************************
** Form generated from reading UI file 'projectsettingsvWHuCL.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PROJECTSETTINGSVWHUCL_H
#define PROJECTSETTINGSVWHUCL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
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
    QPushButton *browse_page_elements;
    QLineEdit *path_to_port;
    QPushButton *browse_port;
    QVBoxLayout *verticalLayout_2;
    QPushButton *add_js;
    QPushButton *remove_js;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *path_to_elements_meta;
    QTableWidget *default_js;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *accept;
    QPushButton *exit;

    void setupUi(QDialog *ProjectSettings)
    {
        if (ProjectSettings->objectName().isEmpty())
            ProjectSettings->setObjectName(QString::fromUtf8("ProjectSettings"));
        ProjectSettings->resize(614, 290);
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
        browse_page_elements = new QPushButton(ProjectSettings);
        browse_page_elements->setObjectName(QString::fromUtf8("browse_page_elements"));

        gridLayout->addWidget(browse_page_elements, 1, 2, 1, 1);

        path_to_port = new QLineEdit(ProjectSettings);
        path_to_port->setObjectName(QString::fromUtf8("path_to_port"));

        gridLayout->addWidget(path_to_port, 0, 1, 1, 1);

        browse_port = new QPushButton(ProjectSettings);
        browse_port->setObjectName(QString::fromUtf8("browse_port"));

        gridLayout->addWidget(browse_port, 0, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        add_js = new QPushButton(ProjectSettings);
        add_js->setObjectName(QString::fromUtf8("add_js"));

        verticalLayout_2->addWidget(add_js);

        remove_js = new QPushButton(ProjectSettings);
        remove_js->setObjectName(QString::fromUtf8("remove_js"));

        verticalLayout_2->addWidget(remove_js);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_2, 3, 2, 1, 1);

        label_2 = new QLabel(ProjectSettings);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(ProjectSettings);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(ProjectSettings);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_3, 3, 0, 1, 1);

        path_to_elements_meta = new QLineEdit(ProjectSettings);
        path_to_elements_meta->setObjectName(QString::fromUtf8("path_to_elements_meta"));

        gridLayout->addWidget(path_to_elements_meta, 1, 1, 1, 1);

        default_js = new QTableWidget(ProjectSettings);
        if (default_js->columnCount() < 1)
            default_js->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        default_js->setHorizontalHeaderItem(0, __qtablewidgetitem);
        default_js->setObjectName(QString::fromUtf8("default_js"));

        gridLayout->addWidget(default_js, 3, 1, 1, 1);


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
        browse_page_elements->setText(QCoreApplication::translate("ProjectSettings", "Browse", nullptr));
        browse_port->setText(QCoreApplication::translate("ProjectSettings", "Browse", nullptr));
        add_js->setText(QCoreApplication::translate("ProjectSettings", "Add", nullptr));
        remove_js->setText(QCoreApplication::translate("ProjectSettings", "Remove", nullptr));
        label_2->setText(QCoreApplication::translate("ProjectSettings", "Path To Port", nullptr));
        label_3->setText(QCoreApplication::translate("ProjectSettings", "Path To Page Elements", nullptr));
        label_4->setText(QCoreApplication::translate("ProjectSettings", "Default JS", nullptr));
        QTableWidgetItem *___qtablewidgetitem = default_js->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ProjectSettings", "Path", nullptr));
        accept->setText(QCoreApplication::translate("ProjectSettings", "Accept", nullptr));
        exit->setText(QCoreApplication::translate("ProjectSettings", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectSettings: public Ui_ProjectSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PROJECTSETTINGSVWHUCL_H
