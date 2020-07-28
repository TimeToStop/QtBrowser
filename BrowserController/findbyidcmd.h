#pragma once
#include "command.h"

class FindByIdCmd : public Command
{
public:
	FindByIdCmd();
	virtual ~FindByIdCmd();

	virtual QByteArray execute(BrowserExecutor*, const QByteArray&) override;
};

