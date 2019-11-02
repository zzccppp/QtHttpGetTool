#pragma once

#include <QWidget>
#include "ui_ResponseWindows.h"
#include "Client.h"

class ResponseWindows : public QWidget
{
	Q_OBJECT

public:
	ResponseWindows(Client &c ,QWidget *parent = Q_NULLPTR);
	~ResponseWindows();

private:
	Ui::ResponseWindows ui;
};
