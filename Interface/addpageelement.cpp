#include "addpageelement.h"
#include "ui_addpageelement.h"

#include <QMessageBox>

AddPageElement::AddPageElement(const std::shared_ptr<Page>& page, const QString& tag, const QString& id, const QStringList& classes, const QString& inner, const QString& path, QWidget *parent):
	QDialog(parent),
	m_page(page),
	ui(new Ui::AddPageElement())
{
	ui->setupUi(this);

	connect(ui->create, &QPushButton::clicked, this, &AddPageElement::create);
	connect(ui->exit,   &QPushButton::clicked, this, &AddPageElement::reject);

	ui->tag->setText(tag);
	ui->id->setText(id);
	ui->path->setText(path);
	ui->classes->addItems(classes);
	ui->inner->setHtml(inner);
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
