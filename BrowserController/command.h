#pragma once
#include <QByteArray>

class BrowserExecutor;

class Command
{
public:
	Command();
	virtual ~Command();

	virtual QByteArray execute(BrowserExecutor*, const QByteArray&) = 0;
};

