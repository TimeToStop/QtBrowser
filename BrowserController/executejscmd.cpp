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
    byte header = 0;
    QByteArray header_wrapper;
    QString result = executor->browser()->syncJavaScriptExecuting(script);
    if (result.startsWith("Uncaught"))
    {
        header |= (byte)HeaderInfo::EXCEPTION;
    }
    
    header_wrapper.push_back(header);
    return header_wrapper + result.toUtf8();
}
