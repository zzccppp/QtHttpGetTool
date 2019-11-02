#include "AuthorDialog.h"

AuthorDialog::AuthorDialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
}

AuthorDialog::~AuthorDialog()
{
}
