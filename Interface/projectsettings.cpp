#include "projectsettings.h"
#include "ui_projectsettings.h"

#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

ProjectSettings::ProjectSettings(std::shared_ptr<Project> project, QWidget *parent):
	QDialog(parent),
	m_debug_source(project->pathToDebugSource()),
	ui(new Ui::ProjectSettings())
{
	ui->setupUi(this);

	ui->path_to_port->setText(project->pathToPort());
	ui->path_to_elements_meta->setText(project->pathToElementsMeta());

	QStringList list = project->defaultJS();

	for (const QString& path : list)
	{
		QFile f(m_debug_source + path);

		if (f.exists())
		{
			addPathToTable(path);
		}
		else
		{
			addPathToTable("(Out Dated) " + path);
		}
	}

	connect(ui->accept,				  &QPushButton::clicked, this, &ProjectSettings::acceptedChanges);
	connect(ui->exit,				  &QPushButton::clicked, this, &ProjectSettings::reject);
	connect(ui->browse_port,		  &QPushButton::clicked, this, &ProjectSettings::browsePortPath);
	connect(ui->browse_page_elements, &QPushButton::clicked, this, &ProjectSettings::browseElementsMetaPath);
	connect(ui->add_js,				  &QPushButton::clicked, this, &ProjectSettings::addDefaultScript);
	connect(ui->remove_js,			  &QPushButton::clicked, this, &ProjectSettings::removeDefaultScript);
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

QStringList ProjectSettings::pathToDefaultScripts() const
{
	QStringList list;
	
	for (int i = 0; i < ui->default_js->rowCount(); i++)
	{
		QString path = m_debug_source + ui->default_js->item(i, 0)->text();
		QFile f(path);

		if (f.exists())
		{
			list << ui->default_js->item(i, 0)->text();
		}
	}

	return list;
}

void ProjectSettings::addPathToTable(const QString& path)
{
	int row = ui->default_js->rowCount();
	ui->default_js->insertRow(row);
	ui->default_js->setItem(row, 0, new QTableWidgetItem(path));
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

void ProjectSettings::addDefaultScript()
{
	QString path = QFileDialog::getOpenFileName(this, "JS", "", "*.js");

	if (path != "")
	{
		if (path.startsWith(m_debug_source))
		{
			path.remove(m_debug_source);
			addPathToTable(path);
		}
	}
}

void ProjectSettings::removeDefaultScript()
{
	QList<QTableWidgetItem*> selected = ui->default_js->selectedItems();

	for (const QTableWidgetItem* cell : selected)
	{
		ui->default_js->removeRow(cell->row());
	}
}

void ProjectSettings::changePath(int row, int column)
{
	QString path = QFileDialog::getOpenFileName(this, "JS", ui->default_js->item(row, column)->text(), "*.js");

	if (path != "")
	{
		ui->default_js->item(row, column)->setText(path);
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

	emit(accept());
}