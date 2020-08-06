#include "createnewproject.h"

#include <QFileDialog>

CreateNewProject::CreateNewProject(QWidget *parent): 
	QDialog(parent),
	ui(new Ui::CreateNewProject())
{
	ui->setupUi(this);

	connect(ui->accept, &QPushButton::clicked, this, &CreateNewProject::createProject);
	connect(ui->exit,   &QPushButton::clicked, this, &QDialog::reject);
	connect(ui->browse, &QPushButton::clicked, this, &CreateNewProject::browse);
}

CreateNewProject::~CreateNewProject()
{
}

QString CreateNewProject::name()
{
	return ui->project_name->text();
}

QString CreateNewProject::path()
{
	return ui->project_dir->text();
}

void CreateNewProject::createProject()
{
	if (ui->project_dir->text() != "" && ui->project_name->text() != "")
	{
		QDir d(ui->project_dir->text());

		if (d.exists())
		{
			emit(accept());
		}
	}
}

void CreateNewProject::browse()
{
	QString directory = QFileDialog::getExistingDirectory(this, "Project's directory");

	if (directory != "")
	{
		ui->project_dir->setText(directory);
	}
}