#pragma once

#include <memory>
#include <QString>

class Page;

enum class ElementType
{
	READABLE,
	INPUT,
	CLICKABLE
};

class Element
{
	std::weak_ptr<Page> m_page;
	bool m_is_waiting_for_redirect;
	ElementType m_type;
	QString m_name;
	QString m_path;

public:
	Element(std::weak_ptr<Page> page, bool is_waiting_for_redirect, ElementType type, const QString& name, const QString& path);
	~Element();

	void setIsWaitingForRedirect(bool);
	void setElementType(ElementType);
	void setName(const QString&);

	std::shared_ptr<Page> page() const;
	bool isWaitingForRedirect() const;
	ElementType type() const;
	QString name() const;
	QString path() const;
};

