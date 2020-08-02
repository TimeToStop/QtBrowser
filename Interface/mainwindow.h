#pragma once

#include <QMainWindow>
#include "console.h"
namespace Ui { class MainWindow; };

class BrowserExecutor;

class MainWindow : public QMainWindow
{
	Q_OBJECT;

public:
	static Console* m_console;

private:
	BrowserExecutor* m_application;

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	virtual ~MainWindow();

public slots:
	void loadStarted();
	void loadProgress(int);
	void loadFinished(bool);

	void onElementHovered(const QString&, const QString&, const QStringList&, const QString&, const QString&);

	void loadPage();
	void runInteljiIdea();
	void runApplication();
	void closeApplication();

	void newProject();
	void openProject();

private:
	Ui::MainWindow *ui;
};
