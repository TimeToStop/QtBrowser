#include "element.h"

#include "page.h"

Element::Element(bool is_waiting_for_redirect, ElementType type, const QString& name, const QString& path):
    m_page(nullptr),
    m_is_waiting_for_redirect(is_waiting_for_redirect),
    m_type(type),
    m_name(name),
    m_path(path)
{
}

Element::~Element()
{
}

void Element::setPage(Page* page)
{
    m_page = page;
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
