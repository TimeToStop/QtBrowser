#pragma once
#include <QMap>
#include <memory>

#include "command.h"

enum class CommandType : int
{
	DISCONNECT			 = 0,
	CONNECT				 = 1,
	LOAD_URL			 = 2,
	LOG					 = 3,
	EXECUTE_JS			 = 4,
	EXECUTE_JS_FROM_FILE = 5
};

class BrowserExecutor;

class CommandExecutor
{
	QMap<CommandType, std::shared_ptr<Command>> m_commands;

public:
	CommandExecutor();
	~CommandExecutor();

	QByteArray execute(BrowserExecutor*, QByteArray&);
};

