#pragma once

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
	Page* m_page;
	bool m_is_waiting_for_redirect;
	ElementType m_type;
	QString m_name;
	QString m_path;

public:
	Element(bool is_waiting_for_redirect, ElementType type, const QString& name, const QString& path);
	~Element();

	void setPage(Page*);

	bool isWaitingForRedirect() const;
	ElementType type() const;
	QString name() const;
	QString path() const;
};

