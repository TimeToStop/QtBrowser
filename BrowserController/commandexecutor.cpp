#include "commandexecutor.h"
#include "debug.h"
#include "browserexecutor.h"

#include "disconnectcmd.h"
#include "loadurlcmd.h"

CommandExecutor::CommandExecutor():
    m_commands()
{
    m_commands.insert(CommandType::DISCONNECT, std::make_shared<DisconnectCmd>());
    m_commands.insert(CommandType::LOAD_URL,   std::make_shared<LoadURLCmd>());
}

CommandExecutor::~CommandExecutor()
{
    m_commands.clear();
}

QByteArray CommandExecutor::execute(BrowserExecutor* executor, QByteArray& data)
{
    CommandType type = static_cast<CommandType>(static_cast<int>(data[0]));
    data.remove(0, 1);
    if (m_commands.contains(type))
    {
        return m_commands.find(type).value()->execute(executor, data);
    }
    else
    {
        CONSOLE_LOG("Calling unknown command");
        return QByteArray();
    }
}
