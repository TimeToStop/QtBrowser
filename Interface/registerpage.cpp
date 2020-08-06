#include "registerpage.h"
#include "ui_registerpage.h"

RegisterPage::RegisterPage(const QString& url, QWidget *parent):
	QDialog(parent),
	ui(new Ui::RegisterPage())
{
	ui->setupUi(this);

	connect(ui->create, &QPushButton::clicked, this, &RegisterPage::registerPage);
	connect(ui->exit, &QPushButton::clicked, this, &RegisterPage::reject);

	ui->request->setText(url);
	ui->target->setText(url);
}

RegisterPage::~RegisterPage()
{
	delete ui;
}

QString RegisterPage::name() const
{
	return ui->name->text();
}

QString RegisterPage::target() const
{
	return ui->target->text();
}

QString RegisterPage::request() const
{
	return ui->request->text();
}

void RegisterPage::registerPage()
{
	if (!ui->name->text().isEmpty() && !ui->request->text().isEmpty() && !ui->target->text().isEmpty())
	{
		emit(accept());
	}
}