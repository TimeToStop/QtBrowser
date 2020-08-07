#pragma once
#include "../ProjectManager/page.h"

#include <QDialog>
namespace Ui { class AddPageElement; };

class AddPageElement : public QDialog
{
	Q_OBJECT;
	
	std::shared_ptr<Page> m_page;

public:
	AddPageElement(const std::shared_ptr<Page>&, const QString&, const QString&, const QStringList&, const QString&, const QString&, QWidget *parent = Q_NULLPTR);
	virtual ~AddPageElement();

	QString name() const;
	QString path() const;

public slots:
	void create();

private:
	Ui::AddPageElement *ui;
};
