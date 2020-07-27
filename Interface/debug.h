#pragma once

#include "mainwindow.h"

#define CONSOLE_LOG(msg) MainWindow::m_console->log(msg)

#define CONSOLE_WARNING (msg) MainWindow::m_console->warning(msg)

#define CONSOLE_ERROR(msg) MainWindow::m_console->error(msg)
