#pragma once

#include <QDialog>
#include "ui_createnewproject.h"

class CreateNewProject : public QDialog
{
	Q_OBJECT

public:
	CreateNewProject(QWidget *parent = Q_NULLPTR);
	virtual ~CreateNewProject();

	QString name();
	QString path();

public slots:
	void createProject();
	void browse();

private:
	Ui::CreateNewProject* ui;
};
