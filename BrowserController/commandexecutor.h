#pragma once
#include <QMap>
#include <memory>

#include "command.h"

enum class CommandType : int
{
	DISCONNECT = 0,

	LOAD_URL = 3,

	FIND_BY_ID,

	CONSOLE_LOG,
	CONSOLE_WARNING,
	CONSOLE_ERROR
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

