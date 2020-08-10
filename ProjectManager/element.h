#pragma once

#include <QString>

class Page;

class Element
{
	Page* m_page;
	QString m_name;
	QString m_path;

public:
	Element(const QString&, const QString&);
	~Element();

	void setPage(Page*);

	QString name() const;
	QString path() const;
};

