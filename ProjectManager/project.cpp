#include "project.h"

#include <QDir>
#include <QXMLStreamReader>
#include <QXMLStreamWriter>

const QString Project::m_settings_template = 
        "package generated;\n"
        "import core.other.Settings;\n\n"
        "public class ProjectSettings extends Settings {\n"
        "\tpublic ProjectSettings() {\n"
        "\t\tsuper();\n"
        "\t\tsuper.port_file_path = \"%1\";\n"
        "\t\tsuper.default_js_scripts = new String[] {%2};\n"
        "\t}\n"
        "}\n";

const QString Project::m_pages_class =
        "package generated;\n"
        "import core.document.*;\n\n"
        "public final class Pages {\n"
        "%1\n"
        "}\n\n";

const QString Project::m_pages_page_class =
        "\tpublic static final class %1 {\n"
        "\tpublic static final PageID self = new PageID(%2,\"%3\",\"%4\");\n\n"
        "%5\n"
        "\t}\n\n";

const QString Project::m_pages_element =
        "\t\tpublic static final %1 %2 = new %1(%3, %4.self, \"%5\");\n\n";

const QString Project::m_path_to_src                   = "/src/main/java/";
const QString Project::m_properties_file               = "project.properties";

const QString Project::m_path_to_generated_src         = "generated/";
const QString Project::m_src_pages                     = "Pages.java";
const QString Project::m_src_settings                  = "ProjectSettings.java";

const QString Project::m_default_path_to_elements_meta = "elements.meta";
const QString Project::m_default_path_to_port_file     = "port.port";

std::shared_ptr<Project> Project::create(const QString& name, const QString& path)
{
    std::shared_ptr<Project> project = std::make_shared<Project>(name, path);

    project->createDefaultPropertiesFile();
    project->rmSrcFile("/main/App.java");
    project->addSrcDirectory("generated");
    project->addProjectDirectory("plugins"); 
    project->addProjectDirectory("source");
    project->saveToPropertiesFile();

    return project;
}

std::shared_ptr<Project> Project::load(const QString& name, const QString& path)
{
    std::shared_ptr<Project> project = std::make_shared<Project>(name, path);

    project->readPropertiesFile();
    project->loadFromMeta();

    return project;
}

