#include "Boxes.h"
#include"Game.h"
extern Game * game;
extern const int boxNum;
int Boxes::count = 0;//count是静态变量
Boxes::Boxes()
{
	setRect(0, 0, 100, 100);
	QBrush brush_box(QImage(":/Player_1/Resources/box.png"));
	setBrush(brush_box);
}

void Boxes::isArrival()
{
	flag2 = flag1;//flag2用于存放之前一步的flag,flag1用来表示现在这一步的flag
	flag1 = 0;
	QList<QGraphicsItem *> colliding_items = collidingItems(Qt::ContainsItemBoundingRect);            //以是否重合判定是否到达

	for (int i = 0, n = colliding_items.size(); i < n; ++i) 
	{
		if (typeid(*(colliding_items[i])) == typeid(Spot)) 
		{
			//弹出对话框，询问是否进入下一关
			flag1 = 1;
		}
	}
	if (flag2 == 1 && flag1 == 0)//箱子由1变为0时，count--    tm不执行？
		count--;
	else if (flag2 == 0 && flag1 == 1)//箱子由0变为1时，count++
		count++;
	//else if (flag2 == 0 && flag1 == 0)//加这一步试出是flag的问题 
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
