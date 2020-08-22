#pragma once

#include "../ProjectManager/element.h"

#include <QDialog>
namespace Ui { class EditElement; };

class EditElement : public QDialog
{
	Q_OBJECT

	std::shared_ptr<Element> m_element;

public:
	EditElement(std::shared_ptr<Element>, QWidget *parent = Q_NULLPTR);
	virtual ~EditElement();

	bool waitForRedirect() const;
	QString name() const;

public slots:
	void edit();

private:
	Ui::EditElement *ui;
};
