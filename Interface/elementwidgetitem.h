#pragma once

#include "../ProjectManager/element.h"
#include <QTreeWidget>

class ElementWidgetItem : public QTreeWidgetItem
{
	std::shared_ptr<Element> m_element;

public:
	ElementWidgetItem(std::shared_ptr<Element> element, QTreeWidgetItem *parent);
	virtual ~ElementWidgetItem();

	void doubleClicked();
};
