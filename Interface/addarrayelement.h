#pragma once
#include "../ProjectManager/page.h"

#include <QDialog>
namespace Ui { class AddArrayElement; };


class AddArrayElement : public QDialog
{
	Q_OBJECT

	std::shared_ptr<Page> m_page;

public:
	AddArrayElement(const std::shared_ptr<Page>&, const QString&, QWidget *parent = Q_NULLPTR);
	~AddArrayElement();

	bool isWaitForRedirect() const;
	QString path() const;
	QString name() const;

public slots:
	void add();

private:
	Ui::AddArrayElement *ui;
};
