#include "disconnectcmd.h"
#include "browserexecutor.h"

DisconnectCmd::DisconnectCmd():
	Command()
{
}

DisconnectCmd::~DisconnectCmd()
{
}

QByteArray DisconnectCmd::execute(BrowserExecutor* executor, const QByteArray&)
{
	executor->setIsTerminateExecution(false);
	return QByteArray();
}
