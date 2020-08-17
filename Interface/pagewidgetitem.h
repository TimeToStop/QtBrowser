#pragma once

#include "../ProjectManager/page.h"
#include <QTreeWidget>

class PageWidgetItem : public QTreeWidgetItem
{
	std::shared_ptr<Page> m_page;

public:
	PageWidgetItem(std::shared_ptr<Page>, QTreeWidget*parent);
	virtual ~PageWidgetItem();

	void removePage();
};
