#include "console.h"

Console::Console(QWidget *parent): 
	QPlainTextEdit(parent)
{
	setReadOnly(true);
}

Console::~Console()
{
}

void Console::log(const QString& msg)
{
	appendPlainText(msg);
}
