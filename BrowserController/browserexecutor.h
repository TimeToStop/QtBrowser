#pragma once
#include "browser.h"
#include "commandexecutor.h"

#include <QProcess>
#include <QTcpServer>
#include <QTcpSocket>

class BrowserExecutor : public QObject
{
	Q_OBJECT;

	bool m_is_terminate;
	Browser* m_browser;
	CommandExecutor* m_executor;
	QProcess* m_process;
	QTcpServer* m_server;
	QTcpSocket* m_client_socket;

public:
	BrowserExecutor();
	virtual ~BrowserExecutor();

	void setBrowser(Browser*);
	void setIsTerminateExecution(bool);
	void clientDisconnected();
	bool start(const QString&);
	void close();

	Browser* browser() const;

signals:
	void taskFinished(bool);

public slots:
	void newConnection();
	void clientReadReady();

private:
	void processData(QByteArray&);
};

