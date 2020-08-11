#include "browser.h"

#include "taskexecutor.h"
#include "hoverhandler.h"

#include <QWebEngineScript>
#include <QFile>
#include <QWebChannel>

Browser::Browser(QWidget *parent):
	QWebEngineView(parent),
	m_default_script_names(),
	m_is_last_loaded_successful(false),
	m_is_browser_init_loading(false),
	m_register_qt_object_script(),
	m_scripts()
{	
	QFile qt_object_scripts("JS/qwebchannel.js");
	if (qt_object_scripts.open(QIODevice::ReadOnly))
	{
		m_register_qt_object_script = qt_object_scripts.readAll();
		qt_object_scripts.close();
	}

	connect(this, &QWebEngineView::loadStarted,  this, &Browser::loadStartedSlot);
	connect(this, &QWebEngineView::loadProgress, this, &Browser::loadProgressSlot);
	connect(this, &QWebEngineView::loadFinished, this, &Browser::loadFinishedSlot);
}

Browser::~Browser()
{
}

bool Browser::isLastLoadedSuccessful() const
{
	return m_is_last_loaded_successful;
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
	task.execute([&url, page]() 
	{
		page->load(QUrl(url));
	});	

	TaskExecutor task_qt_objects;
	task_qt_objects.execute([&task_qt_objects, page, this]()
	{
			page->runJavaScript(m_register_qt_object_script, QWebEngineScript::MainWorld, [&task_qt_objects](const QVariant&)
			{
				task_qt_objects.taskExecuted();
			});
	});

	m_scripts.initAllScripts(page);
	m_is_browser_init_loading = false;
}

void Browser::addDefaultScript(const QString& name, const QString& path)
{
	m_scripts.addScript(name, path);
}

void Browser::addDefaultScript(const QString& path)
{
	m_scripts.addScript("", path);
}

void Browser::setDefaultScripts(const QList<QPair<QString, QString>>& scripts)
{
	for (const QPair<QString, QString>& script : scripts)
	{
		m_scripts.addScript(script.first, script.second);
	}
}

void Browser::removeDefaultScript(const QString& name)
{
	m_scripts.removeScript(name);
}

void Browser::clearDefaultScripts()
{
	m_scripts.clear();
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
		TaskExecutor task_qt_objects;
		task_qt_objects.execute([&task_qt_objects, this]()
		{
			page()->runJavaScript(m_register_qt_object_script, QWebEngineScript::MainWorld, [&task_qt_objects](const QVariant&)
			{
				task_qt_objects.taskExecuted();
			});
		});


		m_scripts.initAllScripts(page());
	}

	m_is_last_loaded_successful = b;
	emit(syncLoadProgress(100));
	emit(syncLoadFinished(b));
}

void Browser::hoveredSlot(const QString& tag, const QString& id, const QStringList& classes, const QString& inner, const QString& path)
{
	hovered(tag, id, classes, inner, path);
}

//
//if (!m_scripts.addScript("jquery", "JS/jquery-3-5-1.min.js"))
//{
//	CONSOLE_WARNING("Cannot read file: JS/jquery-3-5-1.min.js");
//}
//
//if (!m_scripts.addScript("webchannel", "JS/qwebchannel.js"))
//{
//	CONSOLE_WARNING("Cannot read file: JS/qwebchannel.js");
//}
//
//if (!m_scripts.addScript("init", "JS/init.js"))
//{
//	CONSOLE_WARNING("Cannot read file: JS/init.js");
//}
//
//if (!m_scripts.addScript("find", "JS/find.js"))
//{
//	CONSOLE_WARNING("Cannot read file: JS/find.js");
//}
//
//if (!m_scripts.addScript("hover", "JS/hover.js"))
//{
//	CONSOLE_WARNING("Cannot read file: JS/hover.js");
//}