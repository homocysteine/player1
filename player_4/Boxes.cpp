#include "Boxes.h"
#include"Game.h"
extern Game * game;
extern const int boxNum;
int Boxes::count = 0;//count�Ǿ�̬����
Boxes::Boxes()
{
	setRect(0, 0, 100, 100);
	QBrush brush_box(QImage(":/Player_1/Resources/box.png"));
	setBrush(brush_box);
}

void Boxes::isArrival()
{
	flag2 = flag1;//flag2���ڴ��֮ǰһ����flag,flag1������ʾ������һ����flag
	flag1 = 0;
	QList<QGraphicsItem *> colliding_items = collidingItems(Qt::ContainsItemBoundingRect);            //���Ƿ��غ��ж��Ƿ񵽴�

	for (int i = 0, n = colliding_items.size(); i < n; ++i) 
	{
		if (typeid(*(colliding_items[i])) == typeid(Spot)) 
		{
			//�����Ի���ѯ���Ƿ������һ��
			flag1 = 1;
		}
	}
	if (flag2 == 1 && flag1 == 0)//������1��Ϊ0ʱ��count--    tm��ִ�У�
		count--;
	else if (flag2 == 0 && flag1 == 1)//������0��Ϊ1ʱ��count++
		count++;
	//else if (flag2 == 0 && flag1 == 0)//����һ���Գ���flag������ 
		//count++;
	if (count == boxNum)
		game->messagebox = new MessageBox();
}

int Boxes::getCount()
{
	return count;
}

void Boxes::judgeArrival()
{
	
}

bool Boxes::getFlag()
{
	return flag1;
}

Boxes::~Boxes()
{
}
