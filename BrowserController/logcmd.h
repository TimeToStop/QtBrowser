#pragma once

#include "command.h"

enum class LogType : int
{
	LOG		= 0,
	WARNING = 1,
	ERROR	= 2
};

class LogCmd : public Command
{
public:
	LogCmd();
	virtual ~LogCmd();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) override;
};


