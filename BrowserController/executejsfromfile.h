#pragma once

#include "command.h"

enum class OpenFileResult : char
{
	FileNotFound = 0,
	FileFound = 1
};

class ExecuteJsFromFile : public Command
{
public:
	ExecuteJsFromFile();
	virtual ~ExecuteJsFromFile();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) override;
};
