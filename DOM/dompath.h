#pragma once
#include "domnode.h"

#include <QList>
#include <QPair>

class DomArrayPath;

class DomPath
{
	friend class DomArrayPath;

	DomNode* m_node;
	QList<QPair<QString, int>> m_list;

public:
	DomPath(DomNode*);
	~DomPath();

	QString toString() const;

	bool matchElementSequence(const DomArrayPath&) const;
	void update();
};

