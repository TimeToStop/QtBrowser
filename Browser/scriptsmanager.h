#pragma once

#include <QMap>
#include <QString>
#include <QWebEnginePage>

class ScriptsManager
{
	typedef QPair<QString, QString> Script, ScriptResult;

	QList<Script> m_all_scripts;

public:
	ScriptsManager();
	virtual ~ScriptsManager();

	bool addScript(const QString& name, const QString& path);
	QList<ScriptResult> initAllScripts(QWebEnginePage*);
	bool initScript(const QString&, QString&, QWebEnginePage*);

private:
	static bool readFile(const QString&, QString&);
	QString runScript(const QString&, QWebEnginePage*);
};

