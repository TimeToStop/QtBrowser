#include "logcmd.h"

#include "debug.h"

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
		CONSOLE_LOG(QString(data));
		break;
	case LogType::WARNING:
		CONSOLE_WARNING(QString(data));
		break;
	case LogType::ERROR:
		CONSOLE_ERROR(QString(data));
		break;
	default:
		break;
	}

	return QByteArray();
}
