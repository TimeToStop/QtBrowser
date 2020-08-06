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

void Element::dumpToFile(QFile& file) const
{
    file.write("public static final ElementID ");
    file.write(m_name.toUtf8());
    file.write(" = new ElementID(");
    file.write(m_page->name().toUtf8());
    file.write(", \"");
    file.write(m_path.toUtf8());
    file.write("\");\n");
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
