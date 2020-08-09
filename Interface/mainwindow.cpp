#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../BrowserController/browserexecutor.h"
#include "taskexecutor.h"

#include "createnewproject.h"
#include "openproject.h"

#include "registerpage.h"
#include "addpageelement.h"

#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent),
	m_is_control_pressed(false),
	m_path_to_maven("E:/Solver/apache-maven-3.6.3/bin/mvn.cmd"),
	m_path_to_inteliji("C:/Program Files/JetBrains/IntelliJ IDEA Community Edition 2020.1.2/bin/idea64.exe"),
	m_main_project(nullptr),
	m_project_manager(),
	m_application(),
	ui(new Ui::MainWindow())
{
	ui->setupUi(this);

	/*
	* Browser signals
	*/
	connect(ui->browser, &Browser::syncLoadStarted,  this, &MainWindow::loadStarted);
	connect(ui->browser, &Browser::syncLoadProgress, this, &MainWindow::loadProgress);
	connect(ui->browser, &Browser::syncLoadFinished, this, &MainWindow::loadFinished);
	connect(ui->browser, &Browser::hovered,			 this, &MainWindow::onElementHovered);

	/*
	* Buttons UI
	*/

	connect(ui->load,						   &QPushButton	::clicked,				this, qOverload<>(&MainWindow::loadPage			));
	connect(ui->run_inteliji,				   &QPushButton	::clicked,				this,		      &MainWindow::runInteljiIdea	);
	connect(ui->run_app,					   &QPushButton	::clicked,				this,			  &MainWindow::runApplication	);
	connect(ui->stop,						   &QPushButton	::clicked,				this,		      &MainWindow::closeApplication	);
	connect(ui->register_page,				   &QPushButton	::clicked,				this,			  &MainWindow::registerPage		);
	connect(ui->pages,			qOverload<int>(&QComboBox   ::currentIndexChanged), this,			  &MainWindow::pageIndexChanged	);

	/*
	* UI Actions
	*/

	connect(ui->create_new_project,	&QAction::triggered, this, &MainWindow::newProject);
	connect(ui->open_project,		&QAction::triggered, this, &MainWindow::openProject);

	/*
	*  Browser Progress
	*/

	ui->progress->setRange(0, 100);
	ui->progress->setValue(0);

	/*
	*  Default settings
	*/

	ui->html_source->hide();
	m_application.setBrowser(ui->browser);
	m_project_manager.setPathToMaven(m_path_to_maven);
}

MainWindow::~MainWindow()
{
	delete ui;
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* key_event = static_cast<QKeyEvent*>(event);

		if (key_event->key() == Qt::Key_Control)
		{
			m_is_control_pressed = true;
		}
		else if (key_event->key() == Qt::Key_E && m_is_control_pressed && m_current_page != nullptr)
		{
			addElement();
		}
	}
	else if (event->type() == QEvent::KeyRelease)
	{
		QKeyEvent* key_event = static_cast<QKeyEvent*>(event);

		if (key_event->key() == Qt::Key_Control)
		{
			m_is_control_pressed = false;
		}
	}

	return QObject::eventFilter(obj, event);
}

void MainWindow::setMainProject(std::shared_ptr<Project> project)
{
	m_main_project = project;

	if (m_main_project != nullptr)
	{
		ui->project_name->setText(m_main_project->name());
		updateTargetElements();
	}
}

void MainWindow::updateTargetElements()
{
	if (m_main_project != nullptr)
	{
		m_main_project->saveMeta();
		m_main_project->updateMetaData();
		ui->pages->blockSignals(true);
		ui->pages->clear();
		ui->pages->addItem("None");

		ui->elements->clear();
		
		for (size_t i = 0; i < m_main_project->size(); i++)
		{
			std::shared_ptr<Page> page = m_main_project->getPage(i);
			QTreeWidgetItem* page_item = new QTreeWidgetItem(ui->elements);
			page_item->setText(0, page->name());
			ui->elements->addTopLevelItem(page_item);

			ui->pages->addItem(page->name());

			for (size_t i = 0; i < page->size(); i++)
			{
				std::shared_ptr<Element> element = page->getElement(i);
				QTreeWidgetItem* element_item = new QTreeWidgetItem(page_item);
				element_item->setText(1, element->name());
			}
		}

		ui->pages->blockSignals(false);
	}
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

void MainWindow::onElementHovered(const QString& tag, const QString& id, const QStringList& classes, const QString& inner, const QString& path)
{
	ui->tag->setText(tag);
	ui->id->setText(id);
	ui->path->setText(path);
	ui->classes->clear();
	ui->classes->addItems(classes);
	ui->inner->clear();
	ui->inner->setText(inner);
}

void MainWindow::loadPage()
{
	ui->browser->loadURL(ui->url->text());
}

void MainWindow::loadPage(std::shared_ptr<Page> page)
{
	ui->browser->loadURL(page->request());
}

void MainWindow::registerPage()
{
	if (m_main_project != nullptr)
	{
		RegisterPage d(ui->url->text(), this);

		if (d.exec() == QDialog::Accepted)
		{
			std::shared_ptr<Page> page = m_main_project->addPage(d.name());
			page->setTargetURL(d.target());
			page->setRequestURL(d.request());

			updateTargetElements();
		}
	}
}

void MainWindow::pageIndexChanged(int index)
{
	if (index != 0)
	{
		m_current_page = m_main_project->getPage((size_t)index - 1);
		loadPage(m_current_page);
	}
	else
	{
		m_current_page = nullptr;
	}
}

void MainWindow::runInteljiIdea()
{
	if (m_main_project != nullptr)
	{
		QProcess idea;
		idea.start(m_path_to_inteliji, QStringList() << m_main_project->path());
		idea.waitForStarted(-1); 
		idea.waitForFinished(-1);
	}
}

void MainWindow::runApplication()
{
	m_application.close();
	m_application.start("E://Solver/BrowserController/src");
}

void MainWindow::closeApplication()
{
	m_application.close();
}

void MainWindow::newProject()
{
	CreateNewProject d(this);

	if (d.exec() == QDialog::Accepted)
	{
		setMainProject(m_project_manager.create(d.name(), d.path()));
	}
}

void MainWindow::openProject()
{
	OpenProject d(&m_project_manager, this);

	if (d.exec() == QDialog::Accepted)
	{
		setMainProject(d.selectedProject());
	}
}

void MainWindow::addElement()
{
	QStringList list;
	for (int i = 0; i < ui->classes->count(); i++)
	{
		list << ui->classes->itemText(i);
	}

	AddPageElement d(m_current_page, ui->tag->text(), ui->id->text(), list, ui->inner->toPlainText(), ui->path->text(), this);
	if (d.exec() == QDialog::Accepted)
	{
		m_current_page->addElement(std::make_shared<Element>(d.name(), d.path()));
		updateTargetElements();
	}
}
