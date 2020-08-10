#pragma once

#include "../ProjectManager/project.h"

#include <QDialog>
namespace Ui { class ProjectSettings; };

class ProjectSettings : public QDialog
{
	Q_OBJECT

public:
	ProjectSettings(std::shared_ptr<Project> project, QWidget *parent = Q_NULLPTR);
	virtual ~ProjectSettings();

	QString pathToProperties() const;
	QString pathToPort() const;
	QString pathToObjectsMeta() const;

public slots:
	void acceptedChanges();

private:
	Ui::ProjectSettings *ui;
};
