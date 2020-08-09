/********************************************************************************
** Form generated from reading UI file 'mainwindowwFVhgu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWWFVHGU_H
#define MAINWINDOWWFVHGU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "browser.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *create_new_project;
    QAction *open_project;
    QAction *actionPath_To_Maven;
    QAction *actionPath_To_Inteliji_Idea;
    QAction *actionDebug_Settings;
    QAction *actionShow_HTML_Source;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *project_name;
    QSpacerItem *horizontalSpacer;
    QPushButton *generate;
    QPushButton *run_app;
    QPushButton *stop;
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
    QPushButton *register_page;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QComboBox *pages;
    QProgressBar *progress;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QTreeWidget *elements;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLineEdit *tag;
    QLabel *label_2;
    QLineEdit *id;
    QLabel *label_4;
    QLabel *label_3;
    QComboBox *classes;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QLabel *label_8;
    QLineEdit *path;
    QTextBrowser *inner;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    Browser *browser;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_9;
    QTextBrowser *console;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_8;
    QTextBrowser *application_output;
    QVBoxLayout *verticalLayout_8;
    QTextBrowser *html_source;
    QMenuBar *menuBar;
    QMenu *menuProject;
    QMenu *menuSettings;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1769, 1034);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        create_new_project = new QAction(MainWindow);
        create_new_project->setObjectName(QString::fromUtf8("create_new_project"));
        open_project = new QAction(MainWindow);
        open_project->setObjectName(QString::fromUtf8("open_project"));
        actionPath_To_Maven = new QAction(MainWindow);
        actionPath_To_Maven->setObjectName(QString::fromUtf8("actionPath_To_Maven"));
        actionPath_To_Inteliji_Idea = new QAction(MainWindow);
        actionPath_To_Inteliji_Idea->setObjectName(QString::fromUtf8("actionPath_To_Inteliji_Idea"));
        actionDebug_Settings = new QAction(MainWindow);
        actionDebug_Settings->setObjectName(QString::fromUtf8("actionDebug_Settings"));
        actionShow_HTML_Source = new QAction(MainWindow);
        actionShow_HTML_Source->setObjectName(QString::fromUtf8("actionShow_HTML_Source"));
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

        generate = new QPushButton(centralWidget);
        generate->setObjectName(QString::fromUtf8("generate"));

        horizontalLayout_2->addWidget(generate);

        run_app = new QPushButton(centralWidget);
        run_app->setObjectName(QString::fromUtf8("run_app"));

        horizontalLayout_2->addWidget(run_app);

        stop = new QPushButton(centralWidget);
        stop->setObjectName(QString::fromUtf8("stop"));

        horizontalLayout_2->addWidget(stop);

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
        label_6->setMaximumSize(QSize(35, 16777215));

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

        register_page = new QPushButton(groupBox_3);
        register_page->setObjectName(QString::fromUtf8("register_page"));

        horizontalLayout_3->addWidget(register_page);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_7->addWidget(label_9);

        pages = new QComboBox(groupBox_3);
        pages->addItem(QString());
        pages->setObjectName(QString::fromUtf8("pages"));
        sizePolicy1.setHeightForWidth(pages->sizePolicy().hasHeightForWidth());
        pages->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pages);


        verticalLayout_4->addLayout(horizontalLayout_7);

        progress = new QProgressBar(groupBox_3);
        progress->setObjectName(QString::fromUtf8("progress"));
        sizePolicy1.setHeightForWidth(progress->sizePolicy().hasHeightForWidth());
        progress->setSizePolicy(sizePolicy1);
        progress->setValue(24);
        progress->setInvertedAppearance(false);

        verticalLayout_4->addWidget(progress);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        elements = new QTreeWidget(groupBox_4);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        elements->setHeaderItem(__qtreewidgetitem);
        elements->setObjectName(QString::fromUtf8("elements"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(elements->sizePolicy().hasHeightForWidth());
        elements->setSizePolicy(sizePolicy2);
        elements->setColumnCount(2);
        elements->header()->setVisible(false);

        verticalLayout_7->addWidget(elements);


        horizontalLayout_6->addLayout(verticalLayout_7);


        verticalLayout_3->addWidget(groupBox_4);

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

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        id = new QLineEdit(groupBox);
        id->setObjectName(QString::fromUtf8("id"));
        sizePolicy1.setHeightForWidth(id->sizePolicy().hasHeightForWidth());
        id->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(id, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        classes = new QComboBox(groupBox);
        classes->setObjectName(QString::fromUtf8("classes"));

        gridLayout_2->addWidget(classes, 3, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout_5, 4, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        path = new QLineEdit(groupBox);
        path->setObjectName(QString::fromUtf8("path"));
        sizePolicy1.setHeightForWidth(path->sizePolicy().hasHeightForWidth());
        path->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(path, 2, 1, 1, 1);

        inner = new QTextBrowser(groupBox);
        inner->setObjectName(QString::fromUtf8("inner"));
        sizePolicy2.setHeightForWidth(inner->sizePolicy().hasHeightForWidth());
        inner->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(inner, 4, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        browser = new Browser(centralWidget);
        browser->setObjectName(QString::fromUtf8("browser"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(browser->sizePolicy().hasHeightForWidth());
        browser->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(browser);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_9 = new QHBoxLayout(tab);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        console = new QTextBrowser(tab);
        console->setObjectName(QString::fromUtf8("console"));

        horizontalLayout_9->addWidget(console);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_8 = new QHBoxLayout(tab_2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        application_output = new QTextBrowser(tab_2);
        application_output->setObjectName(QString::fromUtf8("application_output"));

        horizontalLayout_8->addWidget(application_output);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_6->addWidget(tabWidget);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        html_source = new QTextBrowser(centralWidget);
        html_source->setObjectName(QString::fromUtf8("html_source"));
        sizePolicy3.setHeightForWidth(html_source->sizePolicy().hasHeightForWidth());
        html_source->setSizePolicy(sizePolicy3);

        verticalLayout_8->addWidget(html_source);


        horizontalLayout_4->addLayout(verticalLayout_8);


        gridLayout->addLayout(horizontalLayout_4, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1769, 21));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QString::fromUtf8("menuProject"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuProject->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuProject->addAction(create_new_project);
        menuProject->addAction(open_project);
        menuSettings->addAction(actionPath_To_Maven);
        menuSettings->addAction(actionPath_To_Inteliji_Idea);
        menuSettings->addAction(actionDebug_Settings);
        menuView->addAction(actionShow_HTML_Source);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        create_new_project->setText(QCoreApplication::translate("MainWindow", "New Project", nullptr));
        open_project->setText(QCoreApplication::translate("MainWindow", "Open Project", nullptr));
        actionPath_To_Maven->setText(QCoreApplication::translate("MainWindow", "Path To Maven", nullptr));
        actionPath_To_Inteliji_Idea->setText(QCoreApplication::translate("MainWindow", "Path To Inteliji Idea", nullptr));
        actionDebug_Settings->setText(QCoreApplication::translate("MainWindow", "Project Settings", nullptr));
        actionShow_HTML_Source->setText(QCoreApplication::translate("MainWindow", "Show HTML Source", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Project:", nullptr));
        project_name->setText(QString());
        generate->setText(QCoreApplication::translate("MainWindow", "Generate Meta", nullptr));
        run_app->setText(QCoreApplication::translate("MainWindow", "Run Appliaction", nullptr));
        stop->setText(QCoreApplication::translate("MainWindow", "Stop Application", nullptr));
        run_inteliji->setText(QCoreApplication::translate("MainWindow", "Run Inteliji", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Browser:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Url:", nullptr));
        url->setText(QCoreApplication::translate("MainWindow", "http://google.com/", nullptr));
        load->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        register_page->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Pages:", nullptr));
        pages->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));

        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Elements:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Hovered Element Info:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Classes:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Id:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Tag:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Inner:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Path:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Console", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Application  Output", nullptr));
        menuProject->setTitle(QCoreApplication::translate("MainWindow", "Project", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWWFVHGU_H
