#pragma once

#include "command.h"

class ExecuteJsCmd : public Command
{
	enum HeaderInfo : byte
	{
		EXCEPTION = 0x1
	};

public:
	ExecuteJsCmd();
	virtual ~ExecuteJsCmd();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) override;
};

