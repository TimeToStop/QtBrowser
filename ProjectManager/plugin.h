#pragma once

#include <memory>
#include <QString>

class Project;

enum class MainCore : int
{
	Main = 1
};

class Plugin
{
	int m_id;
	QString m_path_to_source;

public:
	Plugin(const QString&, int id, std::shared_ptr<Project>);
	~Plugin();

	int id() const;
	QString source() const;
};

