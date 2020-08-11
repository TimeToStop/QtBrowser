/********************************************************************************
** Form generated from reading UI file 'mainwindowKNYPeo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWKNYPEO_H
#define MAINWINDOWKNYPEO_H

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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
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
    QAction *path_to_maven;
    QAction *path_to_inteliji;
    QAction *project_settings;
    QAction *show_html;
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
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout_10;
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
    QLabel *label_8;
    QComboBox *classes;
    QLineEdit *tag;
    QLabel *label_4;
    QLineEdit *path;
    QLabel *label_2;
    QLineEdit *id;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    Console *inner;
    QVBoxLayout *verticalLayout_6;
    Browser *browser;
    QTabWidget *consoles_tab;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_9;
    Console *main_console;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_8;
    Console *application;
    Console *html_source;
    QVBoxLayout *verticalLayout_8;
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
        MainWindow->resize(1634, 916);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        create_new_project = new QAction(MainWindow);
        create_new_project->setObjectName(QString::fromUtf8("create_new_project"));
        open_project = new QAction(MainWindow);
        open_project->setObjectName(QString::fromUtf8("open_project"));
        path_to_maven = new QAction(MainWindow);
        path_to_maven->setObjectName(QString::fromUtf8("path_to_maven"));
        path_to_inteliji = new QAction(MainWindow);
        path_to_inteliji->setObjectName(QString::fromUtf8("path_to_inteliji"));
        project_settings = new QAction(MainWindow);
        project_settings->setObjectName(QString::fromUtf8("project_settings"));
        show_html = new QAction(MainWindow);
        show_html->setObjectName(QString::fromUtf8("show_html"));
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
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMaximumSize(QSize(400, 16777215));
        verticalLayout_10 = new QVBoxLayout(widget);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(widget);
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
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_3->addWidget(label_6);

        url = new QLineEdit(groupBox_3);
        url->setObjectName(QString::fromUtf8("url"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(url->sizePolicy().hasHeightForWidth());
        url->setSizePolicy(sizePolicy2);

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
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_7->addWidget(label_9);

        pages = new QComboBox(groupBox_3);
        pages->addItem(QString());
        pages->setObjectName(QString::fromUtf8("pages"));
        sizePolicy2.setHeightForWidth(pages->sizePolicy().hasHeightForWidth());
        pages->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(pages);


        verticalLayout_4->addLayout(horizontalLayout_7);

        progress = new QProgressBar(groupBox_3);
        progress->setObjectName(QString::fromUtf8("progress"));
        sizePolicy2.setHeightForWidth(progress->sizePolicy().hasHeightForWidth());
        progress->setSizePolicy(sizePolicy2);
        progress->setValue(24);
        progress->setInvertedAppearance(false);

        verticalLayout_4->addWidget(progress);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(widget);
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
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(elements->sizePolicy().hasHeightForWidth());
        elements->setSizePolicy(sizePolicy3);
        elements->setColumnCount(2);
        elements->header()->setVisible(false);

        verticalLayout_7->addWidget(elements);


        horizontalLayout_6->addLayout(verticalLayout_7);


        verticalLayout_3->addWidget(groupBox_4);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        classes = new QComboBox(groupBox);
        classes->setObjectName(QString::fromUtf8("classes"));

        gridLayout_2->addWidget(classes, 3, 1, 1, 1);

        tag = new QLineEdit(groupBox);
        tag->setObjectName(QString::fromUtf8("tag"));
        sizePolicy2.setHeightForWidth(tag->sizePolicy().hasHeightForWidth());
        tag->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(tag, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        path = new QLineEdit(groupBox);
        path->setObjectName(QString::fromUtf8("path"));
        sizePolicy2.setHeightForWidth(path->sizePolicy().hasHeightForWidth());
        path->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(path, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        id = new QLineEdit(groupBox);
        id->setObjectName(QString::fromUtf8("id"));
        sizePolicy2.setHeightForWidth(id->sizePolicy().hasHeightForWidth());
        id->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(id, 1, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);

        verticalLayout_5->addWidget(label_5);

        verticalSpacer = new QSpacerItem(10, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout_5, 5, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        inner = new Console(groupBox);
        inner->setObjectName(QString::fromUtf8("inner"));
        sizePolicy.setHeightForWidth(inner->sizePolicy().hasHeightForWidth());
        inner->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(inner, 5, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);


        verticalLayout_10->addLayout(verticalLayout_3);


        horizontalLayout_4->addWidget(widget);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        browser = new Browser(centralWidget);
        browser->setObjectName(QString::fromUtf8("browser"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(browser->sizePolicy().hasHeightForWidth());
        browser->setSizePolicy(sizePolicy5);

        verticalLayout_6->addWidget(browser);

        consoles_tab = new QTabWidget(centralWidget);
        consoles_tab->setObjectName(QString::fromUtf8("consoles_tab"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_9 = new QHBoxLayout(tab);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        main_console = new Console(tab);
        main_console->setObjectName(QString::fromUtf8("main_console"));

        horizontalLayout_9->addWidget(main_console);

        consoles_tab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_8 = new QHBoxLayout(tab_2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        application = new Console(tab_2);
        application->setObjectName(QString::fromUtf8("application"));

        horizontalLayout_8->addWidget(application);

        consoles_tab->addTab(tab_2, QString());

        verticalLayout_6->addWidget(consoles_tab);


        horizontalLayout_4->addLayout(verticalLayout_6);

        html_source = new Console(centralWidget);
        html_source->setObjectName(QString::fromUtf8("html_source"));
        sizePolicy.setHeightForWidth(html_source->sizePolicy().hasHeightForWidth());
        html_source->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(html_source);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));

        horizontalLayout_4->addLayout(verticalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_9, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1634, 21));
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
        menuSettings->addAction(path_to_maven);
        menuSettings->addAction(path_to_inteliji);
        menuSettings->addAction(project_settings);
        menuView->addAction(show_html);

        retranslateUi(MainWindow);

        consoles_tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        create_new_project->setText(QCoreApplication::translate("MainWindow", "New Project", nullptr));
        open_project->setText(QCoreApplication::translate("MainWindow", "Open Project", nullptr));
        path_to_maven->setText(QCoreApplication::translate("MainWindow", "Path To Maven", nullptr));
        path_to_inteliji->setText(QCoreApplication::translate("MainWindow", "Path To Inteliji Idea", nullptr));
        project_settings->setText(QCoreApplication::translate("MainWindow", "Project Settings", nullptr));
        show_html->setText(QCoreApplication::translate("MainWindow", "Show HTML Source", nullptr));
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
        label_8->setText(QCoreApplication::translate("MainWindow", "Path:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Id:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Classes:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Inner:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Tag:", nullptr));
        consoles_tab->setTabText(consoles_tab->indexOf(tab), QCoreApplication::translate("MainWindow", "Console", nullptr));
        consoles_tab->setTabText(consoles_tab->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Application  Output", nullptr));
        menuProject->setTitle(QCoreApplication::translate("MainWindow", "Project", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWKNYPEO_H
