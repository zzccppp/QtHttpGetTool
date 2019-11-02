#pragma once
#include <QtNetwork/QtNetwork>

class Client : public QObject
{
	Q_OBJECT
public:
	Client();
	~Client();
	QString text;
	QNetworkAccessManager* manager;
	QList<QPair<QByteArray,QByteArray>> headers;

signals:
	void finishedA(Client *c);
	
	private
slots:
	void replyFinished(QNetworkReply *);

	
	
};