Project::Project(const QString& name, const QString& path):
    m_name(name),
    m_path_to_project(path),
    m_path_to_port_file(path + m_default_path_to_port_file),
    m_path_to_elements_meta(path + m_default_path_to_elements_meta),
    m_path_to_debug_source(path + "source/"),
    m_default_js(),
    m_pages()
{
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

// TODO: Structure parse 
void Project::readPropertiesFile()
{
    QFile properties(m_path_to_project + m_properties_file);

    if (properties.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader reader(&properties);

        while (!reader.hasError())
        {
            QXmlStreamReader::TokenType token = reader.readNext();

            if (token == QXmlStreamReader::StartElement)
            {
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
                else if (reader.name() == "port")
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
                else if (reader.name() == "js")
                {
                    QXmlStreamAttributes attributes = reader.attributes();
                    if (attributes.hasAttribute("path"))
                    {
                        QFile file(m_path_to_debug_source + attributes.value("path").toString());

                        if (file.exists())
                        {
                            m_default_js.push_back(attributes.value("path").toString());
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

        writer.writeStartElement("defaultJS");

        for (const QString& script_path : m_default_js)
        {
            writer.writeStartElement("js");
            writer.writeAttribute("path", script_path);
            writer.writeEndElement();
        }

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
        int page_id = 0;
        QString page_list;

        for (const std::shared_ptr<Page> page : m_pages)
        {
            QString element_list;

            for (int i = 0; i < page->size(); i++)
            {
                QString type, redirect;

                switch (page->getElement(i)->type())
                {
                case ElementType::INPUT:
                    type = "InputElementID";
                    break;
                case ElementType::CLICKABLE:
                    type = "ClickElementID";
                    break;
                case ElementType::READABLE:
                    type = "ReadElementID";
                    break;
                }

                if (page->getElement(i)->isWaitingForRedirect())
                {
                    redirect = "true";
                }
                else
                {
                    redirect = "false";
                }

                element_list += m_pages_element.arg(type, page->getElement(i)->name(), redirect, page->name(), page->getElement(i)->path());
            }

            page_list += m_pages_page_class.arg(page->name(), QString::number(page_id++), page->request(), page->target(), element_list);
        }

        file.write(m_pages_class.arg(page_list).toUtf8());
        file.flush();
        file.close();
    }
}

void Project::saveJavaSettingsMeta() const
{
    QFile settings(m_path_to_project + m_path_to_src + m_path_to_generated_src + m_src_settings);

    if (settings.open(QIODevice::WriteOnly))
    {
        QString defaultJS = "";
        int lastElementIndex = m_default_js.size() - 1;

        for (int i = 0; i  < lastElementIndex; i++)
        {
            defaultJS += " \"" + m_default_js[i] + "\", ";
        }

        if (lastElementIndex != -1)
        {
            defaultJS += " \"" + m_default_js[lastElementIndex] + "\"";
        }

        settings.write(m_settings_template.arg(m_path_to_port_file, defaultJS).toUtf8());
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
                QString redirect, is_array, type;
                writer.writeStartElement("element");

                switch (page->getElement(i)->type())
                {
                case ElementType::INPUT:
                    type = "input";
                    break;
                case ElementType::CLICKABLE:
                    type = "click";
                    break;
                case ElementType::READABLE:
                    type = "read";
                    break;
                }

                if (page->getElement(i)->isWaitingForRedirect())
                {
                    redirect = "true";
                }
                else
                {
                    redirect = "false";
                }

                if (page->getElement(i)->isArray())
                {
                    is_array = "true";
                }
                else
                {
                    is_array = "false";
                }

                writer.writeAttribute("redirect", redirect);
                writer.writeAttribute("type", type);
                writer.writeAttribute("array", is_array);
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

void Project::setPathToDebugSource(const QString& path)
{
    m_path_to_debug_source = path;
}

void Project::setDefaultJS(const QStringList& list)
{
    m_default_js = list;
}

std::shared_ptr<Page> Project::addPage(const QString& name)
{
    std::shared_ptr<Page> page = std::make_shared<Page>(shared_from_this(), name);
    m_pages.push_back(page);
    return page;
}

void Project::removePage(const std::shared_ptr<Page>& page)
{
    for (std::vector<std::shared_ptr<Page>>::iterator it = m_pages.begin(); it < m_pages.end(); ++it)
    {
        if (*it == page)
        {
            m_pages.erase(it);
            return;
        }
    }
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

QString Project::pathToDebugSource() const
{
    return m_path_to_debug_source;
}

QStringList Project::defaultJS() const
{
    return m_default_js;
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
            while (!reader.hasError())
            {
                QXmlStreamReader::TokenType token = reader.readNext();

                if (token == QXmlStreamReader::StartElement && reader.name() == "page")
                {
                    QXmlStreamAttributes attributes = reader.attributes();
                    if (attributes.hasAttribute("name") && attributes.hasAttribute("request") && attributes.hasAttribute("target"))
                    {
                        std::shared_ptr<Page> page = std::make_shared<Page>(shared_from_this(), attributes.value("name").toString());

                        page->setRequestURL(attributes.value("request").toString());
                        page->setTargetURL(attributes.value("target").toString());

                        while (!reader.hasError())
                        {
                            QXmlStreamReader::TokenType token = reader.readNext();

                            if (token == QXmlStreamReader::StartElement && reader.name() == "element")
                            {
                                QXmlStreamAttributes attributes = reader.attributes();
                                if (attributes.hasAttribute("name") && attributes.hasAttribute("path") 
                                    && attributes.hasAttribute("redirect") && attributes.hasAttribute("type"))
                                {
                                    bool redirect;
                                    bool is_array;
                                    ElementType type;
                                    QString array_attr = attributes.value("array").toString();
                                    QString redirect_attr = attributes.value("redirect").toString();
                                    QString type_attr = attributes.value("type").toString();


                                    if (redirect_attr == "true")
                                    {
                                        redirect = true;
                                    }
                                    else if (redirect_attr == "false")
                                    {
                                        redirect = false;
                                    }
                                    else
                                    {
                                        continue;
                                    }

                                    if (array_attr == "true")
                                    {
                                        is_array = true;
                                    }
                                    else if (array_attr == "false")
                                    {
                                        is_array = false;
                                    }
                                    else
                                    {
                                        continue;
                                    }

                                    if (type_attr == "click")
                                    {
                                        type = ElementType::CLICKABLE;
                                    }
                                    else if (type_attr == "read")
                                    {
                                        type = ElementType::READABLE;
                                    }
                                    else if(type_attr == "input")
                                    {
                                        type = ElementType::INPUT;
                                    }
                                    else
                                    {
                                        continue;
                                    }

                                    page->addElement(std::make_shared<Element>(page, is_array, redirect, type, attributes.value("name").toString(), attributes.value("path").toString()));
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
