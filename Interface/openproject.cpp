#include "openproject.h"
#include "ui_openproject.h"

#include <QMouseEvent>

OpenProject::OpenProject(ProjectManager* manager, QWidget *parent):
	QDialog(parent),
	m_manager(manager),
	ui(new Ui::OpenProject())
{
	ui->setupUi(this);

	connect(ui->projects, &QListWidget::itemDoubleClicked, this, &OpenProject::itemWasSelected);

	for (size_t i = 0; i < m_manager->size(); i++)
	{
		QString name = m_manager->getProject(i)->name();

		if (m_manager->getProject(i)->isOutDated())
		{
			name += "(Out dated)";
		}

		ui->projects->addItem(new QListWidgetItem(name, ui->projects));
	}
}

OpenProject::~OpenProject()
{
	delete ui;
}

std::shared_ptr<Project> OpenProject::selectedProject() const
{
	return m_selected_project;
}

void OpenProject::itemWasSelected(QListWidgetItem*)
{
	int index = ui->projects->currentIndex().row();
	m_selected_project = m_manager->getProject(index);
	if (m_selected_project->isOutDated())
	{
		//TODO: messagebox info
		QListWidgetItem* item = ui->projects->takeItem(index);
		m_manager->removeProject(index);
		delete item;
	}
	else
	{
		emit(accept());
	}
}
