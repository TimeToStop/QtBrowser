#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../BrowserController/browserexecutor.h"
#include "taskexecutor.h"

#include "createnewproject.h"
#include "openproject.h"

#include "registerpage.h"
#include "addpageelement.h"
#include "addarrayelement.h"
#include "editelement.h"
#include "elementwidgetitem.h"
#include "pagewidgetitem.h"

#include "projectsettings.h"

#include "../DOM/domnodewidgetitem.h"
#include "../DOM/domnode.h"
#include "../DOM/dompath.h"

#include <QMessageBox>

#include <QKeyEvent>
#include <QFileDialog>

#include <QXmlStreamReader>
#include <QXmlStreamWriter>


const QString MainWindow::m_path_to_global_settings = "File/global.settings";

MainWindow* MainWindow::m_window = nullptr;

MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent),
	m_is_control_pressed(false),
	m_is_selecting_array(false),
	m_path_to_maven(),
	m_path_to_inteliji(),
	m_scripts({ {"Find", "JS/find.js"}, {"Hover", "JS/hover.js"},
		{"jQuery", "JS/jquery-3-5-1.min.js"}, {"SourceHTML", "JS/html.js"} 
	}),
	m_main_project(nullptr),
	m_project_manager(),
	m_application(),
	m_current_node(nullptr),
	m_array(),
	ui(new Ui::MainWindow())
{
	MainWindow::m_window = this;
	ui->setupUi(this);
	readGlobalSettings();

	connect(ui->elements, &QTreeWidget::itemDoubleClicked, this, &MainWindow::editElement);
	connect(ui->dom_tree, &QTreeWidget::itemClicked,	   this, &MainWindow::elementDomSelected);

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

	connect(ui->load,						   &QPushButton	::clicked,				this, qOverload<>(&MainWindow::loadPage					));
	connect(ui->generate,					   &QPushButton ::clicked,				this,			  &MainWindow::generateMetaProjectData	);
	connect(ui->run_inteliji,				   &QPushButton	::clicked,				this,		      &MainWindow::runInteljiIdea			);
	connect(ui->run_app,					   &QPushButton	::clicked,				this,			  &MainWindow::runApplication			);
	connect(ui->stop,						   &QPushButton	::clicked,				this,		      &MainWindow::closeApplication			);
	connect(ui->register_page,				   &QPushButton	::clicked,				this,			  &MainWindow::registerPage				);
	connect(ui->pages,			qOverload<int>(&QComboBox   ::currentIndexChanged), this,			  &MainWindow::pageIndexChanged			);

	connect(ui->add_array_to_project,	&QPushButton::clicked, this, &MainWindow::addArrayToProject);
	connect(ui->select_array_elements,	&QPushButton::clicked, this, &MainWindow::selectArray);

	/*
	* UI Actions
	*/

	connect(ui->create_new_project,	&QAction::triggered, this, &MainWindow::newProject);
	connect(ui->open_project,		&QAction::triggered, this, &MainWindow::openProject);
	connect(ui->path_to_maven,		&QAction::triggered, this, &MainWindow::changePathToMaven);
	connect(ui->path_to_inteliji,	&QAction::triggered, this, &MainWindow::changePathToInteliji);
	connect(ui->project_settings,	&QAction::triggered, this, &MainWindow::projectSettings);
	connect(ui->show_html,			&QAction::triggered, this, &MainWindow::showHtmlSource);


	/*
	*  Browser Progress
	*/

	ui->progress->setRange(0, 100);
	ui->progress->setValue(0);

	/*
	*  Default settings
	*/

	ui->browser->setDefaultScripts(m_scripts);

	m_application.setBrowser(ui->browser);
	m_application.setConsole(ui->application);
	m_project_manager.setPathToMaven(m_path_to_maven);
}

