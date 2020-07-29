#pragma once

#include "command.h"

class ExecuteJsCmd : public Command
{
public:
	ExecuteJsCmd();
	virtual ~ExecuteJsCmd();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) override;
};

