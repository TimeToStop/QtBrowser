#pragma once
#include "../ProjectManager/page.h"

#include <QDialog>
namespace Ui { class AddArrayElement; };


class AddArrayElement : public QDialog
{
	Q_OBJECT

	std::shared_ptr<Page> m_page;
	ElementType m_type;

public:
	AddArrayElement(const std::shared_ptr<Page>&, const QString&, QWidget *parent = Q_NULLPTR);
	~AddArrayElement();

	bool isWaitForRedirect() const;
	ElementType type() const;
	QString path() const;
	QString name() const;

public slots:
	void add();
	void typeChanged(int);

private:
	Ui::AddArrayElement *ui;
};
