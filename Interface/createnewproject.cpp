#include "createnewproject.h"
#include "ui_createnewproject.h"

#include <QFileDialog>
#include <QMessageBox>

CreateNewProject::CreateNewProject(QWidget *parent): 
	QDialog(parent),
	ui(new Ui::CreateNewProject())
{
	ui->setupUi(this);

	connect(ui->create, &QPushButton::clicked, this, &CreateNewProject::checkAccept);
	connect(ui->exit,   &QPushButton::clicked, this, &QDialog::reject);
	connect(ui->browse, &QPushButton::clicked, this, &CreateNewProject::dirSelection);
}

CreateNewProject::~CreateNewProject()
{
	delete ui;
}

QString CreateNewProject::name() const
{
	return ui->project_name->text();
}

QString CreateNewProject::projectPath() const
{
	return ui->project_path->text();
}

void CreateNewProject::checkAccept()
{
	if (!(ui->project_name->text().isEmpty()
		&& ui->project_path->text().isEmpty()))
	{
		emit(accept());
	}
	else
	{
		QMessageBox::warning(this, "Error", "Empty name or path");
	}
}

void CreateNewProject::dirSelection()
{
	QString name = QFileDialog::getExistingDirectory(this, "Create Project");

	if (name != "")
	{
		ui->project_path->setText(name);
	}
}