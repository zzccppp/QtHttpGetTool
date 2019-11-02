#pragma once

#include <QWidget>
#include "ui_AuthorDialog.h"

class AuthorDialog : public QWidget
{
	Q_OBJECT

public:
	AuthorDialog(QWidget *parent = Q_NULLPTR);
	~AuthorDialog();

private:
	Ui::AuthorDialog ui;
};
