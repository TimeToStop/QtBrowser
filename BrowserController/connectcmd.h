#pragma once

#include "command.h"

class ConnectCmd : public Command
{
	static const QByteArray key;

public:
	ConnectCmd();
	virtual ~ConnectCmd();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) override;
};

