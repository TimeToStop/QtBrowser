#include "console.h"

Console::Console(QWidget *parent): 
	QTextEdit(parent)
{
	setReadOnly(true);
}

Console::~Console()
{
}

void Console::log(const QString& msg)
{
	append("<p><font color=\"black\">" + msg + "</font></p>");
}

void Console::warning(const QString& msg)
{
	append("<p><font color=\"yellow\">" + msg + "</font></p>");
}

void Console::error(const QString& msg)
{
	append("<p><font color=\"red\">" + msg + "</font></p>");
}

void Console::logHtml(const QString& msg)
{
	append("<p><font color=\"black\"><code><pre>" + msg + "</pre></code></font></p>");
}

void Console::warningHtml(const QString& msg)
{
	append("<p><font color=\"yellow\"><code><pre>" + msg + "</pre></code></font></p>");
}

void Console::errorHtml(const QString& msg)
{
	append("<p><font color=\"red\"><code><pre>" + msg + "</pre></code></font></p>");
}

