#include "addarrayelement.h"
#include "ui_addarrayelement.h"

#include <QMessageBox>

AddArrayElement::AddArrayElement(const std::shared_ptr<Page>& page, const QString& path, QWidget *parent):
	QDialog(parent),
	m_page(page),
	m_type(ElementType::INPUT),
	ui(new Ui::AddArrayElement())
{
	ui->setupUi(this);

	connect(ui->type,	qOverload<int>(&QComboBox::currentIndexChanged), this, &AddArrayElement::typeChanged);
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

ElementType AddArrayElement::type() const
{
	return m_type;
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

void AddArrayElement::typeChanged(int index)
{
	switch (index)
	{
	case 0:
		m_type = ElementType::INPUT;
		ui->wait_for_redirect->setChecked(false);
		break;
	case 1:
		m_type = ElementType::READABLE;
		ui->wait_for_redirect->setChecked(false);
		break;
	case 2:
		m_type = ElementType::CLICKABLE;
		ui->wait_for_redirect->setChecked(true);
		break;
	default:
		break;
	}
}
