/********************************************************************************
** Form generated from reading UI file 'mainwindowltxVcv.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWLTXVCV_H
#define MAINWINDOWLTXVCV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "browser.h"
#include "console.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *create_new_project;
    QAction *open_project;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *project_name;
    QSpacerItem *horizontalSpacer;
    QPushButton *run_inteliji;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *url;
    QPushButton *load;
    QProgressBar *progress;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLineEdit *tag;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QLineEdit *id;
    QLabel *label_4;
    QComboBox *classes;
    QLabel *label_2;
    Console *inner;
    Browser *browser;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *application;
    QPushButton *run_app;
    QPushButton *stop_app;
    QSpacerItem *verticalSpacer_2;
    Console *console;
    QMenuBar *menuBar;
    QMenu *menuProject;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1769, 1034);
        create_new_project = new QAction(MainWindow);
        create_new_project->setObjectName(QString::fromUtf8("create_new_project"));
        open_project = new QAction(MainWindow);
        open_project->setObjectName(QString::fromUtf8("open_project"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        project_name = new QLabel(centralWidget);
        project_name->setObjectName(QString::fromUtf8("project_name"));

        horizontalLayout_2->addWidget(project_name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        run_inteliji = new QPushButton(centralWidget);
        run_inteliji->setObjectName(QString::fromUtf8("run_inteliji"));

        horizontalLayout_2->addWidget(run_inteliji);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_6);

        url = new QLineEdit(groupBox_3);
        url->setObjectName(QString::fromUtf8("url"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(url->sizePolicy().hasHeightForWidth());
        url->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(url);

        load = new QPushButton(groupBox_3);
        load->setObjectName(QString::fromUtf8("load"));

        horizontalLayout_3->addWidget(load);


        verticalLayout_4->addLayout(horizontalLayout_3);

        progress = new QProgressBar(groupBox_3);
        progress->setObjectName(QString::fromUtf8("progress"));
        sizePolicy1.setHeightForWidth(progress->sizePolicy().hasHeightForWidth());
        progress->setSizePolicy(sizePolicy1);
        progress->setValue(24);

        verticalLayout_4->addWidget(progress);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tag = new QLineEdit(groupBox);
        tag->setObjectName(QString::fromUtf8("tag"));
        sizePolicy1.setHeightForWidth(tag->sizePolicy().hasHeightForWidth());
        tag->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(tag, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout_5, 3, 0, 1, 1);

        id = new QLineEdit(groupBox);
        id->setObjectName(QString::fromUtf8("id"));
        sizePolicy1.setHeightForWidth(id->sizePolicy().hasHeightForWidth());
        id->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(id, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        classes = new QComboBox(groupBox);
        classes->setObjectName(QString::fromUtf8("classes"));

        gridLayout_2->addWidget(classes, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        inner = new Console(groupBox);
        inner->setObjectName(QString::fromUtf8("inner"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(inner->sizePolicy().hasHeightForWidth());
        inner->setSizePolicy(sizePolicy2);
        inner->setMinimumSize(QSize(200, 0));

        gridLayout_2->addWidget(inner, 3, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        browser = new Browser(centralWidget);
        browser->setObjectName(QString::fromUtf8("browser"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(browser->sizePolicy().hasHeightForWidth());
        browser->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(browser, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        application = new QLineEdit(groupBox_2);
        application->setObjectName(QString::fromUtf8("application"));
        sizePolicy1.setHeightForWidth(application->sizePolicy().hasHeightForWidth());
        application->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(application);

        run_app = new QPushButton(groupBox_2);
        run_app->setObjectName(QString::fromUtf8("run_app"));

        horizontalLayout_5->addWidget(run_app);

        stop_app = new QPushButton(groupBox_2);
        stop_app->setObjectName(QString::fromUtf8("stop_app"));

        horizontalLayout_5->addWidget(stop_app);


        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_6);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

        console = new Console(centralWidget);
        console->setObjectName(QString::fromUtf8("console"));
        sizePolicy3.setHeightForWidth(console->sizePolicy().hasHeightForWidth());
        console->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(console, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1769, 21));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QString::fromUtf8("menuProject"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuProject->menuAction());
        menuProject->addAction(create_new_project);
        menuProject->addAction(open_project);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        create_new_project->setText(QCoreApplication::translate("MainWindow", "New Project", nullptr));
        open_project->setText(QCoreApplication::translate("MainWindow", "Open Project", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Project:", nullptr));
        project_name->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        run_inteliji->setText(QCoreApplication::translate("MainWindow", "Run Inteliji", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Browser:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Url:", nullptr));
        url->setText(QCoreApplication::translate("MainWindow", "http://google.com/", nullptr));
        load->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Hovered Element Info:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Tag:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Inner:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Id:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Classes:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Application:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Version", nullptr));
        run_app->setText(QCoreApplication::translate("MainWindow", " Run Application", nullptr));
        stop_app->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        menuProject->setTitle(QCoreApplication::translate("MainWindow", "Project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWLTXVCV_H
