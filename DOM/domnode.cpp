#include "domnode.h"

#include "dompath.h"

DomNode::DomNode(DomNode* parent):
    m_parent(parent),
    m_children(),
    m_path(new DomPath(this)),
    m_item(nullptr),
    m_id(),
    m_tag(),
    m_class_list()
{
    if (m_parent != nullptr)
    {
        m_parent->addChild(this);
    }

    m_path->update();
}

DomNode::DomNode(const QString& id, const QString& tag, const QStringList& class_list, DomNode* parent):
    m_parent(parent),
    m_children(),
    m_path(new DomPath(this)),
    m_item(nullptr),
    m_id(id),
    m_tag(tag),
    m_class_list(class_list)
{
    if (m_parent != nullptr)
    {
        m_parent->addChild(this);
    }

    m_path->update();
}

DomNode::~DomNode()
{
    for (DomNode* child : m_children)
    {
        delete child;
    }

    delete m_path;
}

size_t DomNode::childCount() const
{
    return m_children.size();
}

size_t DomNode::parentIndex() const
{
    if (m_parent != nullptr)
    {
        return m_parent->indexOfChild(this);
    }
    else
    {
        return -1;
    }
}

size_t DomNode::indexOfChild(const DomNode* target) const
{
    for (int i = 0; i < m_children.size(); i++)
    {
        if (m_children[i] == target)
        {
            return i;
        }
    }

    return -1;
}

DomNode* DomNode::parent() const
{
    return m_parent;
}

DomNode* DomNode::child(size_t i) const
{
    return m_children[i];
}

DomNodeWidgetItem* DomNode::item() const
{
    return m_item;
}

DomPath* DomNode::path() const
{
    return m_path;
}

QString DomNode::id() const
{
    return m_id;
}

QString DomNode::tag() const
{
    return m_tag;
}

QStringList DomNode::classList() const
{
    return m_class_list;
}

void DomNode::setParent(DomNode* parent)
{
    m_parent = parent;
    m_path->update();
}

void DomNode::addChild(DomNode* child)
{
    m_children.push_back(child);
}

void DomNode::removeChild(int index)
{
    m_children.erase(m_children.begin() + index);
}

void DomNode::removeChild(DomNode* target)
{
    for (auto it = m_children.begin(); it != m_children.end(); ++it)
    {
        if (*it == target)
        {
            m_children.erase(it);
        }
    }
}

void DomNode::setItem(DomNodeWidgetItem* item)
{
    m_item = item;
}

void DomNode::setId(const QString& id)
{
    m_id = id;
}

void DomNode::setTag(const QString& tag)
{
    m_tag = tag;
    m_path->update();
}

void DomNode::setClassList(const QStringList& class_list)
{
    m_class_list = class_list;
}