MainWindow::~MainWindow()
{
	saveGlobalSettings();
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
		else if (key_event->key() == Qt::Key_F && m_is_control_pressed && m_current_page != nullptr)
		{
			findElement();
		}
		else if (obj == ui->elements && key_event->key() == Qt::Key_Delete)
		{
			rmElement();
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
	bool has_project = (project != nullptr);
	m_main_project = project;

	if (has_project)
	{
		ui->project_name->setText(m_main_project->name());
		updateTargetElements();
	}

	ui->register_page->setEnabled(has_project);
	ui->generate->setEnabled(has_project);
	ui->run_app->setEnabled(has_project);
	ui->run_inteliji->setEnabled(has_project);
	ui->stop->setEnabled(has_project);
	ui->select_array_elements->setEnabled(has_project);
	ui->add_array_to_project->setEnabled(has_project);
}

void MainWindow::updateTargetElements()
{
	if (m_main_project != nullptr)
	{
		m_main_project->saveJavaMeta();
		m_main_project->saveProjectMeta();

		ui->pages->blockSignals(true);
		ui->pages->clear();
		ui->pages->addItem("None");

		ui->elements->clear();
		
		for (size_t i = 0; i < m_main_project->size(); i++)
		{
			std::shared_ptr<Page> page = m_main_project->getPage(i);
			PageWidgetItem* page_item = new PageWidgetItem(page, ui->elements);
			page_item->setText(0, page->name());
			ui->elements->addTopLevelItem(page_item);

			ui->pages->addItem(page->name());

			for (size_t i = 0; i < page->size(); i++)
			{
				std::shared_ptr<Element> element = page->getElement(i);
				ElementWidgetItem* element_item = new ElementWidgetItem(element, page_item);
				element_item->setText(1, element->name());
			}
		}

		ui->pages->blockSignals(false);
	}
}

void MainWindow::log(const QString& msg)
{
	m_window->ui->main_console->log(msg);
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
	
	if (!ui->source->isHidden())
	{
		ui->dom_tree->setJsonHTML(ui->browser->htmlToJson());
	}
}

void MainWindow::onElementHovered(const QString& tag, const QString& id, const QStringList& classes, const QString& inner, const QString& path)
{
	ui->tag->setText(tag);
	ui->id->setText(id);
	ui->path->setText(path);
	ui->classes->clear();
	ui->classes->addItems(classes);
	ui->inner->clear();
	ui->inner->log(inner);
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
			
			ui->pages->blockSignals(true);
			ui->pages->setCurrentIndex(ui->pages->count() - 1);
			ui->pages->blockSignals(false);
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
		idea.startDetached(m_path_to_inteliji, QStringList() << m_main_project->path());
		idea.waitForStarted(-1); 
	}
}

void MainWindow::runApplication()
{
	if (m_main_project != nullptr)
	{
		m_application.close();
		m_application.start(m_main_project);
		ui->consoles_tab->setCurrentIndex(1);
	}
}

void MainWindow::closeApplication()
{
	if (m_main_project != nullptr)
	{
		m_application.close();
	}
}

void MainWindow::editElement(QTreeWidgetItem* item, int)
{
	ElementWidgetItem* element_item = dynamic_cast<ElementWidgetItem*>(item);

	if (element_item != nullptr)
	{
		element_item->doubleClicked();
	}
}

