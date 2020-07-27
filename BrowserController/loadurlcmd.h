#pragma once
#include "command.h"

class LoadURLCmd : public Command
{
public:
	LoadURLCmd();
	virtual ~LoadURLCmd();

	virtual QByteArray execute(BrowserExecutor*, const QByteArray&) override;
};

