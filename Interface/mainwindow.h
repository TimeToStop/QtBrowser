#pragma once

#include "../ProjectManager/projectmanager.h"
#include "../BrowserController/browserexecutor.h"

#include "../DOM/domarraypath.h"

#include <QTreeWidget>
#include <QMainWindow>

namespace Ui { class MainWindow; };

class BrowserExecutor;

class MainWindow : public QMainWindow
{
	Q_OBJECT;

	static const QString m_path_to_global_settings;

	static MainWindow* m_window;

	bool m_is_control_pressed;
	bool m_is_selecting_array;

	QString m_path_to_maven;
	QString m_path_to_inteliji;

	QList<QPair<QString, QString>> m_scripts;

	std::shared_ptr<Project> m_main_project;
	std::shared_ptr<Page>    m_current_page;

	BrowserExecutor m_application;
	ProjectManager	m_project_manager;

	DomNode* m_current_node;
	DomArrayPath m_array;
	
public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	virtual ~MainWindow();

	virtual bool eventFilter(QObject*, QEvent*) override;

	void setMainProject(std::shared_ptr<Project>);
	void updateTargetElements();

	static void log(const QString&);

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

	void editElement(QTreeWidgetItem*, int);

	void newProject();
	void openProject();
	void changePathToMaven();
	void changePathToInteliji();
	void projectSettings();
	void showHtmlSource();

	void elementDomSelected(QTreeWidgetItem*, int);
	void selectArray();
	void addArrayToProject();

private:
	void addElement();
	void findElement();
	void rmElement();

	void readGlobalSettings();
	void saveGlobalSettings();

private:
	Ui::MainWindow *ui;
};
