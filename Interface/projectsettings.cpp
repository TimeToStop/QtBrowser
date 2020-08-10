#include "projectsettings.h"
#include "ui_projectsettings.h"

#include <QFile>
#include <QMessageBox>

ProjectSettings::ProjectSettings(std::shared_ptr<Project> project, QWidget *parent):
	QDialog(parent),
	ui(new Ui::ProjectSettings())
{
	ui->setupUi(this);

	connect(ui->accept, &QPushButton::clicked, this, &ProjectSettings::acceptedChanges);
	connect(ui->exit,   &QPushButton::clicked, this, &ProjectSettings::rejected);
}

ProjectSettings::~ProjectSettings()
{
	delete ui;
}

QString ProjectSettings::pathToProperties() const
{
	return ui->path_to_properties->text();
}

QString ProjectSettings::pathToPort() const
{
	return ui->path_to_port->text();
}

QString ProjectSettings::pathToObjectsMeta() const
{
	return ui->path_to_elements_meta->text();
}

void ProjectSettings::acceptedChanges()
{
	QStringList list({ pathToProperties(), pathToPort(), pathToObjectsMeta()});

	for (const QString& path : list)
	{
		QFile file(path);

		if (!file.exists())
		{
			QMessageBox::critical(this, "Bad file", "Cannot file does not exists: " + path);
			return;
		}
	}

	emit(accepted());
}