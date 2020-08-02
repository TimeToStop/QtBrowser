#pragma once

#include <QObject>

class HoverHandler : public QObject
{
	Q_OBJECT

public:
	HoverHandler(QObject *parent);
	virtual ~HoverHandler();

signals:
	void hovered(const QString&, const QString&, const QStringList&, const QString&, const QString&);

public slots:
	void onHovered(const QString&);
};
