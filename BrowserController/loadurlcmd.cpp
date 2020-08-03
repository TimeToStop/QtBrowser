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

QByteArray LoadURLCmd::execute(BrowserExecutor* executor, QByteArray& data)
{
    QString url(data);
    executor->browser()->loadURL(url);
    byte header = 0;
    QByteArray header_wrapper;
    QString current_url = executor->browser()->url().toString();

    if (!executor->browser()->isLastLoadedSuccessful())
    {
        header |= (char)HeaderInfo::LOAD_ERROR;
    }

    header_wrapper.push_back(header);
    return header_wrapper + current_url.toUtf8();
}
