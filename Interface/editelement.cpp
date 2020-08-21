#include "editelement.h"
#include "ui_editelement.h"

#include "../ProjectManager/page.h"

#include <QMessageBox>

EditElement::EditElement(std::shared_ptr<Element> element, QWidget *parent):
	QDialog(parent),
	m_element(element),
	ui(new Ui::EditElement())
{
	ui->setupUi(this);

	connect(ui->apply, &QPushButton::clicked, this, &EditElement::edit);
	connect(ui->exit,  &QPushButton::clicked, this, &EditElement::reject);

	ui->name->setText(m_element->name());
	ui->redirect->setChecked(m_element->isWaitingForRedirect());

	switch (m_element->type())
	{
	case ElementType::INPUT:
		ui->type->setCurrentIndex(0);
		break;
	case ElementType::READABLE:
		ui->type->setCurrentIndex(1);
		break;
	case ElementType::CLICKABLE:
		ui->type->setCurrentIndex(2);
		break;
	}

	ui->is_array->setChecked(element->isArray());
}

EditElement::~EditElement()
{
	delete ui;
}

QString EditElement::name() const
{
	return ui->name->text();
}

ElementType EditElement::type() const
{
	switch (ui->type->currentIndex())
	{
	case 0:
		return ElementType::INPUT;
	case 1:
		return ElementType::READABLE;
	case 2:
	default:
		return ElementType::CLICKABLE;
	}
}

bool EditElement::waitForRedirect() const
{
	return ui->redirect->isChecked();
}

void EditElement::edit()
{
	QString name = ui->name->text();

	if (!name.isEmpty())
	{
		if (m_element->name() != name && m_element->page()->hasElementName(name))
		{
			QMessageBox::critical(this, "Cannot create Element", "Name of the element is not unique");
			return;
		}

		
		emit(accept());
	}
}
