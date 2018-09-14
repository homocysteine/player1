#include "MessageBox.h"
#include "Game.h"
#include<cstdlib>
extern Game * game;


MessageBox::MessageBox(QMessageBox * parent):QMessageBox(parent)
{
	setWindowTitle(QString("Message"));
	setText(QString("Congratulations!"));
	setStandardButtons(QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Cancel);
	setButtonText(QMessageBox::StandardButton::Ok, QString("continue"));
	setButtonText(QMessageBox::StandardButton::Cancel, QString("quit"));
	exec(); QMessageBox::StandardButton ret = standardButton(clickedButton());
	switch (ret)
	{
	case QMessageBox::Ok:
		game->view[1]->show();
		delete game->view[0];
		break;
	case QMessageBox::Cancel:
		exit(0);
		break;
	default:
		break;
	}

}

MessageBox::~MessageBox()
{
}
