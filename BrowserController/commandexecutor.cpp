#include "commandexecutor.h"
#include "debug.h"
#include "browserexecutor.h"

#include "connectcmd.h"
#include "disconnectcmd.h"
#include "loadurlcmd.h"
#include "logcmd.h"
#include "executejscmd.h"
#include "executejsfromfile.h"

CommandExecutor::CommandExecutor():
    m_commands()
{
    m_commands.insert(CommandType::CONNECT,              std::make_shared<ConnectCmd>       ());
    m_commands.insert(CommandType::DISCONNECT,           std::make_shared<DisconnectCmd>    ());
    m_commands.insert(CommandType::LOAD_URL,             std::make_shared<LoadURLCmd>       ());
    m_commands.insert(CommandType::LOG,                  std::make_shared<LogCmd>           ());
    m_commands.insert(CommandType::EXECUTE_JS,           std::make_shared<ExecuteJsCmd>     ());
    m_commands.insert(CommandType::EXECUTE_JS_FROM_FILE, std::make_shared<ExecuteJsFromFile>());
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
