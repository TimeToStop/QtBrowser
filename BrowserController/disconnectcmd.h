#pragma once
#include "command.h"

class DisconnectCmd : public Command
{
public:
	DisconnectCmd();
	virtual ~DisconnectCmd();

	virtual QByteArray execute(BrowserExecutor*, const QByteArray&) override;
};

