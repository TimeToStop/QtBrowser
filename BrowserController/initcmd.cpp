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
    QStringList list = QString(data).split("\0");
    if (list.size() >= 1)
    {
        QString source_dir = list[0];

        executor->setSourceDirectory(source_dir);

        for (int i = 1; i < list.size(); i++)
        {
            executor->browser()->addDefaultScript(executor->sourceDirectory() + list[i]);
        }
    }

    return QByteArray();
}
