#include "project.h"

#include <QDir>
#include <QXMLStreamReader>
#include <QXMLStreamWriter>

const QString Project::m_path_to_src                   = "/src/main/java/";
const QString Project::m_properties_file               = "project.properties";

const QString Project::m_path_to_generated_src         = "generated/";
const QString Project::m_src_pages                     = "Pages.java";
const QString Project::m_src_settings                  = "ProjectSettings.java";

const QString Project::m_default_path_to_elements_meta = "elements.meta";
const QString Project::m_default_path_to_port_file     = "port.port";

Project::Project(const QString& name, const QString& path, bool is_creation):
    m_name(name),
    m_path_to_project(path),
    m_path_to_port_file(path + m_default_path_to_port_file),
    m_path_to_elements_meta(path + m_default_path_to_elements_meta),
    m_path_to_debug_source(path + "source/"),
    m_pages()
{
    if (is_creation)
    {
        createDefaultPropertiesFile();
        addPlugin(std::make_shared<Plugin>("core", ));
        saveToPropertiesFile();
    }
    else
    {
        readPropertiesFile();
        loadFromMeta();
    }
}

Project::~Project()
{
    saveToPropertiesFile();
}

void Project::createDefaultPropertiesFile() 
{
    QFile port(m_path_to_port_file);
    if (port.open(QIODevice::WriteOnly))
    {
        port.close();
    }

    QFile elements(m_path_to_elements_meta);
    if (elements.open(QIODevice::WriteOnly))
    {
        elements.close();
    }

    QDir source(m_path_to_project);
    if (source.exists())
    {
        source.mkdir("source");
    }
}

void Project::readPropertiesFile()
{
    QFile properties(m_path_to_project + m_properties_file);

    if (properties.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader reader(&properties);
        reader.readNextStartElement();

        if (reader.name() == "project")
        {
            while (!properties.atEnd() && !reader.hasError())
            {
                reader.readNextStartElement();

                if (reader.name() == "elements")
                {
                    QXmlStreamAttributes attributes = reader.attributes();
                    if (attributes.hasAttribute("path"))
                    {
                        QFile file = attributes.value("path").toString();

                        if (file.exists())
                        {
                            m_path_to_elements_meta = attributes.value("path").toString();
                        }
                    }
                }
                else if(reader.name() == "port")
                {
                    QXmlStreamAttributes attributes = reader.attributes();
                    if (attributes.hasAttribute("path"))
                    {
                        QFile file = attributes.value("path").toString();

                        if (file.exists())
                        {
                            m_path_to_port_file = attributes.value("path").toString();
                        }
                    }
                }
                else if (reader.name() == "dsource")
                {
                    QXmlStreamAttributes attributes = reader.attributes();
                    if (attributes.hasAttribute("path"))
                    {
                        QFile file = attributes.value("path").toString();

                        if (file.exists())
                        {
                            m_path_to_debug_source = attributes.value("path").toString();
                        }
                    }
                }
            }
        }

        properties.close();
    }
}
 
void Project::saveToPropertiesFile() const
{
    QFile properties(m_path_to_project + m_properties_file);

    if (properties.open(QIODevice::WriteOnly))
    {
        QXmlStreamWriter writer(&properties);

        writer.writeStartDocument();
        writer.writeStartElement("project");
       
        writer.writeStartElement("elements");
        writer.writeAttribute("path", m_path_to_elements_meta);
        writer.writeEndElement();

        writer.writeStartElement("port");
        writer.writeAttribute("path", m_path_to_port_file);
        writer.writeEndElement();

        writer.writeStartElement("dsource");
        writer.writeAttribute("path", m_path_to_debug_source);
        writer.writeEndElement();

        writer.writeEndElement();
        writer.writeEndDocument();

        properties.flush();
        properties.close();
    }
}

void Project::saveJavaPageMeta() const
{
    QFile file(m_path_to_project + m_path_to_src + m_path_to_generated_src + m_src_pages);

    if (file.open(QIODevice::WriteOnly))
    {
        file.write("package generated;\n");
        file.write("import core.document.*;\n\n");
        file.write("public final class Pages {\n");

        int i = 0;

        for (const std::shared_ptr<Page>& page : m_pages)
        {
            file.write(("\tpublic static final class " + page->name() + " {\n").toUtf8());
            file.write(("\t\tpublic static final PageID self = new PageID(" + QString::number(i)
                + ", \"" + page->request() + "\",\"" + page->target() + "\");\n\n").toUtf8());

            for (int i = 0; i < page->size(); i++)
            {
                file.write(("\t\tpublic static final ElementID " + page->getElement(i)->name() + " = new ElementID(" + page->name() + ".self, \"" + page->getElement(i)->path() + "\");\n").toUtf8());
            }

            file.write("}\n");
        }

        file.write("}\n");
        file.flush();
        file.close();
    }
}

void Project::saveJavaSettingsMeta() const
{
    QFile settings(m_path_to_project + m_path_to_src + m_path_to_generated_src + m_src_settings);

    if (settings.open(QIODevice::WriteOnly))
    {
        settings.write("package generated;\n");
        settings.write("import core.other.Settings;\n\n");
        settings.write("public class ProjectSettings extends Settings {\n");
        settings.write("\tpublic ProjectSettings() {\n");
        settings.write(("\tsuper.port = \"" + m_path_to_port_file + "\";\n").toUtf8());
        settings.write("\t}\n");
        settings.write("}\n");
        settings.flush();
        settings.close();
    }
}

void Project::saveProjectPageMeta() const
{
    QFile file(m_path_to_elements_meta);

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

        file.flush();
        file.close();
    }
}

void Project::setName(const QString& name)
{
    m_name = name;
}

void Project::setPathToPort(const QString& path)
{
    QFile file(m_path_to_port_file);

    if (file.open(QIODevice::WriteOnly))
    {
        m_path_to_port_file = path;
        QFile::remove(m_path_to_port_file);
        file.close();
    }
}

void Project::setPathToElementsMeta(const QString& path)
{
    QFile file(m_path_to_port_file);

    if (file.open(QIODevice::WriteOnly))
    {
        m_path_to_elements_meta = path;
        QFile::remove(m_path_to_elements_meta);
        file.close();
    }
}

std::shared_ptr<Page> Project::addPage(const QString& name)
{
    std::shared_ptr<Page> page = std::make_shared<Page>(name);
    m_pages.push_back(page);
    return page;
}

void Project::addPlugin(std::shared_ptr<Plugin> plugin)
{
    m_plugins.push_back(plugin);
}

QString Project::name() const
{
    return m_name;
}

QString Project::path() const
{
    return m_path_to_project;
}

QString Project::pathToPort() const
{
    return m_path_to_port_file;
}

QString Project::pathToElementsMeta() const
{
    return m_path_to_elements_meta;
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

bool Project::writePort(int port) const
{
    QFile portFile(m_path_to_port_file);

    if (portFile.open(QIODevice::WriteOnly))
    {
        portFile.write(QString::number(port).toUtf8());
        portFile.flush();
        portFile.close();

        return true;
    }

    return false;
}

void Project::saveJavaMeta() const
{
    saveJavaPageMeta();
    saveJavaSettingsMeta();
}

void Project::saveProjectMeta() const
{
    saveProjectPageMeta();
}

void Project::loadFromMeta()
{
    QFile file(m_path_to_elements_meta);

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

        file.close();
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
