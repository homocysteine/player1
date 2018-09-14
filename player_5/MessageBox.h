#pragma once
#include<QMessageBox>
class MessageBox:public QMessageBox
{
public:
	MessageBox(QMessageBox * parent=0);
	~MessageBox();
};

