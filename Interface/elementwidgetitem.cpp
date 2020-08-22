#include "elementwidgetitem.h"

#include "editelement.h"
#include "../ProjectManager/page.h"

ElementWidgetItem::ElementWidgetItem(std::shared_ptr<Element> element, QTreeWidgetItem *parent):
	QTreeWidgetItem(parent),
	m_element(element)
{
}

ElementWidgetItem::~ElementWidgetItem()
{
}

void ElementWidgetItem::doubleClicked()
{
	EditElement d(m_element, treeWidget());

	if (d.exec() == QDialog::Accepted)
	{
		m_element->setName(d.name());
		m_element->setIsWaitingForRedirect(d.waitForRedirect());

		setText(1, d.name());
	}
}

void ElementWidgetItem::removeElement()
{
	m_element->page()->removeElement(m_element);
}
