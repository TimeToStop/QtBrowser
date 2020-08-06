#pragma once

#include <QDialog>
namespace Ui { class RegisterPage; };

class RegisterPage : public QDialog
{
	Q_OBJECT;

public:
	RegisterPage(const QString& url, QWidget *parent = Q_NULLPTR);
	virtual ~RegisterPage();

	QString name() const;
	QString target() const;
	QString request() const;

public slots:
	void registerPage();

private:
	Ui::RegisterPage *ui;
};
