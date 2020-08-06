#pragma once

#include <QDialog>
namespace Ui { class AddPageElement; };

class AddPageElement : public QDialog
{
	Q_OBJECT;

public:
	AddPageElement(const QString&, const QString&, const QStringList&, const QString&, const QString&, QWidget *parent = Q_NULLPTR);
	virtual ~AddPageElement();

	QString name() const;

public slots:
	void create();

private:
	Ui::AddPageElement *ui;
};
