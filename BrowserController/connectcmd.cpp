#include "connectcmd.h"

#include <QString>

const QByteArray ConnectCmd::header = QStringLiteral("\0").toUtf8();
const QByteArray ConnectCmd::key    = QStringLiteral("9456327810").toUtf8();
const QByteArray ConnectCmd::answer = header + key;

ConnectCmd::ConnectCmd():
    Command()
{
}

ConnectCmd::~ConnectCmd()
{
}

QByteArray ConnectCmd::execute(BrowserExecutor*, QByteArray& data)
{
    if (data == key)
    {
        return answer;
    }
    else
    {
        return QByteArray();
    }
}
