#include "findbyidcmd.h"

#include "browserexecutor.h"
#include <QString>

FindByIdCmd::FindByIdCmd():
	Command()
{
}

FindByIdCmd::~FindByIdCmd()
{
}

QByteArray FindByIdCmd::execute(BrowserExecutor* executor, const QByteArray& data)
{
	QString result =  executor->browser()->findById(data);

	if (result.isEmpty())
	{
		result = "Cannot find any by given id";
	}

	return result.toUtf8();
}
