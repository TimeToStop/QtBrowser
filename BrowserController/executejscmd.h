#pragma once

#include "command.h"

class ExecuteJsCmd : public Command
{
	enum class RequestHeader : byte
	{
		WAIT_FOR_REDIRECT = 0x1
	};

	enum class HeaderInfo : byte
	{
		EXCEPTION = 0x1
	};

public:
	ExecuteJsCmd();
	virtual ~ExecuteJsCmd();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) override;
};

