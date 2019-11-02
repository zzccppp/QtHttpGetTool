//#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include "Client.h"

class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);
	Client * client = nullptr;

private:
	Ui::QtGuiApplication1Class ui;

public slots:
	void onClickStartBtn();
	void output(Client *);
	void authorAction();
};
