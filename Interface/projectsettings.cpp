#include "projectsettings.h"
#include "ui_projectsettings.h"

#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

ProjectSettings::ProjectSettings(std::shared_ptr<Project> project, QWidget *parent):
	QDialog(parent),
	ui(new Ui::ProjectSettings())
{
	ui->setupUi(this);

	ui->path_to_port->setText(project->pathToPort());
	ui->path_to_elements_meta->setText(project->pathToElementsMeta());

	connect(ui->accept,				  &QPushButton::clicked, this, &ProjectSettings::acceptedChanges);
	connect(ui->exit,				  &QPushButton::clicked, this, &ProjectSettings::rejected);
	connect(ui->browse_port,		  &QPushButton::clicked, this, &ProjectSettings::browsePortPath);
	connect(ui->browse_page_elements, &QPushButton::clicked, this, &ProjectSettings::browseElementsMetaPath);
}

ProjectSettings::~ProjectSettings()
{
	delete ui;
}

QString ProjectSettings::pathToPort() const
{
	return ui->path_to_port->text();
}

QString ProjectSettings::pathToElementsMeta() const
{
	return ui->path_to_elements_meta->text(); 
}

void ProjectSettings::browsePortPath()
{
	QString path = QFileDialog::getExistingDirectory(this, "Port");

	if (path != "")
	{
		ui->path_to_port->setText(path + "/port.port");
	}
}

void ProjectSettings::browseElementsMetaPath()
{
	QString path = QFileDialog::getExistingDirectory(this, "Port");

	if (path != "")
	{
		ui->path_to_port->setText(path + "/elements.meta");
	}
}

void ProjectSettings::acceptedChanges()
{
	QStringList list({ pathToPort(), pathToElementsMeta()});

	for (const QString& path : list)
	{
		QFile file(path);

		if (!file.open(QIODevice::ReadWrite))
		{
			QMessageBox::critical(this, "Bad file", "File does not exists or cannot be read/write: " + path);
			return;
		}
	}

	emit(accepted());
}