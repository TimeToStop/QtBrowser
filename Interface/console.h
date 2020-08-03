#pragma once

#include <QWidget>
namespace Ui { class Console; };

class Console : public QWidget
{
	Q_OBJECT;

	int m_wheel_scroll_speed;

public:
	Console(QWidget *parent = Q_NULLPTR);
	virtual ~Console();

	void setMaxWidth(int);
	void setWheelScrollSpeed(int);
	void setFont(const QFont&);
	void setLogColor(const QColor&);
	void setWarningColor(const QColor&);
	void setErrorColor(const QColor&);

	void log(const QString&);
	void warning(const QString&);
	void error(const QString&);

	void clear();

	int consoleViewWidth();

protected:
	virtual void wheelEvent(QWheelEvent*) override;
	virtual void resizeEvent(QResizeEvent*) override;

public slots:
	void verticalSliderMoved(int);
	void horizontalSliderMoved(int);

private:
	void viewChanged();

	Ui::Console *ui;
};
