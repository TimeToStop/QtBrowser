#include "browser.h"

#include "taskexecutor.h"
#include "hoverhandler.h"

#include <QtWebEngineWidgets/qwebenginescript.h>
#include <QtCore/qfile.h>
#include <QtWebChannel/qwebchannel.h>

#include "debug.h"

Browser::Browser(QWidget *parent):
	QWebEngineView(parent),
	m_is_browser_init_loading(false),
	m_scripts()
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
	m_is_browser_init_loading = true;
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

	m_scripts.initAllScripts(page);
	m_is_browser_init_loading = false;
	CONSOLE_LOG("Load ended");
}

QString Browser::syncJavaScriptExecuting(const QString& script, qint64 world)
{
	QString result;
	TaskExecutor task;
	task.execute([&task, &result, &script, &world, this]()
	{
		page()->runJavaScript(script, world, [&task, &result](const QVariant& v)
		{
			result = v.toString();
			task.taskExecuted();
		});
	});

	return result;
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
	if (!m_is_browser_init_loading)
	{
		m_scripts.initAllScripts(page());
	}

	emit(syncLoadProgress(100));
	emit(syncLoadFinished(b));
}

void Browser::hoveredSlot(const QString& tag, const QString& id, const QStringList& classes, const QString& inner, const QString& path)
{
	hovered(tag, id, classes, inner, path);
}

void Browser::initScript()
{
	if (!m_scripts.addScript("jquery", "JS/jquery-3-5-1.min.js"))
	{
		CONSOLE_WARNING("Cannot read file: JS/jquery-3-5-1.min.js");
	}

	if (!m_scripts.addScript("webchannel", "JS/qwebchannel.js"))
	{
		CONSOLE_WARNING("Cannot read file: JS/qwebchannel.js");
	}
	
	if (!m_scripts.addScript("init", "JS/init.js"))
	{
		CONSOLE_WARNING("Cannot read file: JS/init.js");
	}

	if (!m_scripts.addScript("find", "JS/find.js"))
	{
		CONSOLE_WARNING("Cannot read file: JS/find.js");
	}

	if (!m_scripts.addScript("hover", "JS/hover.js"))
	{
		CONSOLE_WARNING("Cannot read file: JS/hover.js");
	}
}