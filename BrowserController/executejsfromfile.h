#pragma once

#include "command.h"

class ExecuteJsFromFile : public Command
{
	enum class HeaderInfo : byte
	{
		FILE_NOT_FOUND = 0x1,
		EXECUTE_EXCEPTION = 0x2
	};


public:
	ExecuteJsFromFile();
	virtual ~ExecuteJsFromFile();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) override;
};
;