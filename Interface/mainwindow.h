#pragma once

#include <QMainWindow>
#include "console.h"
#include "../ProjectManager/projectmanager.h"

namespace Ui { class MainWindow; };

class BrowserExecutor;

class MainWindow : public QMainWindow
{
	Q_OBJECT;

public:
	static Console* m_console;

private:
	bool m_is_control_pressed;
	QString m_path_to_inteliji;
	std::shared_ptr<Project> m_main_project;
	std::shared_ptr<Page>    m_current_page;

	BrowserExecutor* m_application;
	ProjectManager m_project_manager;

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	virtual ~MainWindow();

	virtual void keyPressEvent(QKeyEvent*) override;
	virtual void keyReleaseEvent(QKeyEvent*) override;

	void setMainProject(std::shared_ptr<Project>);
	void updateTargetElements();

public slots:
	void loadStarted();
	void loadProgress(int);
	void loadFinished(bool);

	void onElementHovered(const QString&, const QString&, const QStringList&, const QString&, const QString&);

	void loadPage();
	void registerPage();
	void pageIndexChanged(int);
	void runInteljiIdea();
	void runApplication();
	void closeApplication();

	void newProject();
	void openProject();

private:
	Ui::MainWindow *ui;
};
