#include "consoleview.h"

#include <QPainter>
#include <QFont>
#include <QApplication>

const int ConsoleView::m_h_margin = 5;
const int ConsoleView::m_bottom_margin = 5;

ConsoleView::ConsoleView(QWidget *parent): 
	QWidget(parent),
	m_max_width(-1),
	m_log_pen(Qt::black),
	m_warning_pen(Qt::yellow),
	m_error_pen(Qt::red),
	m_content_size(0, m_bottom_margin),
	m_view_hint(0, 0),
	m_font(QApplication::font()),
	m_font_metrics(m_font),
	m_messages()
{
}

ConsoleView::~ConsoleView()
{
}

void ConsoleView::setMaxWidth(int w)
{
	if (w > 0)
	{
		m_max_width = w;
	}
}

void ConsoleView::setFont(const QFont& font)
{
	m_font = font;
	m_font_metrics = QFontMetrics(font);
}

void ConsoleView::setLogColor(const QColor& c)
{
	m_log_pen = c;
}

void ConsoleView::setWarningColor(const QColor& c)
{
	m_warning_pen = c;
}

void ConsoleView::setErrorColor(const QColor& c)
{
	m_error_pen = c;
}

void ConsoleView::addText(MessageType type, QString msg)
{
	const int w = m_font_metrics.horizontalAdvance(msg);
	const int h = m_font_metrics.capHeight() + m_h_margin;

	if (m_content_size.width() < w)
	{
		if (m_max_width != -1 && m_max_width < w)
		{
			m_content_size.setWidth(m_max_width);
			int width = 0;

			for (int i = 0; i < msg.size(); i++)
			{
				width += m_font_metrics.horizontalAdvance(msg[i]);
				if (width > m_max_width)
				{
					QString left = msg.left(i - 1);
					QString right = msg.right(msg.size() - i + 1);
					push(type, h, left);
					addText(type, right);
					return;
				}
			}
		}
		else
		{
			m_content_size.setWidth(w);
		}
	}

	push(type, h, msg);
}

void ConsoleView::setViewHintX(int v)
{
	m_view_hint.setX(v);
	repaint();
}

void ConsoleView::setViewHintY(int v)
{
	m_view_hint.setY(v);
	repaint();
}

void ConsoleView::clear()
{
	m_messages.clear();
	m_view_hint = QPoint(0, 0);
	m_content_size = QSize(0, 0);
}

QSize ConsoleView::contentSize() const
{
	return m_content_size;
}

void ConsoleView::paintEvent(QPaintEvent*)
{
	int h = -m_view_hint.y();
	QPainter painter(this);
	painter.setFont(m_font);

	for (const QPair<MessageType, QString>& msg : m_messages)
	{
		h += m_font_metrics.capHeight() + m_h_margin;
	
		switch (msg.first)
		{
		case MessageType::LOG:
			painter.setPen(m_log_pen);
			break;
		case MessageType::WARNING:
			painter.setPen(m_warning_pen);
			break;
		case MessageType::ERROR:
			painter.setPen(m_error_pen);
			break;
		default:
			break;
		}
		painter.drawText(-m_view_hint.x(), h, msg.second);
	}
}

void ConsoleView::push(MessageType type, int h, const QString& msg)
{
	m_content_size += QSize(0, h);
	m_messages.push_back({ type, msg });
	repaint();
}
