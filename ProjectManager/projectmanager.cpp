#include "projectmanager.h"

#include <QDir>
#include <QFile>
#include <QProcess>

#include <QDebug>

#include "taskexecutor.h"

const QString ProjectManager::m_path_to_projects_meta_data = "File/projects.meta";

ProjectManager::ProjectManager()
{
	readProjectsData();
}

ProjectManager::~ProjectManager()
{
	saveProjectsData();
}

void ProjectManager::setPathToMaven(const QString& path)
{
	m_path_to_maven = path;
}

QString ProjectManager::pathToMaven() const
{
	return m_path_to_maven;
}

size_t ProjectManager::size() const
{
	return m_projects.size();
}

std::shared_ptr<Project> ProjectManager::getProject(size_t i)
{
	return m_projects[i];
}

std::shared_ptr<Project> ProjectManager::operator[](size_t i)
{
	return m_projects[i];
}

void ProjectManager::removeProject(size_t i)
{
	m_projects.erase(m_projects.begin() + i);
}

std::shared_ptr<Project> ProjectManager::create(const QString& name, const QString& path)
{
	QDir d(path);

	if (d.exists())
	{
		QProcess maven;
		maven.setWorkingDirectory(d.absolutePath());
		maven.start(m_path_to_maven, 
			QStringList() << "archetype:generate"
						  << "-DgroupId=solver"
						  << "-DartifactId=" + name
						  << "-DarchetypeArtifactId=maven-archetype-quickstart"
						  << "-DarchetypeVersion=1.4"
						  << "-DinteractiveMode=false"
		);

		if (maven.waitForStarted(-1) && maven.waitForFinished(-1))
		{
			std::shared_ptr<Project> project = std::make_shared<Project>(name, d.absolutePath() + "/" + name);
			project->rmFile("/solver/App.java");
			project->addDirectory("compiled");
			project->addDirectory("core");
			m_projects.push_back(project);
			return project;
		}
	}

	return nullptr;
}

void ProjectManager::readProjectsData()
{
	QFile file(m_path_to_projects_meta_data);

	if (file.open(QIODevice::ReadOnly))
	{
		QStringList projects = QString(file.readAll()).split("\n");

		for (const QString& p : projects)
		{
			QStringList temp = p.split(" ");
			if (temp.size() == 2)
			{
				m_projects.push_back(std::make_shared<Project>(temp[0], temp[1]));
			}
		}

		file.close();
	}
}

void ProjectManager::saveProjectsData()
{
	QFile file(m_path_to_projects_meta_data);

	if (file.open(QIODevice::WriteOnly))
	{
		for (std::shared_ptr<Project> p : m_projects)
		{
			QString data = p->name() + " " + p->path() + "\n";
			file.write(data.toUtf8());
		}

		file.flush();
		file.close();
	}
}
