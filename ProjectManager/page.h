#pragma once

#include "element.h"

#include <memory>
#include <vector>

class Page 
{
	QString m_name;
	QString m_request_url;
	QString m_target_url;
	std::vector<std::shared_ptr<Element>> m_elements;

public:
	Page(const QString&);
	virtual ~Page();

	void setName(const QString&);

	void setRequestURL(const QString&);
	void setTargetURL(const QString&);

	void addElement(const std::shared_ptr<Element>&);
	void addElement(std::shared_ptr<Element>&&);

	QString name() const;
	QString request() const;
	QString target() const;

	size_t size() const;
	std::shared_ptr<Element> getElement(size_t);

	std::shared_ptr<Element> operator[](size_t);
};

