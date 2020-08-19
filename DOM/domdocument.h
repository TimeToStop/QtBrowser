#pragma once
#include "domnode.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

class DomDocument
{
	QString m_error;
	DomNode* m_root;

public:
	DomDocument();
	~DomDocument();

	bool hasError() const;
	QString error() const;
	DomNode* root() const;

	void fromJson(const QString& json);
	void clear();

private:
	DomNode* parseNode(DomNode* parent, QVariantMap&);
};

