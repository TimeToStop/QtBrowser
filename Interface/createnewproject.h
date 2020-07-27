#pragma once

#include <QDialog>
namespace Ui { class CreateNewProject; };

class CreateNewProject : public QDialog
{
	Q_OBJECT

public:
	CreateNewProject(QWidget *parent = Q_NULLPTR);
	virtual ~CreateNewProject();

	QString name() const;
	QString projectPath() const;

public slots:
	void checkAccept();
	void dirSelection();

private:
	Ui::CreateNewProject *ui;
};
