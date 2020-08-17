#include "page.h"

#include "project.h"

Page::Page(std::weak_ptr<Project> project, const QString& name):
    m_project(project),
    m_name(name),
    m_request_url(),
    m_target_url(),
    m_elements()
{
}

Page::~Page()
{
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
    m_elements.push_back(element);
}

void Page::addElement(std::shared_ptr<Element>&& element)
{
    m_elements.push_back(element);
}

void Page::removeElement(const std::shared_ptr<Element>& target)
{
    for (auto it = m_elements.begin(); it < m_elements.end(); ++it)
    {
        if (*it == target)
        {
            m_elements.erase(it);
            return;
        }
    }
}

std::shared_ptr<Project> Page::project() const
{
    return m_project.lock();
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

bool Page::hasElementName(const QString& name) const
{
    for (std::shared_ptr<Element> element : m_elements)
    {
        if (name == element->name())
        {
            return true;
        }
    }

    return false;
}
