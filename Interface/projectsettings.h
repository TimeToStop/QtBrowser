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

	QString pathToPort() const;
	QString pathToElementsMeta() const;

public slots:
	void acceptedChanges();

	void browsePortPath();
	void browseElementsMetaPath();

private:
	Ui::ProjectSettings *ui;
};
