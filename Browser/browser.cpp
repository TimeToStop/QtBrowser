#include "browser.h"

#include "taskexecutor.h"
#include "hoverhandler.h"

#include <QtWebEngineWidgets/qwebenginescript.h>
#include <QtCore/qfile.h>
#include <QtWebChannel/qwebchannel.h>

#include "debug.h"

Browser::Browser(QWidget *parent):
	QWebEngineView(parent)
{
	initScript();
	
	connect(this, &QWebEngineView::loadStarted,  this, &Browser::loadStartedSlot);
	connect(this, &QWebEngineView::loadProgress, this, &Browser::loadProgressSlot);
	connect(this, &QWebEngineView::loadFinished, this, &Browser::loadFinishedSlot);
}

Browser::~Browser()
{
}

void Browser::loadURL(const QString& url)
{
	QWebEnginePage* page = new QWebEnginePage(this);
	QWebChannel* channel = new QWebChannel(page);
	HoverHandler* handler = new HoverHandler(page);
	connect(handler, &HoverHandler::hovered, this, &Browser::hoveredSlot);
	channel->registerObject("hover_handler", handler);
	page->setWebChannel(channel);
	setPage(page);

	TaskExecutor task;
	task.addListenFor<QWebEngineView>(this, &QWebEngineView::loadFinished);
	task.execute([&url, page]() {
		CONSOLE_LOG("Synchronized loading started");
		page->load(QUrl(url));
	});

	task.rmListenFor<QWebEngineView>(this, &QWebEngineView::loadFinished);
	task.execute([page, this, &task]() {
			CONSOLE_LOG("Run initial scripts");
			page->runJavaScript(m_script, QWebEngineScript::MainWorld, [&task, this](const QVariant& v) {
			task.taskExecuted();
			});
		});

	CONSOLE_LOG("Load ended");
}

void Browser::loadStartedSlot()
{
	emit(syncLoadStarted());
}

void Browser::loadProgressSlot(int v)
{
	emit(syncLoadProgress(v * 0.8));
}

void Browser::loadFinishedSlot(bool b)
{
	if (b)
	{
		TaskExecutor task;
		task.execute([this, &task]() {
		page()->runJavaScript(m_script, QWebEngineScript::MainWorld, [&task](const QVariant& v) {
				task.taskExecuted();
			});
		});
	}

	emit(syncLoadProgress(100));
	emit(syncLoadFinished(b));
}

void Browser::hoveredSlot(const QString& tag, const QString& id, const QStringList& classes, const QString& inner)
{
	hovered(tag, id, classes, inner);
}

void Browser::initScript()
{
	QString jquery = loadFile("JS/jquery-3-5-1.min.js");
	QString qwebchannel = loadFile("JS/qwebchannel.js");
	QString init = loadFile("JS/init.js");
    QString hover = loadFile("JS/hover.js");

	m_script = (QStringList() << jquery
		<< qwebchannel
		<< init
		<< hover).join('\n');
}

QString Browser::loadFile(const QString& file_name)
{
	QString res;
	QFile file(file_name);
	if (file.open(QIODevice::ReadOnly))
	{
		QByteArray b = file.readAll();
		res = b;
	}
	else
	{
		qDebug() << "###################";
		qDebug() << "Cannot load file: " << file_name;
		qDebug() << "###################";
	}

	return res;
}


