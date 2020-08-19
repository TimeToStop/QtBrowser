#include "domnodewidgetitem.h"

DomNodeWidgetItem::DomNodeWidgetItem(DomNode* node):
    QTreeWidgetItem(),
    m_node(node)
{
    m_node->setItem(this);
}

DomNodeWidgetItem::~DomNodeWidgetItem()
{
}

DomNode* DomNodeWidgetItem::node() const
{
    return m_node;
}

