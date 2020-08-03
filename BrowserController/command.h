#pragma once
#include <QByteArray>

class BrowserExecutor;

typedef unsigned char byte;

class Command
{
public:
	Command();
	virtual ~Command();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) = 0;
};

