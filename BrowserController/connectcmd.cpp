#include "connectcmd.h"

#include <QString>

const QByteArray ConnectCmd::key = QStringLiteral("9456327810").toUtf8();

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
        return key;
    }
    else
    {
        return QByteArray();
    }
}
