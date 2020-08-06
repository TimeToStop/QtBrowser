#pragma once

#include "../ProjectManager/projectmanager.h"

#include <QListWidget>
#include <QDialog>

namespace Ui { class OpenProject; };

class OpenProject : public QDialog
{
	Q_OBJECT;

	ProjectManager* m_manager;
	std::shared_ptr<Project> m_selected_project;

public:
	OpenProject(ProjectManager*, QWidget *parent = Q_NULLPTR);
	virtual ~OpenProject();

	std::shared_ptr<Project> selectedProject() const;

public slots:
	void itemWasSelected(QListWidgetItem*);

private:
	Ui::OpenProject *ui;
};
