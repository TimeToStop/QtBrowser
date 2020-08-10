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
	QString m_register_qt_object_script;
	ScriptsManager m_scripts;

public:
	Browser(QWidget *parent);
	virtual ~Browser();

	bool isLastLoadedSuccessful() const;
	void loadURL(const QString&);
	void setDefaultScripts(const QList<QPair<QString, QString>>& scripts);
	void removeDefaultScript(const QString&);
	void clearDefaultScripts();
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
