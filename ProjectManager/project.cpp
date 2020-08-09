#include "project.h"

#include <QDir>
#include <QXMLStreamReader>
#include <QXMLStreamWriter>

const QString Project::m_path_to_project_meta_data = "/compiled";
const QString Project::m_path_to_src = "/src/main/java";
const QString Project::m_path_to_target_meta = "/target.elements.meta";

Project::Project(const QString& name, const QString& path):
    m_name(name),
    m_path_to_project(path),
    m_pages()
{
    loadFromMeta();
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

void Project::saveMeta() const
{
    QFile file(m_path_to_project + m_path_to_target_meta);

    if (file.open(QIODevice::WriteOnly))
    {
        QXmlStreamWriter writer(&file);

        writer.writeStartDocument();
        writer.writeStartElement("pages");
        
        for (const std::shared_ptr<Page>& page : m_pages)
        {
            writer.writeStartElement("page");

            writer.writeAttribute("name", page->name());
            writer.writeAttribute("request", page->request());
            writer.writeAttribute("target", page->target());

            for (size_t i = 0; i < page->size(); i++)
            {
                writer.writeStartElement("element");

                writer.writeAttribute("name", page->getElement(i)->name());
                writer.writeAttribute("path", page->getElement(i)->path());
                
                writer.writeEndElement();
            }

            writer.writeEndElement();
        }

        writer.writeEndElement();
        writer.writeEndDocument();
    }
}

void Project::loadFromMeta()
{
    QFile file(m_path_to_project + m_path_to_target_meta);

    if (file.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader reader(&file);
        reader.readNextStartElement();
        if (reader.name() == "pages")
        {
            while (!reader.atEnd() && !reader.hasError())
            {
                QXmlStreamReader::TokenType token = reader.readNext();

                if (token == QXmlStreamReader::StartElement && reader.name() == "page")
                {
                    QXmlStreamAttributes attributes = reader.attributes();
                    if (attributes.hasAttribute("name") && attributes.hasAttribute("request") && attributes.hasAttribute("target"))
                    {
                        std::shared_ptr<Page> page = std::make_shared<Page>(attributes.value("name").toString());

                        page->setRequestURL(attributes.value("request").toString());
                        page->setTargetURL(attributes.value("target").toString());

                        while (!reader.atEnd() && !reader.hasError())
                        {
                            QXmlStreamReader::TokenType token = reader.readNext();

                            if (token == QXmlStreamReader::StartElement && reader.name() == "element")
                            {
                                QXmlStreamAttributes attributes = reader.attributes();
                                if (attributes.hasAttribute("name") && attributes.hasAttribute("path"))
                                {
                                    page->addElement(std::make_shared<Element>(attributes.value("name").toString(), attributes.value("path").toString()));
                                }
                            }
                        }

                        m_pages.push_back(page);
                    }
                }
            }
        }
    }
}

QString Project::projectFilePath(const QString& path)
{
    return m_path_to_project + path;
}

QString Project::srcFilePath(const QString& path)
{
    return m_path_to_project + m_path_to_src + path;
}

void Project::addSrcFile(const QString& path, const QByteArray& data)
{
    QFile file(m_path_to_project + m_path_to_src + path);

    if (file.open(QIODevice::WriteOnly))
    {
        file.write(data);
        file.flush();
        file.close();
    }
}

void Project::addProjectFile(const QString& path, const QByteArray& data)
{
    QFile file(m_path_to_project + path);

    if (file.open(QIODevice::WriteOnly))
    {
        file.write(data);
        file.flush();
        file.close();
    }
}

void Project::rmSrcFile(const QString& path)
{
    QFile::remove(m_path_to_project + m_path_to_src + path);
}

void Project::rmProjectFile(const QString& path)
{
    QFile::remove(m_path_to_project + path);
}

void Project::addSrcDirectory(const QString& path)
{
    QDir d(m_path_to_project + m_path_to_src);

    if (d.exists())
    {
        d.mkpath(path);
    }
}

void Project::addProjectDirectory(const QString& path)
{
    QDir d(m_path_to_project);

    if (d.exists())
    {
        d.mkpath(path);
    }
}

void Project::addMavenLocalDependency(const QString& path)
{
    QFile pom_in(m_path_to_project + "/pom.xml");

    if (pom_in.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        const QString to_find = "<dependencies>";
        const QString dependency = 
            "\n<dependency>\n"
            "<groupId>com.google.code</groupId>\n"
            "<artifactId>framework</artifactId>\n"
            "<version>0.0.1</version>\n"
            "<scope>system</scope>\n"
            "<systemPath>" + path + "</systemPath>\n"
            "</dependency>";

        QString data = pom_in.readAll();
        int index = data.indexOf(to_find);
        if (index != -1)
        {
            data.insert(index + to_find.size(), 
                dependency
            );
        }
        else
        {
            data.insert(data.indexOf("<name>"), 
                "<dependencies>" +
                dependency +
                "</dependencies>");
        }

        pom_in.close();

        QFile pom_out(m_path_to_project + "/pom.xml");
        
        if (pom_out.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            pom_out.write(data.toUtf8());
            pom_out.flush();
            pom_out.close();
        }
    }
}
