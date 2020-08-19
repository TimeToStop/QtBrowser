#include "domnodewidgetitem.h"

DomNodeWidgetItem::DomNodeWidgetItem(DomNode* node):
    QTreeWidgetItem(),
    m_node(node)
{
}

DomNodeWidgetItem::~DomNodeWidgetItem()
{
}

DomNode* DomNodeWidgetItem::node() const
{
    return m_node;
}

