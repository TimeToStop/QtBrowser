#pragma once

#include <QWidget>
#include <QPen>

enum class MessageType
{
	LOG,
	WARNING,
	ERROR
};

class ConsoleView : public QWidget
{
	Q_OBJECT;

	static const int m_h_margin;
	static const int m_bottom_margin;

	int m_max_width;

	QPen m_log_pen;
	QPen m_warning_pen;
	QPen m_error_pen;

	QSize m_content_size;
	QPoint m_view_hint;
	QFont m_font;
	QFontMetrics m_font_metrics;
	QVector<QPair<MessageType, QString>> m_messages;

public:
	ConsoleView(QWidget *parent);
	virtual ~ConsoleView();

	void setMaxWidth(int);
	void setFont(const QFont&);
	void setLogColor(const QColor&);
	void setWarningColor(const QColor&);
	void setErrorColor(const QColor&);

	void addText(MessageType, QString);
	void setViewHintX(int);
	void setViewHintY(int);

	void clear();

	QSize contentSize() const;

protected:
	virtual void paintEvent(QPaintEvent*) override;

private:
	void push(MessageType type, int h, const QString& msg);
};
