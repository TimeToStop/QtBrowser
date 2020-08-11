#pragma once
#include "command.h"

class InitCmd : public Command
{
public:
	InitCmd();
	virtual ~InitCmd();

	virtual QByteArray  execute(BrowserExecutor*, QByteArray&) override;
};

