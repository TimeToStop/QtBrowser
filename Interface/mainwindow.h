#pragma once

#include <QMainWindow>
#include "../ProjectManager/projectmanager.h"
#include "../BrowserController/browserexecutor.h"

namespace Ui { class MainWindow; };

class BrowserExecutor;

class MainWindow : public QMainWindow
{
	Q_OBJECT;

	static const QString m_path_to_global_settings;

	static MainWindow* m_window;

	bool m_is_control_pressed;

	QString m_path_to_maven;
	QString m_path_to_inteliji;

	QList<QPair<QString, QString>> m_scripts;

	std::shared_ptr<Project> m_main_project;
	std::shared_ptr<Page>    m_current_page;

	BrowserExecutor m_application;
	ProjectManager	m_project_manager;

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	virtual ~MainWindow();

	virtual bool eventFilter(QObject*, QEvent*) override;

	void setMainProject(std::shared_ptr<Project>);
	void updateTargetElements();

	static void log(const QString&);
	static void warning(const QString&);
	static void error(const QString&);

public slots:
	void loadStarted();
	void loadProgress(int);
	void loadFinished(bool);

	void onElementHovered(const QString&, const QString&, const QStringList&, const QString&, const QString&);

	void loadPage();
	void loadPage(std::shared_ptr<Page>);
	void registerPage();
	void pageIndexChanged(int);
	void runInteljiIdea();
	void runApplication();
	void closeApplication();

	void newProject();
	void openProject();
	void changePathToMaven();
	void changePathToInteliji();
	void projectSettings();
	void showHtmlSource();

private:
	void addElement();

	void readGlobalSettings();
	void saveGlobalSettings();

private:
	Ui::MainWindow *ui;
};
