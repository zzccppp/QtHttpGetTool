#include "QtGuiApplication1.h"
#include "Client.h"

#include <QTextCodec>
#include <QtNetwork/QtNetwork>
#include "ResponseWindows.h"
#include "AuthorDialog.h"


QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.actionAuthor, SIGNAL(triggered()), this, SLOT(authorAction()));

}

void QtGuiApplication1::onClickStartBtn()
{
	QString url = ui.lineEdit->text();
	delete client;
	client = new Client;
	connect(client, SIGNAL(finishedA(Client *)), this, SLOT(output(Client *)));
	//Method case
	QNetworkRequest r = QNetworkRequest(QUrl(url));
	QString headers = ui.inputRequestHeaders->document()->toRawText();
	QStringList list = headers.split(QChar(ushort(8233)));
	
	for (QString head : list)
	{
		QStringList l = head.split(": ");
		if(l.length() == 2)
		{
			r.setRawHeader(l[0].toLatin1(), l[1].toLatin1());
		}
	}
	client->manager->get(r);
	
}

void QtGuiApplication1::output(Client * c)
{
	ResponseWindows *response_windows = new ResponseWindows(*c, nullptr);
	response_windows->show();
}

void QtGuiApplication1::authorAction()
{
	AuthorDialog *dialog = new AuthorDialog();
	dialog->show();
}
