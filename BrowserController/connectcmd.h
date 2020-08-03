#pragma once

#include "command.h"

class ConnectCmd : public Command
{
	static const QByteArray header;
	static const QByteArray key;
	static const QByteArray answer;

public:
	ConnectCmd();
	virtual ~ConnectCmd();

	virtual QByteArray execute(BrowserExecutor*, QByteArray&) override;
};

