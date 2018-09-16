#include "Boxes.h"
#include"Top.h"
extern Top * top;
int Boxes::count = 0;//count�Ǿ�̬����
int Boxes::boxNum = 0;
Boxes::Boxes()
{
	setRect(0, 0, boxSize, boxSize);//�������Ӵ�С��ͼƬ
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
	if (count == boxNum)//��boxNum��Ϊ���ӵ����ԣ���̬�ģ��ú��ڵ�ͼ��ʼ��ʱ��������
	{
		if(top->view1!=nullptr)
			top->map1->userfile->saveScore(1, top->map1->step->getStep());//����Ϸ���ݴ�����,����Ϸ��һ����Ҫ��������
		if (top->view2 != nullptr)
			top->map2->userfile->saveScore(2, top->map2->step->getStep());//ǰ�����level���ԣ����Դ�����
		if (top->view3 != nullptr)
			top->map3->userfile->saveScore(3, top->map3->step->getStep());
		if (top->view4 != nullptr)
			top->map4->userfile->saveScore(4, top->map4->step->getStep());
	}
}

bool Boxes::getFlag()
{
	return flag1;
}

Boxes::~Boxes()
{
}
