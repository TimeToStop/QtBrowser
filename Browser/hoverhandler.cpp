#include "hoverhandler.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

HoverHandler::HoverHandler(QObject *parent):
	QObject(parent)
{
}

HoverHandler::~HoverHandler()
{
}

void HoverHandler::onHovered(const QString& data)
{
	QString tag, inner, id;
	QStringList classes;
	QJsonDocument document = QJsonDocument::fromJson(data.toUtf8());

	if (document.isObject())
	{
		QMap<QString, QVariant> v = document.toVariant().toMap();
		QString tag, inner, id, path;
		QStringList classes;
		tag = v["tag"].toString();
		inner = v["inner"].toString();
		id = v["id"].toString();
		QList<QVariant> list = v["class"].toList();
		for (QVariant& e : list)
		{
			classes.push_back(e.toString());
		}

		path = v["path"].toString();

		emit(hovered(tag, id, classes, inner, path));
	}
}