#include "browserexecutor.h"

#include "taskexecutor.h"

#include <QFile>

BrowserExecutor::BrowserExecutor():
	m_project(),
	m_is_terminate(false),
	m_browser(nullptr),
	m_console(nullptr),
	m_executor(new CommandExecutor()),
	m_process(new QProcess()),
	m_server(new QTcpServer()),
	m_client_socket(nullptr)
{
}

BrowserExecutor::~BrowserExecutor()
{
	delete m_executor;
	delete m_process;
	delete m_server;
}

void BrowserExecutor::newConnection()
{
	m_console->log("New connection found");

	if (!m_client_socket)
	{
		m_console->log("Connection accepted");
		m_client_socket = m_server->nextPendingConnection();
		m_client_socket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
		QObject::connect(m_client_socket, &QTcpSocket::readyRead, this, &BrowserExecutor::clientReadReady);
		QObject::connect(m_client_socket, &QTcpSocket::disconnected, this, &BrowserExecutor::clientDisconnected);
	}
	else
	{
		m_console->log("Connection is not unique");
		m_console->log("Connect rejected");
	}
}

void BrowserExecutor::setBrowser(Browser* browser)
{
	m_browser = browser;
}

void BrowserExecutor::setConsole(Console* console)
{
	m_console = console;
}

void BrowserExecutor::setIsTerminateExecution(bool b)
{
	m_is_terminate = b;
}

void BrowserExecutor::close()
{
	if (m_server->isListening())
	{
		m_console->log("Application is closed");
		m_server->close();
	}

	m_client_socket = nullptr;
}

Browser* BrowserExecutor::browser() const
{
	return m_browser;
}

QString BrowserExecutor::getFileName(const QString& path) const
{
	if (!path.isEmpty() && path[0] != '/')
	{
		return m_project->path() + "source/" + path;
	}
	else
	{
		return m_project->path() + "source" + path;
	}

}

void BrowserExecutor::clientDisconnected()
{
	m_console->log(QStringLiteral("Client disconnect: ") + (m_is_terminate ? "terminated" : "normal"));
	m_client_socket = nullptr;
	close();
	emit(taskFinished(m_is_terminate));
}

bool BrowserExecutor::start(std::shared_ptr<Project> project)
{
	m_project = project;

	if (!m_server->listen(QHostAddress::LocalHost))
	{
		m_console->log("Cannot start application");
		return false;
	}
	else
	{
		m_console->log("Application has been started");
		QObject::connect(m_server, &QTcpServer::newConnection, this, &BrowserExecutor::newConnection);
		m_project->writePort(m_server->serverPort());
		return true;
	}
}

void BrowserExecutor::clientReadReady()
{
	QByteArray data = m_client_socket->readAll();

	while(m_client_socket->bytesAvailable())
	{
		data += m_client_socket->readAll();
	}

	processData(data);
}

void BrowserExecutor::processData(QByteArray& data)
{
	QByteArray answer = m_executor->execute(this, data);
	if (answer.size())
	{
		m_client_socket->write(answer);
		m_client_socket->flush();
	}
}
