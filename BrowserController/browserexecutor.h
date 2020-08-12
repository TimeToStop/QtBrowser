#pragma once
#include "browser.h"
#include "commandexecutor.h"

#include "../ProjectManager/project.h"
#include "console.h"

#include <QProcess>
#include <QTcpServer>
#include <QTcpSocket>

class BrowserExecutor : public QObject
{
	Q_OBJECT;

	bool m_is_terminate;
	std::shared_ptr<Project> m_project;
	Browser* m_browser;
	Console* m_console;
	CommandExecutor* m_executor;
	QProcess* m_process;
	QTcpServer* m_server;
	QTcpSocket* m_client_socket;

public:
	BrowserExecutor();
	virtual ~BrowserExecutor();

	void setBrowser(Browser*);
	void setConsole(Console*); 
	void setIsTerminateExecution(bool);
	void clientDisconnected();
	bool start(std::shared_ptr<Project>);
	void close();

	Browser* browser() const;
	QString getFileName(const QString&) const;

signals:
	void taskFinished(bool);

public slots:
	void newConnection();
	void clientReadReady();

private:
	void processData(QByteArray&);
};

