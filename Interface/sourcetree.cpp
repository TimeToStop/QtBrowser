#include "sourcetree.h"

#include "../DOM/domnodewidgetitem.h"

SourceTree::SourceTree(QWidget* parent):
	QTreeWidget(parent),
	m_document()
{
	setSelectionMode(QAbstractItemView::SingleSelection);
}

SourceTree::~SourceTree()
{
}

void SourceTree::setJsonHTML(const QString& json)
{
	m_document.fromJson(json);

	if (!m_document.hasError())
	{
		clear();
		addTopLevelItem(parseDomTree(m_document.root()));
		expandAll();
	}
}

QTreeWidgetItem* SourceTree::parseDomTree(DomNode* e)
{
	DomNodeWidgetItem* item = new DomNodeWidgetItem(e);

	item->setText(0, QStringLiteral("<%1 id=\"%2\" class=\"%3\">").arg(
		e->tag(),
		e->id(),
		e->classList().join(" ")
	));

	for (size_t i = 0; i < e->childCount(); i++)
	{
		item->addChild(parseDomTree(e->child(i)));
	}

	return item;
}
