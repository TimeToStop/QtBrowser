#pragma once

#include <QTextEdit>

class Console : public QTextEdit
{
	Q_OBJECT

public:
	Console(QWidget *parent = nullptr);
	virtual ~Console();

	void log(const QString&);
	void warning(const QString&);
	void error(const QString&);

	void logHtml(const QString&);
	void warningHtml(const QString&);
	void errorHtml(const QString&);
};
