#include "addpageelement.h"
#include "ui_addpageelement.h"

#include <QMessageBox>

AddPageElement::AddPageElement(const std::shared_ptr<Page>& page, const QString& tag, const QString& id, const QStringList& classes, const QString& inner, const QString& path, QWidget *parent):
	QDialog(parent),
	m_page(page),
	m_type(ElementType::INPUT),
	ui(new Ui::AddPageElement())
{
	ui->setupUi(this);

	connect(ui->type,	qOverload<int>(&QComboBox::currentIndexChanged), this, &AddPageElement::typeChanged);
	connect(ui->create,				   &QPushButton::clicked,			 this, &AddPageElement::create);
	connect(ui->exit,				   &QPushButton::clicked,			 this, &AddPageElement::reject);

	ui->tag->setText(tag);
	ui->id->setText(id);
	ui->path->setText(path);
	ui->classes->addItems(classes);
	ui->inner->log(inner);
}

AddPageElement::~AddPageElement()
{
	delete ui;
}

QString AddPageElement::name() const
{
	return ui->name->text();
}

QString AddPageElement::path() const
{
	return ui->path->text();
}

ElementType AddPageElement::type() const
{
	return m_type;
}

bool AddPageElement::isWaitingForRedirect() const
{
	return ui->redirect->isChecked();
}

void AddPageElement::typeChanged(int index)
{
	switch (index)
	{
	case 0:
		m_type = ElementType::INPUT;
		ui->redirect->setChecked(false);
		break;
	case 1:
		m_type = ElementType::READABLE;
		ui->redirect->setChecked(false);
		break;
	case 2:
		m_type = ElementType::CLICKABLE;
		ui->redirect->setChecked(true);
		break;
	default:
		break;
	}
}

void AddPageElement::create()
{
	QString name = ui->name->text();

	if (!name.isEmpty())
	{
		for (size_t i = 0; i < m_page->size(); i++)
		{
			if (name == m_page->getElement(i)->name())
			{
				QMessageBox::critical(this, "Cannot create Element", "Name of the element is not unique");
				return;
			}
		}


		emit(accept());
	}
}
