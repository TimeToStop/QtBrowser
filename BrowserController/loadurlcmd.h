#pragma once
#include "command.h"

enum HeaderInfo : byte
{
	LOAD_ERROR = 0x1
};

class LoadURLCmd : public Command
{
public:
	LoadURLCmd();
	virtual ~LoadURLCmd();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) override;
};

