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
