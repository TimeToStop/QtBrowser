#pragma once
#include <QFile>

class PageMetaData
{
public:
	PageMetaData();
	virtual ~PageMetaData();

private:
	virtual void dumpToFile(QFile&) const = 0;
};

