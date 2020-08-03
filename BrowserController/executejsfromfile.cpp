#include "executejsfromfile.h"

#include "browserexecutor.h"
#include <QFile>

ExecuteJsFromFile::ExecuteJsFromFile():
    Command()
{
}

ExecuteJsFromFile::~ExecuteJsFromFile()
{
}

QByteArray ExecuteJsFromFile::execute(BrowserExecutor* executor, QByteArray& file_name)
{
    byte header = 0;
    QByteArray header_wrapper;
    QString result;
    QFile f(file_name);

    if (f.open(QIODevice::ReadOnly))
    {
        QString script = f.readAll();
        result = executor->browser()->syncJavaScriptExecuting(script);

        if (result.startsWith("Uncaught"))
        {
            header |= (byte)HeaderInfo::EXECUTE_EXCEPTION;
        }

        f.close();
    }
    else
    {
        header |= (byte)HeaderInfo::FILE_NOT_FOUND;
    }

    header_wrapper.push_back(header);
    return header_wrapper + result.toUtf8();
}
