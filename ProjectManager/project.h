#pragma once

#include "page.h"
#include "plugin.h"

#include <QString>
#include <QStringList>

class Project : public std::enable_shared_from_this<Project>
{
	static const QString m_settings_template;

	static const QString m_path_to_src;
	static const QString m_properties_file;
	
	static const QString m_path_to_generated_src;
	static const QString m_src_pages;
	static const QString m_src_settings;

	static const QString m_default_path_to_elements_meta;
	static const QString m_default_path_to_port_file;

	QString m_name;
	QString m_path_to_project;
	QString m_path_to_port_file;
	QString m_path_to_elements_meta;
	QString m_path_to_debug_source;

	QStringList m_default_js;

	std::vector<std::shared_ptr<Page>> m_pages;
	std::vector<std::shared_ptr<Plugin>> m_plugins;

public:
	Project(const QString&, const QString&);
	~Project();

	static std::shared_ptr<Project> create(const QString& name, const QString& path);
	static std::shared_ptr<Project> load(const QString& name, const QString& path);

	QString name() const;
	QString path() const;
	QString pathToPort() const;
	QString pathToElementsMeta() const;
	QString pathToDebugSource() const;
	QStringList defaultJS() const;

	size_t size() const;
	std::shared_ptr<Page> getPage(size_t i) const;
	std::shared_ptr<Page> operator[](size_t) const;

	void setName(const QString&);
	void setPathToPort(const QString&);
	void setPathToElementsMeta(const QString&);
	void setPathToDebugSource(const QString&);
	void setDefaultJS(const QStringList&);

	std::shared_ptr<Page> addPage(const QString&);
	void addPlugin(std::shared_ptr<Plugin>);

	bool isOutDated() const;
	bool writePort(int) const;
	void saveJavaMeta() const;
	void saveProjectMeta() const;
	void loadFromMeta();

	QString projectFilePath(const QString&);
	QString srcFilePath(const QString&);

	void addSrcFile(const QString&, const QByteArray&);
	void addProjectFile(const QString&, const QByteArray&);

	void rmSrcFile(const QString&);
	void rmProjectFile(const QString&);

	void addSrcDirectory(const QString&);
	void addProjectDirectory(const QString&);

	void addMavenLocalDependency(const QString& path);

private:
	void createDefaultPropertiesFile();
	void readPropertiesFile();
	void saveToPropertiesFile() const;

	void saveJavaPageMeta() const;
	void saveJavaSettingsMeta() const;

	void saveProjectPageMeta() const;
};

