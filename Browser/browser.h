#pragma once

#include <QWebEngineView>
#include <QWebEngineScript>

class Browser : public QWebEngineView
{
	Q_OBJECT;

	QString m_script;

public:
	Browser(QWidget *parent);
	virtual ~Browser();

	void loadURL(const QString&);
	QString syncJavaScriptExecuting(const QString&, qint64 = QWebEngineScript::MainWorld);

signals:
	void syncLoadStarted();
	void syncLoadProgress(int);
	void syncLoadFinished(bool);

	void hovered(const QString&, const QString&, const QStringList&, const QString&);

public slots:
	void loadStartedSlot();
	void loadProgressSlot(int);
	void loadFinishedSlot(bool);
	void hoveredSlot(const QString&, const QString&, const QStringList&, const QString&);

private:
	void initScript();
	static QString loadFile(const QString&);
};
