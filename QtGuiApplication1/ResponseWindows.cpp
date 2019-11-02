#include "ResponseWindows.h"
#include "Client.h"

ResponseWindows::ResponseWindows(Client & c, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	for (auto header : c.headers)
	{
		//this->ui.showHeaders->appendPlainText();
		QString k(header.first);
		QString v(header.second);
		if (k.contains("Cookie"))
		{
			ui.showCookies->appendPlainText(k + ": " + v);
		}else
		{
			ui.showHeaders->appendPlainText(k + ": " + v);
		}
	}
	ui.Text->appendPlainText(c.text);
}

ResponseWindows::~ResponseWindows()
{
}