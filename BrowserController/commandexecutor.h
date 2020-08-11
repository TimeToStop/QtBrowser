#pragma once
#include <QMap>
#include <memory>

#include "command.h"

enum class CommandType : int
{
	DISCONNECT			 = 0,
	CONNECT				 = 1,
	INITIALIZATION		 = 2,
	LOAD_URL			 = 3,
	LOG					 = 4,
	EXECUTE_JS			 = 5,
	EXECUTE_JS_FROM_FILE = 6
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

