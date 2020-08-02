#include "executejscmd.h"

#include "browserexecutor.h"
#include <QString>

ExecuteJsCmd::ExecuteJsCmd():
    Command()
{
}

ExecuteJsCmd::~ExecuteJsCmd()
{
}

QByteArray ExecuteJsCmd::execute(BrowserExecutor* executor, QByteArray& script)
{
    return executor->browser()->syncJavaScriptExecuting(script).toUtf8();
}
