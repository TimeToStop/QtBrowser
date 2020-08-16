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

QByteArray ExecuteJsCmd::execute(BrowserExecutor* executor, QByteArray& data)
{
    byte request_header = data[0];
    byte header = 0;
    QString result;
    QByteArray header_wrapper;
    data.remove(0, 1);

    result = executor->browser()->syncJavaScriptExecuting(data, (request_header & (byte)RequestHeader::WAIT_FOR_REDIRECT) != 0);

    if (result.startsWith("Uncaught"))
    {
        header |= (byte)HeaderInfo::EXCEPTION;
    }
    
    header_wrapper.push_back(header);
    return header_wrapper + result.toUtf8();
}
