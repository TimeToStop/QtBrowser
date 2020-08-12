#include "plugin.h"

#include "project.h"

#include <QDir>

Plugin::Plugin(const QString& name, int id, std::shared_ptr<Project> project):
    m_id(id),
    m_name(name),
    m_path_to_source(project->path() + "plugins/" + name + "/source/")
{
    QDir d;
    d.mkdir(m_path_to_source);
    d.mkpath(project->path() + "plugins/" + name + ".jar");
}

Plugin::~Plugin()
{
}

int Plugin::id() const
{
    return m_id;
}

QString Plugin::source() const
{
    return m_path_to_source;
}

QString Plugin::name() const
{
    return m_name;
}
