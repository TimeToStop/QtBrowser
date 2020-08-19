#include "dompath.h"

#include "domarraypath.h"


DomPath::DomPath(DomNode* node):
	m_node(node),
	m_list()
{
}

DomPath::~DomPath()
{
}

QString DomPath::toString() const
{
	QString result;

	for (const QPair<QString, int>& element : m_list)
	{
		result = element.first + "[" + QString::number(element.second) + "]/" + result;
	}

	return result;
}

bool DomPath::matchElementSequence(const DomArrayPath& array) const
{
	if (m_list.size() != array.m_list.size())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < m_list.size(); i++)
		{
			if (m_list[i].first != array.m_list[i].first)
			{
				return false;
			}
		}

		return true;
	}
}

void DomPath::update()
{
	int node_index = -1;
	m_list.clear();

	if (m_node->parent() != nullptr)
	{
		int index = m_node->parentIndex();
		m_list = m_node->parent()->path()->m_list;
		
		for (int i = 0; i <= index; i++)
		{
			if (m_node->tag() == m_node->parent()->child(i)->tag())
			{
				node_index++;
			}
		}
	}
	else
	{
		node_index = 0;
	}

	m_list.push_front(QPair<QString, int>(m_node->tag().toUpper(), node_index));
}
