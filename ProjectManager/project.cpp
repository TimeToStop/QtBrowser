#include "project.h"

#include <QDir>

const QString Project::m_path_to_project_meta_data = "/compiled";
const QString Project::m_path_to_src = "/src/main/java";

Project::Project(const QString& name, const QString& path):
    m_name(name),
    m_path_to_project(path),
    m_pages()
{
}

Project::~Project()
{
}

void Project::dumpToFile(QFile& file) const
{
    file.write("public static final class Pages \n{\n");
    
    for (std::shared_ptr<Page> p : m_pages)
    {
        p->dumpToFile(file);
    }

    file.write("}\n");
}

void Project::setName(const QString& name)
{
    m_name = name;
}

std::shared_ptr<Page> Project::addPage(const QString& name)
{
    std::shared_ptr<Page> page = std::make_shared<Page>(name);
    m_pages.push_back(page);
    return page;
}

QString Project::name() const
{
    return m_name;
}

QString Project::path() const
{
    return m_path_to_project;
}

size_t Project::size() const
{
    return m_pages.size();
}

std::shared_ptr<Page> Project::getPage(size_t i) const
{
    return m_pages[i];
}

std::shared_ptr<Page> Project::operator[](size_t i) const
{
    return m_pages[i];
}

bool Project::isOutDated() const
{
    QDir d(m_path_to_project);
    return !d.exists();
}

void Project::updateMetaData() const
{
    QFile page_meta(m_path_to_project + m_path_to_src + m_path_to_project_meta_data + "/pages.java");

    if (page_meta.open(QIODevice::WriteOnly))
    {
        dumpToFile(page_meta);
        page_meta.close();
    }
}

void Project::addFile(const QString& path, const QByteArray& data)
{
    QFile file(m_path_to_project + m_path_to_src + path);
    
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(data);
        file.flush();
        file.close();
    }
}

void Project::rmFile(const QString& path)
{
    QFile::remove(m_path_to_project + m_path_to_src + path);
}

void Project::addDirectory(const QString& path)
{
    QDir d(m_path_to_project + m_path_to_src);
    
    if (d.exists())
    {
        d.mkpath(path);
    }
}
