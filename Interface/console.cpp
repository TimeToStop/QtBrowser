#include "console.h"
#include "ui_console.h"

#include <QWheelEvent>
#include <QResizeEvent>

Console::Console(QWidget *parent):
	QWidget(parent),
	m_wheel_scroll_speed(20),
	ui(new Ui::Console())
{
	ui->setupUi(this);

	ui->vertical->hide();
	connect(ui->vertical, &QAbstractSlider::sliderMoved, this, &Console::verticalSliderMoved);

	ui->vertical->setMinimum(0);
	ui->vertical->setMaximum(ui->console_view->height());
	ui->vertical->setSingleStep(1);
	ui->vertical->setPageStep(ui->console_view->height());

	ui->horizontal->hide();
	connect(ui->horizontal, &QAbstractSlider::sliderMoved, this, &Console::horizontalSliderMoved);

	ui->horizontal->setMinimum(0);
	ui->horizontal->setMaximum(ui->console_view->width());
	ui->horizontal->setSingleStep(1);
	ui->horizontal->setPageStep(ui->console_view->width());
}

Console::~Console()
{
	delete ui;
}

void Console::setMaxWidth(int w)
{
	ui->console_view->setMaxWidth(w);
}

void Console::setWheelScrollSpeed(int w)
{
	m_wheel_scroll_speed = w;
}

void Console::setFont(const QFont& font)
{
	ui->console_view->setFont(font);
	repaint();
}

void Console::setLogColor(const QColor& c)
{
	ui->console_view->setLogColor(c);
	repaint();
}

void Console::setWarningColor(const QColor&c)
{
	ui->console_view->setWarningColor(c);
	repaint();
}

void Console::setErrorColor(const QColor& c)
{
	ui->console_view->setErrorColor(c);
	repaint();
}

void Console::log(const QString& msg)
{
	ui->console_view->addText(MessageType::LOG, msg);
	viewChanged();
}

void Console::warning(const QString& msg)
{
	ui->console_view->addText(MessageType::WARNING, msg);
	viewChanged();
}

void Console::error(const QString& msg)
{
	ui->console_view->addText(MessageType::ERROR, msg);
	viewChanged();
}

void Console::clear()
{
	ui->console_view->clear();
	viewChanged();
}

int Console::consoleViewWidth()
{
	return ui->console_view->width();
}

void Console::wheelEvent(QWheelEvent* e)
{
	if (!ui->vertical->isHidden())
	{
		const int pos = ui->vertical->sliderPosition() + m_wheel_scroll_speed * (e->delta() < 0 ? 1 : -1);
		ui->vertical->setSliderPosition(pos);
		verticalSliderMoved(pos);
	}
}

void Console::resizeEvent(QResizeEvent*)
{
	viewChanged();
}

void Console::verticalSliderMoved(int v)
{
	ui->console_view->setViewHintY(v);
	repaint();
}

void Console::horizontalSliderMoved(int v)
{
	ui->console_view->setViewHintX(v);
	repaint();
}

void Console::viewChanged()
{
	if (ui->console_view->contentSize().height() > ui->console_view->height())
	{
		ui->vertical->show();
		ui->vertical->setPageStep(ui->console_view->height());
		ui->vertical->setMaximum(ui->console_view->contentSize().height() - ui->vertical->pageStep());
		ui->vertical->setSliderPosition(ui->vertical->maximum());
		verticalSliderMoved(ui->vertical->maximum());
	}
	else
	{
		ui->vertical->hide();
	}

	if (ui->console_view->contentSize().width() > ui->console_view->width())
	{
		ui->horizontal->show();
		ui->horizontal->setPageStep(ui->console_view->width());
		ui->horizontal->setMaximum(ui->console_view->contentSize().width() - ui->horizontal->pageStep());
		ui->horizontal->setSliderPosition(0);
		horizontalSliderMoved(0);
	}
	else
	{
		ui->horizontal->hide();
	}
}


