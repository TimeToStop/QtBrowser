#include "domarraypath.h"

#include "dompath.h"

DomArrayPath::DomArrayPath():
	m_list()
{
}

DomArrayPath::~DomArrayPath()
{
}

bool DomArrayPath::isEmpty() const
{
	return m_list.isEmpty();
}

QString DomArrayPath::toString() const
{
	QString result;

	for (const QPair<QString, int>& element : m_list)
	{
		QString index = (element.second != -1) ? QString::number(element.second) : "*";

		result = element.first + "[" + index +"]/" + result;
	}

	return result;
}

bool DomArrayPath::addDomPath(const DomPath& path)
{
	if (m_list.isEmpty())
	{
		m_list = path.m_list;
		return true;
	}
	else
	{
		if (!path.matchElementSequence(*this))
		{
			return false;
		}

		for (int i = 0; i < m_list.size(); i++)
		{
			if (m_list[i].second != path.m_list[i].second)
			{
				m_list[i].second = -1;
			}
		}

		return true;
	}
}

void DomArrayPath::clear()
{
	m_list.clear();
}
