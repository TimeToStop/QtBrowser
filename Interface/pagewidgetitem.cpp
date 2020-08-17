#include "pagewidgetitem.h"

#include "../ProjectManager/project.h"

PageWidgetItem::PageWidgetItem(std::shared_ptr<Page> page, QTreeWidget *parent):
	QTreeWidgetItem(parent),
	m_page(page)
{
}

PageWidgetItem::~PageWidgetItem()
{
}

void PageWidgetItem::removePage()
{
	m_page->project()->removePage(m_page);
}
