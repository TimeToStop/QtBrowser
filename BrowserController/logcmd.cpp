#include "logcmd.h"

LogCmd::LogCmd()
{
}

LogCmd::~LogCmd()
{
}

QByteArray LogCmd::execute(BrowserExecutor*, QByteArray& data)
{
	LogType type = (LogType)(int)data[0];
	data.remove(0, 1);

	switch (type)
	{
	case LogType::LOG:
		break;
	case LogType::WARNING:
		break;
	case LogType::ERROR:
		break;
	default:
		break;
	}

	return QByteArray();
}
