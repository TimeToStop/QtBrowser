#include "domdocument.h"

#include "dompath.h"

DomDocument::DomDocument():
    m_error(),
    m_root(nullptr)
{
}

DomDocument::~DomDocument()
{
    clear();
}

bool DomDocument::hasError() const
{
    return !m_error.isEmpty();
}

QString DomDocument::error() const
{
    return m_error;
}

DomNode* DomDocument::root() const
{
    return m_root;
}

void DomDocument::clear()
{
    if (m_root != nullptr)
    {
        delete m_root;
        m_root = nullptr;
    }
}

void DomDocument::fromJson(const QString& json)
{
    QJsonDocument document = QJsonDocument::fromJson(json.toUtf8());

    if (document.isObject())
    {
        QVariantMap map = document.object().toVariantMap();
        clear();
        m_error = "";
        m_root = parseNode(nullptr, map);
    }
    else
    {
        m_error = "Bad json input: cannot parse json document";
    }
}

DomNode* DomDocument::parseNode(DomNode* parent, QVariantMap& json_node)
{
    if (json_node.contains("tag") && json_node.contains("id")
        && json_node.contains("classList") && json_node.contains("children"))
    {
        DomNode* node = new DomNode(parent);

        node->setId(json_node["id"].toString());
        node->setTag(json_node["tag"].toString());
        node->setClassList(json_node["classList"].toStringList());

        QVariantList children = json_node["children"].toList();

        for (QVariant& child : children)
        {
            DomNode* child_node = parseNode(node, child.toMap());

            if (!child_node)
            {
                delete node;
                return nullptr;
            }
        }

        return node;
    }
    else
    {   
        m_error = "Bad json input: json does not contains main properties";
        return nullptr;
    }
}
