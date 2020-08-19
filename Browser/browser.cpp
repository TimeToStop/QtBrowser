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

QString Browser::htmlToJson()
{
	return syncJavaScriptExecuting("source();");
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

QString Browser::syncJavaScriptExecuting(const QString& script, bool wait_for_redirect, qint64 world)
{
	QString result;
	TaskExecutor redirection;

	if (wait_for_redirect)
	{
		redirection.addListenFor(this, &Browser::syncLoadFinished);
	}

	redirection.execute([&]()
	{
		TaskExecutor task;
		task.execute([&]()
		{
			page()->runJavaScript(script, world, [&](const QVariant& v)
			{
				result = v.toString();
				task.taskExecuted();
				if (!wait_for_redirect)
				{
					redirection.taskExecuted();
				}
			});
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

