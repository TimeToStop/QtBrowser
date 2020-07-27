#include "loadurlcmd.h"
#include <QString>

#include "browserexecutor.h"

LoadURLCmd::LoadURLCmd():
    Command()
{
}

LoadURLCmd::~LoadURLCmd()
{
}

QByteArray LoadURLCmd::execute(BrowserExecutor* executor, const QByteArray& data)
{
    QString url(data);
    executor->browser()->loadURL(url);
    QString current_url = executor->browser()->url().toString();
    return current_url.toUtf8();
}
