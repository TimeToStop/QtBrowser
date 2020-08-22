#include "addarrayelement.h"
#include "ui_addarrayelement.h"

#include <QMessageBox>

AddArrayElement::AddArrayElement(const std::shared_ptr<Page>& page, const QString& path, QWidget *parent):
	QDialog(parent),
	m_page(page),
	ui(new Ui::AddArrayElement())
{
	ui->setupUi(this);

	connect(ui->add,				   &QPushButton::clicked,			 this, &AddArrayElement::add);
	connect(ui->exit,				   &QPushButton::clicked,			 this, &AddArrayElement::reject);

	ui->path->setText(path);
}

AddArrayElement::~AddArrayElement()
{
	delete ui;
}

bool AddArrayElement::isWaitForRedirect() const
{
	return ui->wait_for_redirect->isChecked();
}

QString AddArrayElement::path() const
{
	return ui->path->text();
}

QString AddArrayElement::name() const
{
	return ui->name->text();
}

void AddArrayElement::add()
{
	QString name = ui->name->text();

	if (!name.isEmpty())
	{
		if (m_page->hasElementName(name))
		{
			QMessageBox::critical(this, "Cannot create Array", "Name of the array is not unique");
			return;
		}

		emit(accept());
	}
}