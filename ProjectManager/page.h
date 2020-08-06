#pragma once

#include "element.h"

#include <memory>
#include <vector>

class Page : public PageMetaData
{
	QString m_name;
	QString m_request_url;
	QString m_check_url;
	std::vector<std::shared_ptr<Element>> m_elements;

public:
	Page(const QString&);
	~Page();

	virtual void dumpToFile(QFile&) const override;

	void setName(const QString&);

	void setRequestURL(const QString&);
	void setCheckURL(const QString&);

	void addElement(const std::shared_ptr<Element>&);
	void addElement(std::shared_ptr<Element>&&);

	QString name() const;
	size_t size() const;
	std::shared_ptr<Element> getElement(size_t);

	std::shared_ptr<Element> operator[](size_t);
};

