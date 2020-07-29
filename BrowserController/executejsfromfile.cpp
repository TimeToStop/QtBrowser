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
    QByteArray answer;
    QFile f(file_name);
    if (f.open(QIODevice::ReadOnly))
    {
        QString script = f.readAll();
        f.close();

        answer.append((char)OpenFileResult::FileFound);
        answer.append(executor->browser()->syncJavaScriptExecuting(script).toUtf8());
    }
    else
    {
        answer.append((char)OpenFileResult::FileNotFound);
    }

    return answer;
}
