#pragma once

#include <memory>
#include <vector>
#include <QString>

#include "project.h"

class ProjectManager
{
	static const QString m_path_to_projects_meta_data;

	std::vector<std::unique_ptr<Project>> m_projects;

public:
	ProjectManager();
	~ProjectManager();

	Project& create(const QString& name, const QString& path);
};

