#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "createnewproject.h"
#include "../BrowserController/browserexecutor.h"
#include "taskexecutor.h"

Console* MainWindow::m_console = nullptr;

MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent),
	m_application(new BrowserExecutor()),
	ui(new Ui::MainWindow())
{
	ui->setupUi(this);
	MainWindow::m_console = ui->console;

	connect(ui->browser, &Browser::syncLoadStarted, this, &MainWindow::loadStarted);
	connect(ui->browser, &Browser::syncLoadProgress, this, &MainWindow::loadProgress);
	connect(ui->browser, &Browser::syncLoadFinished, this, &MainWindow::loadFinished);

	connect(ui->browser, &Browser::hovered, this, &MainWindow::onElementHovered);

	connect(ui->load, &QPushButton::clicked, this, &MainWindow::loadPage);
	connect(ui->run_inteliji, &QPushButton::clicked, this, &MainWindow::runInteljiIdea);
	connect(ui->run_app, &QPushButton::clicked, this, &MainWindow::runApplication);
	connect(ui->stop_app, &QPushButton::clicked, this, &MainWindow::closeApplication);

	connect(ui->create_new_project, &QAction::triggered, this, &MainWindow::newProject);
	connect(ui->open_project, &QAction::triggered, this, &MainWindow::openProject);

	ui->progress->setRange(0, 100);
	ui->progress->setValue(0);

	m_application->setBrowser(ui->browser);
}

MainWindow::~MainWindow()
{
	delete m_application;
	delete ui;
}

void MainWindow::loadStarted()
{
	if(ui->progress->value() == 100)
	{
		ui->progress->reset();
	}
}

void MainWindow::loadProgress(int progress)
{
	if (progress > ui->progress->value())
	{
		ui->progress->setValue(progress);
	}
}

void MainWindow::loadFinished(bool b)
{
	ui->url->setText(ui->browser->url().toString());
}

void MainWindow::onElementHovered(const QString& tag, const QString& id, const QStringList& classes, const QString& inner)
{
	ui->tag->setText(tag);
	ui->id->setText(id);
	ui->classes->clear();
	ui->classes->addItems(classes);
	ui->inner->clear();
	ui->inner->log(inner);
}

void MainWindow::loadPage()
{
	ui->browser->loadURL(ui->url->text());
}

void MainWindow::runInteljiIdea()
{
	ui->console->log("clicked");
}

void MainWindow::runApplication()
{
	m_application->close();
	m_application->start("E://Solver/BrowserController/src");
}

void MainWindow::closeApplication()
{
	m_application->close();
}

void MainWindow::newProject()
{
	CreateNewProject d;

	if (d.exec() == QDialog::Accepted)
	{

	}
}

void MainWindow::openProject()
{
}
