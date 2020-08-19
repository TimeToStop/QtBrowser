#pragma once

#include <vector>
#include <QString>
#include <QStringList>

class DomPath;

class DomNode
{
	DomNode* m_parent;
	std::vector<DomNode*> m_children;

	DomPath* m_path;
	QString m_id;
	QString m_tag;
	QStringList m_class_list;

public:
	DomNode(DomNode* parent = nullptr);
	DomNode(const QString& id, const QString& tag, const QStringList& classes, DomNode* parent = nullptr);
	~DomNode();

	size_t childCount() const; 
	size_t parentIndex() const;
	size_t indexOfChild(const DomNode*) const;

	DomNode* parent() const;
	DomNode* child(size_t) const;

	DomPath* path() const;
	QString id() const;
	QString tag() const;
	QStringList classList() const;

	void setParent(DomNode*);

	void addChild(DomNode*);
	void removeChild(int);
	void removeChild(DomNode*);

	void setId(const QString&);
	void setTag(const QString&);
	void setClassList(const QStringList&);
};

