#include "MessageBox.h"



MessageBox::MessageBox(QMessageBox * parent):QMessageBox(parent)
{
	setWindowTitle(QString("Message"));
	setText(QString("Congratulations!"));
	setStandardButtons(QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Cancel);
	setButtonText(QMessageBox::StandardButton::Ok, QString("continue"));
	setButtonText(QMessageBox::StandardButton::Cancel, QString("quit"));
	exec();
}

void MessageBox::display()
{
	setWindowTitle(QString("Message"));
	setText(QString("Congratulations!"));
	setStandardButtons(QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Cancel);
	setButtonText(QMessageBox::StandardButton::Ok, QString("continue"));
	setButtonText(QMessageBox::StandardButton::Cancel, QString("quit"));
}

MessageBox::~MessageBox()
{
}
