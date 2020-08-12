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
	QString pathToDebugSource() const;
	QStringList pathToDefaultScripts() const;

	void addPathToTable(const QString&);

public slots:
	void acceptedChanges();

	void browsePortPath();
	void browseElementsMetaPath();
	void browseDebugSource();
	void addDefaultScript();
	void removeDefaultScript();

	void changePath(int, int);

private:
	Ui::ProjectSettings *ui;
};
