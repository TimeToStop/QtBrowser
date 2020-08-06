#pragma once

#include <QString>

#include "pagemetadata.h"

class Page;

class Element : public PageMetaData
{
	Page* m_page;
	QString m_name;
	QString m_path;

public:
	Element(const QString&, const QString&);
	~Element();

	virtual void dumpToFile(QFile&) const override;

	void setPage(Page*);

	QString name() const;
	QString path() const;
};

