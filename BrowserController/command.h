#pragma once
#include <QByteArray>

class BrowserExecutor;

class Command
{
public:
	Command();
	virtual ~Command();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) = 0;
};

