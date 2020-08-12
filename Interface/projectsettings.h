#pragma once

#include "../ProjectManager/project.h"

#include <QDialog>
namespace Ui { class ProjectSettings; };

class ProjectSettings : public QDialog
{
	Q_OBJECT;

	QString m_debug_source;

public:
	ProjectSettings(std::shared_ptr<Project> project, QWidget *parent = Q_NULLPTR);
	virtual ~ProjectSettings();

	QString pathToPort() const;
	QString pathToElementsMeta() const;
	QStringList pathToDefaultScripts() const;

	void addPathToTable(const QString&);

public slots:
	void acceptedChanges();

	void browsePortPath();
	void browseElementsMetaPath();
	void addDefaultScript();
	void removeDefaultScript();

	void changePath(int, int);

private:
	Ui::ProjectSettings *ui;
};
