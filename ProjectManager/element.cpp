#include "element.h"

#include "page.h"

Element::Element(std::weak_ptr<Page> page, bool is_waiting_for_redirect, ElementType type, const QString& name, const QString& path):
    m_page(page),
    m_is_waiting_for_redirect(is_waiting_for_redirect),
    m_type(type),
    m_name(name),
    m_path(path)
{
}

Element::~Element()
{
}

void Element::setIsWaitingForRedirect(bool wait)
{
    m_is_waiting_for_redirect = wait;
}

void Element::setElementType(ElementType type)
{
    m_type = type;
}

void Element::setName(const QString& name)
{
    m_name = name;
}

std::shared_ptr<Page> Element::page() const
{
    return m_page.lock();
}

bool Element::isWaitingForRedirect() const
{
    return m_is_waiting_for_redirect;
}

ElementType Element::type() const
{
    return m_type;
}

QString Element::name() const
{
    return m_name;
}

QString Element::path() const
{
    return m_path;
}
