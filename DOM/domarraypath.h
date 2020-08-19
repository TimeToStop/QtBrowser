#pragma once
#include "domnode.h"

class DomPath;

class DomArrayPath
{
	friend class DomPath;
	QList<QPair<QString, int>> m_list;

public:
	DomArrayPath();
	~DomArrayPath();

	bool isEmpty() const;
	QString toString() const;

	bool addDomPath(const DomPath&);
	void clear();
};

