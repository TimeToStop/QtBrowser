#pragma once

#include "../DOM/domdocument.h"

#include <QTreeWidget>

class SourceTree : public QTreeWidget
{
	Q_OBJECT

	DomDocument m_document;

public:
	SourceTree(QWidget *parent);
	virtual ~SourceTree();

	void setJsonHTML(const QString&);

private:
	QTreeWidgetItem* parseDomTree(DomNode* e);
};
