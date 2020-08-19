#pragma once
#include "domnode.h"

#include <QTreeWidgetItem>

class DomNodeWidgetItem : public QTreeWidgetItem
{
	DomNode* m_node;

public:
	DomNodeWidgetItem(DomNode*);
	virtual ~DomNodeWidgetItem();

	DomNode* node() const;
};

