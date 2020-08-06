#pragma once

#include "project.h"

class ProjectManager
{
	static const QString m_path_to_projects_meta_data;
	
	QString m_path_to_maven;

	std::vector<std::shared_ptr<Project>> m_projects;

public:
	ProjectManager();
	~ProjectManager();

	void setPathToMaven(const QString&);

	QString pathToMaven() const;

	size_t size() const;
	std::shared_ptr<Project> getProject(size_t);
	std::shared_ptr<Project> operator[](size_t);

	void removeProject(size_t);

	std::shared_ptr<Project> create(const QString& name, const QString& path);

private:
	void readProjectsData();
	void saveProjectsData();
};

