#pragma once

#include <memory>
#include <QString>

class Page;

class Element
{
	std::weak_ptr<Page> m_page;
	bool m_is_waiting_for_redirect;
	bool m_is_array;
	QString m_name;
	QString m_path;

public:
	Element(std::weak_ptr<Page> page, bool is_array, bool is_waiting_for_redirect, const QString& name, const QString& path);
	~Element();

	void setIsWaitingForRedirect(bool);
	void setName(const QString&);

	std::shared_ptr<Page> page() const;
	bool isWaitingForRedirect() const;
	bool isArray() const;
	QString name() const;
	QString path() const;
};

