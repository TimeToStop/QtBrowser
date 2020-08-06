#include "addpageelement.h"
#include "ui_addpageelement.h"

AddPageElement::AddPageElement(const QString& tag, const QString& id, const QStringList& classes, const QString& inner, const QString& path, QWidget *parent):
	QDialog(parent),
	ui(new Ui::AddPageElement())
{
	ui->setupUi(this);

	connect(ui->create, &QPushButton::clicked, this, &AddPageElement::create);
	connect(ui->exit,   &QPushButton::clicked, this, &AddPageElement::reject);

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

void AddPageElement::create()
{
	if (!ui->name->text().isEmpty())
	{
		emit(accept());
	}
}
