#include "Client.h"
#include <QTextCodec>
#include <QtNetwork/QtNetwork>


Client::Client()
{
	manager = new QNetworkAccessManager();
	QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));
}


Client::~Client()
{
}

void Client::replyFinished(QNetworkReply * reply)
{
	QTextCodec *codec = QTextCodec::codecForName("utf-8");
	text.append(codec->toUnicode(reply->readAll()));
	headers = reply->rawHeaderPairs();
	reply->deleteLater();
	emit finishedA(this);
}