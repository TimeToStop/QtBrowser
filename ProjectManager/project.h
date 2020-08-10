#pragma once

#include "page.h"

class Project
{
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

	std::vector<std::shared_ptr<Page>> m_pages;

public:
	Project(const QString&, const QString&, bool is_creation);
	~Project();

	QString name() const;
	QString path() const;
	QString pathToPort() const;
	QString pathToElementsMeta() const;

	size_t size() const;
	std::shared_ptr<Page> getPage(size_t i) const;
	std::shared_ptr<Page> operator[](size_t) const;

	void setName(const QString&);
	void setPathToPort(const QString&);
	void setPathToElementsMeta(const QString&);

	std::shared_ptr<Page> addPage(const QString&);

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

