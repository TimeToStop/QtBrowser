#include "disconnectcmd.h"
#include "browserexecutor.h"

const QByteArray DisconnectCmd::key = QStringLiteral("034782938476123").toUtf8();

DisconnectCmd::DisconnectCmd():
	Command()
{
}

DisconnectCmd::~DisconnectCmd()
{
}

QByteArray DisconnectCmd::execute(BrowserExecutor* executor, QByteArray& data)
{
	executor->setIsTerminateExecution(data == key);
	return QByteArray();
}
