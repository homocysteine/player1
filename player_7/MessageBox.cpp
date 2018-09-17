#include "MessageBox.h"
#include<cstdlib>
#include"Map1.h"
#include"LevelChoose.h"
#include"Top.h"
extern Top * top;
MessageBox::MessageBox(QMessageBox * parent) :QMessageBox(parent)
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
	{//��һ��ͨ��ʱ������һ���µ�ѡ�ؽ���
		QGraphicsScene* ch = new QGraphicsScene();
		LevelChoose * c = new LevelChoose(ch,top->userfile->getLevel());
		c->show();
		//���ݵ�ǰ�ĸ���ʾָ�벻Ϊ����ɾ��ԭ���ľɵ�ͼ
		if (top->view1 != nullptr)
		{
			delete top->view1;
			top->view1 = nullptr;
		}//������ɾ��һ��ָ��֮�󣬱�����ֻ���ͷŸ�ָ����ָ����ڴ�ռ䣬������ɾ�����ָ�뱾��

		if (top->view2 != nullptr)
		{
			delete top->view2;
			top->view2 = nullptr;
		}

		if (top->view3 != nullptr)
		{
			delete top->view3;
			top->view3 = nullptr;
		}

		if (top->view4 != nullptr)
		{
			delete top->view4;
			top->view4 = nullptr;
		}

		Boxes::count = 0;
		break;
	}
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
