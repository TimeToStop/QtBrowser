#include "executejscmd.h"

#include <QString>
#include "browserexecutor.h"

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
