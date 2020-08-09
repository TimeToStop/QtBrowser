#pragma once

#include "scriptsmanager.h"

#include <QWebEngineView>
#include <QWebEngineScript>

class Browser : public QWebEngineView
{
	Q_OBJECT;

	QStringList m_default_script_names;

	bool m_is_last_loaded_successful;
	bool m_is_browser_init_loading;
	ScriptsManager m_scripts;

public:
	Browser(QWidget *parent);
	virtual ~Browser();

	bool isLastLoadedSuccessful() const;
	void loadURL(const QString&);
	bool addDefaultPageLoadedScript(const QString& name, const QString& path_to_script);
	QString syncJavaScriptExecuting(const QString&, qint64 = QWebEngineScript::MainWorld);

signals:
	void syncLoadStarted();
	void syncLoadProgress(int);
	void syncLoadFinished(bool);

	void hovered(const QString&, const QString&, const QStringList&, const QString&, const QString&);

public slots:
	void loadStartedSlot();
	void loadProgressSlot(int);
	void loadFinishedSlot(bool);
	void hoveredSlot(const QString&, const QString&, const QStringList&, const QString&, const QString&);
};
