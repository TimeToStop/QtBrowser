#include "element.h"

#include "page.h"

Element::Element(const QString& name, const QString& path):
    m_page(nullptr),
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

QString Element::name() const
{
    return m_name;
}

QString Element::path() const
{
    return m_path;
}
