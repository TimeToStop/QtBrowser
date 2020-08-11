#include "plugin.h"

#include "project.h"

Plugin::Plugin(const QString& name, int id, std::shared_ptr<Project> project):
    m_id(id),
    m_path_to_source(project->path() + "plugins/" + name + "/source/")
{
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
