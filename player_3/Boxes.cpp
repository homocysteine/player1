#include "Boxes.h"
#include"Game.h"
extern Game * game;
Boxes::Boxes()
{
	setRect(0, 0, 100, 100);
	QBrush brush_box(QImage(":/Player_1/Resources/box.png"));
	setBrush(brush_box);
}

void Boxes::isArrival()
{
	flag = 0;
	QList<QGraphicsItem *> colliding_items = collidingItems(Qt::ContainsItemBoundingRect);            //���Ƿ��غ��ж��Ƿ񵽴�

	for (int i = 0, n = colliding_items.size(); i < n; ++i) 
	{
		if (typeid(*(colliding_items[i])) == typeid(Spot)) 
		{
			//�����Ի���ѯ���Ƿ������һ��
			flag = 1;
			game->messagebox = new MessageBox();
		}
	}

}

bool Boxes::getFlag()
{
	return flag;
}

Boxes::~Boxes()
{
}