void MainWindow::newProject()
{
	CreateNewProject d(this);

	if (d.exec() == QDialog::Accepted)
	{
		saveGlobalSettings();
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

void MainWindow::changePathToMaven()
{
	QString dir = QFileDialog::getOpenFileName(this, "Path To Maven", "", "mvn.cmd");

	if (dir != "")
	{
		m_path_to_maven = dir;
	}
}

void MainWindow::changePathToInteliji()
{
	QString dir = QFileDialog::getOpenFileName(this, "Path To Inteliji", "", "idea.exe");

	if (dir != "")
	{
		m_path_to_inteliji = dir;
	}
}

void MainWindow::projectSettings()
{
	if (m_main_project != nullptr)
	{
		ProjectSettings d(m_main_project, this);

		if (d.exec() == QDialog::Accepted)
		{
			m_main_project->setPathToPort(d.pathToPort());
			m_main_project->setPathToElementsMeta(d.pathToElementsMeta());
			m_main_project->setDefaultJS(d.pathToDefaultScripts());
			m_main_project->saveProjectMeta();
		}
	}
}

void MainWindow::generateMetaProjectData()
{
	if (m_main_project != nullptr)
	{
		updateTargetElements();
	}
}

void MainWindow::showHtmlSource()
{
	if (ui->source->isHidden())
	{
		ui->source->show();
		ui->show_html->setText("Hide HTML Source");
		ui->dom_tree->setJsonHTML(ui->browser->htmlToJson());
	}
	else
	{
		m_current_node = nullptr;
		ui->source->hide();
		ui->show_html->setText("Show HTML Source");
	}
}

void MainWindow::elementDomSelected(QTreeWidgetItem* item, int)
{
	m_current_node = static_cast<DomNodeWidgetItem*>(item)->node();

	if (m_is_selecting_array)
	{
		if (!m_array.addDomPath(*m_current_node->path()))
		{
			QMessageBox::critical(this, "Array selection", "Array cannot be extended to this element");
			item->setSelected(false);
		}
		else
		{
			ui->array_value->setText(m_array.toString());
		}
	}
	else
	{
		ui->current_path->setText(m_current_node->path()->toString());
	}
}

void MainWindow::selectArray()
{
	if (m_is_selecting_array)
	{
		m_array.clear();

		ui->select_array_elements->setText("Select Array Elements");
		ui->array_value->setText("");
		ui->dom_tree->setSelectionMode(QAbstractItemView::SingleSelection);
	}
	else
	{
		if (m_current_node != nullptr)
		{
			m_array.addDomPath(*m_current_node->path());
		}

		ui->select_array_elements->setText("Stop Selecting");
		ui->array_value->setText(ui->current_path->text());
		ui->dom_tree->setSelectionMode(QAbstractItemView::MultiSelection);
	}

	m_is_selecting_array = !m_is_selecting_array;
}

void MainWindow::addArrayToProject()
{
	if (m_current_page != nullptr 
		&& m_is_selecting_array
		&& !m_array.isEmpty())
	{
		if (m_array.dimensions() > 1)
		{
			QMessageBox::critical(this, "Array", "Array with more than one demension is unsupported by java framework");
		}
		else
		{
			AddArrayElement d(m_current_page, m_array.toString(), this);

			if (d.exec() == QDialog::Accepted)
			{
				m_current_page->addElement(std::make_shared<Element>(m_current_page, true, d.isWaitForRedirect(), d.type(), d.name(), d.path()));
				updateTargetElements();
			}
		}
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
		m_current_page->addElement(std::make_shared<Element>(m_current_page, false, d.isWaitingForRedirect(), d.type(), d.name(), d.path()));
		updateTargetElements();
	}
}

void MainWindow::findElement()
{
	if (ui->dom_tree->topLevelItemCount() != 0)
	{
		DomNode* e = static_cast<DomNodeWidgetItem*>(ui->dom_tree->topLevelItem(0))->node();
		QStringList path = ui->path->text().split("/");

		for (const QString& element : path)
		{
			if (!element.isEmpty())
			{
				QStringList list = element.split("[");

				if (list.size() == 2)
				{
					QString tag = list[0].toLower();
					QString str_index = list[1];
					str_index.chop(1);

					int index = str_index.toInt();

					for (int i = 0; i < e->childCount(); i++)
					{
						if (e->child(i)->tag() == tag)
						{
							--index;

							if (index == -1)
							{
								e = e->child(i);
								break;
							}
						}
					}

					if (index != -1)
					{
						QMessageBox::critical(this, "Error", "Cannot find element");
						return;
					}
				}
				else
				{
					QMessageBox::critical(this, "Error", "Bad path");
					return;
				}
			}
		}

		if (e->item() != nullptr)
		{
			e->item()->setSelected(true);
		}
	}
}

void MainWindow::rmElement()
{
	QList<QTreeWidgetItem*> items = ui->elements->selectedItems();

	for (QTreeWidgetItem* item : items)
	{
		QTreeWidgetItem* parent = item->parent();
		PageWidgetItem* page = dynamic_cast<PageWidgetItem*>(item);
	
		if (page)
		{
			page->removePage();
		}
		else
		{
			ElementWidgetItem* element = dynamic_cast<ElementWidgetItem*>(item);
			
			if (element)
			{
				element->removeElement();
			}
		}

		if (parent) 
		{
			delete parent->takeChild(parent->indexOfChild(item));
		}
		else 
		{
			delete ui->elements->takeTopLevelItem(ui->elements->indexOfTopLevelItem(item));
		}
	}

	updateTargetElements();
}

void MainWindow::readGlobalSettings()
{
	QFile global(m_path_to_global_settings);

	if (global.open(QIODevice::ReadOnly))
	{
		QXmlStreamReader reader(&global);
		reader.readNextStartElement();
		
		if (reader.name() == "settings")
		{
			while (!reader.atEnd() && !reader.hasError())
			{
				reader.readNextStartElement();

				if (reader.name() == "maven")
				{
					QXmlStreamAttributes attributes = reader.attributes();

					if (attributes.hasAttribute("path"))
					{
						m_path_to_maven = attributes.value("path").toString();
					}
				}
				else if (reader.name() == "inteliji")
				{
					QXmlStreamAttributes attributes = reader.attributes();

					if (attributes.hasAttribute("path"))
					{
						m_path_to_inteliji = attributes.value("path").toString();
					}
				}
			}
		}

		global.close();
	}
}

void MainWindow::saveGlobalSettings()
{
	QFile global(m_path_to_global_settings);

	if (global.open(QIODevice::WriteOnly))
	{
		QXmlStreamWriter writer(&global);
	
		writer.writeStartDocument();
		writer.writeStartElement("settings");
		writer.writeStartElement("maven");
		writer.writeAttribute("path", m_path_to_maven);
		writer.writeEndElement();

		writer.writeStartElement("inteliji");
		writer.writeAttribute("path", m_path_to_inteliji);
		writer.writeEndElement();

		writer.writeEndElement();
		writer.writeEndDocument();

		global.flush();
		global.close();
	}
}
