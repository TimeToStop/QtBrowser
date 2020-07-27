#include "browserexecutor.h"

#include "debug.h"
#include "taskexecutor.h"

#include <QFile>

BrowserExecutor::BrowserExecutor():
	m_is_terminate(false),
	m_browser(nullptr),
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
	if (!m_client_socket)
	{
		CONSOLE_LOG("New connection accepted");
		m_client_socket = m_server->nextPendingConnection();
		m_client_socket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
		QObject::connect(m_client_socket, &QTcpSocket::readyRead, this, &BrowserExecutor::clientReadReady);
		QObject::connect(m_client_socket, &QTcpSocket::disconnected, this, &BrowserExecutor::clientDisconnected);
	}
	else
	{
		CONSOLE_LOG("More than one connection does not accepted");
	}
}

void BrowserExecutor::setBrowser(Browser* browser)
{
	m_browser = browser;
}

void BrowserExecutor::setIsTerminateExecution(bool b)
{
	m_is_terminate = b;
}

void BrowserExecutor::close()
{
	if (m_server->isListening())
	{
		m_server->close();
	}

	m_client_socket = nullptr;
}

Browser* BrowserExecutor::browser() const
{
	return m_browser;
}

void BrowserExecutor::clientDisconnected()
{
	CONSOLE_LOG("Task finished");
	close();
	emit(taskFinished(m_is_terminate));
}

bool BrowserExecutor::start(const QString& project)
{
	if (!m_server->listen(QHostAddress::LocalHost))
	{
		CONSOLE_LOG("Cannot run server!");
		return false;
	}
	else
	{
		CONSOLE_LOG("Server run at port: " + QString::number(m_server->serverPort()));
		QObject::connect(m_server, &QTcpServer::newConnection, this, &BrowserExecutor::newConnection);
		QFile file(project + "/properties.prop");
		if (file.open(QIODevice::WriteOnly))
		{
			file.write(QString::number(m_server->serverPort()).toUtf8());
			file.flush();
			file.close();
		}
		else
		{
			CONSOLE_LOG("Cannot write port to file \"properties.prop\"");
		}

		return true;
	}
}

void BrowserExecutor::clientReadReady()
{
	CONSOLE_LOG("Read data form programm");
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
