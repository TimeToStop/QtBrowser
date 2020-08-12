#include "initcmd.h"

#include "browserexecutor.h"

InitCmd::InitCmd()
{
}

InitCmd::~InitCmd()
{
}

QByteArray InitCmd::execute(BrowserExecutor* executor, QByteArray& data)
{
    QStringList list = QString(data).split(" ");
   
    for (const QString& path : list)
    {
        executor->browser()->addDefaultScript(executor->getFileName(path));
    }

    return QByteArray();
}
