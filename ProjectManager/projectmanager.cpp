#include "projectmanager.h"

#include <QDir>
#include <QFile>
#include <QProcess>
#include <QXMLStreamReader>
#include <QXMLStreamWriter>

#include "taskexecutor.h"

const QString ProjectManager::m_path_to_projects_meta_data = "File/projects.meta";
const QByteArray ProjectManager::m_default_main_data = QStringLiteral(
	"package main;\n"
	"\n"
	"import core.WebEngine;\n"
	"import generated.ProjectSettings;\n"
	"\n"
	"public class Main\n"
	"{\n"
	"\tpublic static void main(String[] args)\n"
	"\t{\n"
		"\t\tWebEngine engine = WebEngine.create(new ProjectSettings());\n"
		"\t\tif(engine != null)\n"
		"\t\t{\n"
		"\t\t\t// write your code here\n"
		"\t\t}\n"
	"\t}\n"
"}\n"
""
).toUtf8();

ProjectManager::ProjectManager()
{
	QFile project("E://Solver/BrowserController/target/BrowserController-1.1.1-SNAPSHOT.jar");
	if (project.open(QIODevice::ReadOnly))
	{
		m_core_jar_file_data = project.readAll();
		project.close();
	}

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
						  << "-DgroupId=main"
						  << "-DartifactId=" + name
						  << "-DarchetypeArtifactId=maven-archetype-quickstart"
						  << "-DarchetypeVersion=1.4"
						  << "-DinteractiveMode=false"
		);

		if (maven.waitForStarted(-1) && maven.waitForFinished(-1))
		{
			std::shared_ptr<Project> project = Project::create(name, d.absolutePath() + "/" + name + "/");
			project->addProjectDirectory("plugins/core-0-0-1");
			project->addProjectFile("plugins/core-0-0-1/core-0-0-1.jar", m_core_jar_file_data);
			project->addMavenLocalDependency(project->projectFilePath("plugins/core-0-0-1/core-0-0-1.jar"));
			project->addSrcFile("/main/Main.java", m_default_main_data);
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
		QXmlStreamReader reader(&file);

		while (!reader.hasError())
		{
			reader.readNextStartElement();

			if (reader.name() == "project")
			{
				QXmlStreamAttributes attributes = reader.attributes();

				if (attributes.hasAttribute("name") && attributes.hasAttribute("path"))
				{
					m_projects.push_back(Project::load(attributes.value("name").toString(), attributes.value("path").toString()));
				}
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
		QXmlStreamWriter writer(&file);

		writer.writeStartDocument();
		writer.writeStartElement("projects");

		for (std::shared_ptr<Project> p : m_projects)
		{
			writer.writeStartElement("project");
			writer.writeAttribute("name", p->name());
			writer.writeAttribute("path", p->path());
			writer.writeEndElement();
		}

		writer.writeEndElement();
		writer.writeEndDocument();

		file.flush();
		file.close();
	}
}
