#include "taskexecutor.h"

TaskExecutor::TaskExecutor(QObject *parent): 
	QObject(parent),
	m_is_finished(false)
{
}

TaskExecutor::~TaskExecutor()
{
}

void TaskExecutor::taskExecuted()
{
	m_is_finished = true;
}