#pragma once

#include <QObject>
#include <QtCore/qcoreapplication.h>

class TaskExecutor : public QObject
{
	Q_OBJECT;

	bool m_is_finished;

public:
	TaskExecutor(QObject* parent = nullptr);
	TaskExecutor(const TaskExecutor&) = delete;
	TaskExecutor(TaskExecutor&&) = delete;
	virtual ~TaskExecutor();

	template<typename Lambda>
	void execute(Lambda l);

	template<typename T, typename ... Args>
	void addListenFor(T* object, void (T::* signal)(Args ...))
	{
		connect(object, signal, this, &TaskExecutor::taskExecuted);
	}

	template<typename T, typename ... Args>
	void rmListenFor(T* object, void (T::* signal)(Args ...))
	{
		disconnect(object, signal, this, &TaskExecutor::taskExecuted);
	}


public slots:
	void taskExecuted();
};

template<typename Lambda>
inline void TaskExecutor::execute(Lambda l)
{
	l();
	for (; !m_is_finished;)
	{
		QCoreApplication::processEvents();
	}

	m_is_finished = false;
}