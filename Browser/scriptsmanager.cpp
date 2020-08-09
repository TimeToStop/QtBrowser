#include "scriptsmanager.h"

#include "taskexecutor.h"

#include <QFile>
#include <QWebEngineScript>

ScriptsManager::ScriptsManager():
    m_all_scripts()
{
}

ScriptsManager::~ScriptsManager()
{
}

bool ScriptsManager::addScript(const QString& name, const QString& path)
{
    QString script;

    if (readFile(path, script))
    {
        m_all_scripts.append(Script(name, script));
        return true;
    }

    return false;
}

QList<ScriptsManager::ScriptResult> ScriptsManager::initAllScripts(QWebEnginePage* page)
{
    QList<ScriptResult> result;

    for (const Script& script : m_all_scripts)
    {
        result.append(ScriptResult(script.first, runScript(script.second, page)));
    }

    return result;
}

bool ScriptsManager::initScript(const QString& name, QString& res, QWebEnginePage* page)
{
    for (const Script& script : m_all_scripts)
    {
        if (script.first == name)
        {
            res = runScript(script.second, page);
            return true;
        }
    }

    return false;
}

bool ScriptsManager::readFile(const QString& path, QString& result)
{
    QFile file(path);

    if (file.open(QIODevice::ReadOnly))
    {
        result = file.readAll();
        file.close();
        return true;
    }

    return false;
}

QString ScriptsManager::runScript(const QString& script, QWebEnginePage* page)
{
    QString result;
    TaskExecutor task;
    task.execute([&task, &page, &script, &result]()
    {
            page->runJavaScript(script, QWebEngineScript::MainWorld, [&result, &task](const QVariant& v) 
            {
                    result = v.toString();
                    task.taskExecuted();
            });
    });

    return result;
}
