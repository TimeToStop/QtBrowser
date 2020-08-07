#include "page.h"

Page::Page(const QString& name):
    m_name(name),
    m_request_url(),
    m_target_url(),
    m_elements()
{
}

Page::~Page()
{
}

void Page::dumpToFile(QFile& file) const
{
    file.write("public static final class ");
    file.write(m_name.toUtf8());
    file.write("\n{\n");
    file.write("public static final PageID self = new PageID(\"");
    file.write(m_name.toUtf8());
    file.write("\", \"");
    file.write(m_request_url.toUtf8());
    file.write("\", \"");
    file.write(m_target_url.toUtf8());
    file.write("\");\n\n");
    
    for (std::shared_ptr<Element> e : m_elements)
    {
        e->dumpToFile(file);
    }

    file.write("\n}\n\n");
}

void Page::setName(const QString& name)
{
    m_name = name;
}

void Page::setRequestURL(const QString& request)
{
    m_request_url = request;
}

void Page::setTargetURL(const QString& target)
{
    m_target_url = target;
}

void Page::addElement(const std::shared_ptr<Element>& element)
{
    element->setPage(this);
    m_elements.push_back(element);
}

void Page::addElement(std::shared_ptr<Element>&& element)
{
    element->setPage(this);
    m_elements.push_back(element);
}

QString Page::name() const
{
    return m_name;
}

QString Page::request() const
{
    return m_request_url;
}

QString Page::target() const
{
    return m_target_url;
}

size_t Page::size() const
{
    return m_elements.size();
}

std::shared_ptr<Element> Page::getElement(size_t i)
{
    return m_elements[i];
}

std::shared_ptr<Element> Page::operator[](size_t i)
{
    return m_elements[i];
}
