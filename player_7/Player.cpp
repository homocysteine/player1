#include "Player.h"
#include"Step.h"
#include"Top.h"
extern Top * top;
Player::Player()
{
	setRect(0, 0, playerSize, playerSize);
	QBrush brush_player(QImage(":/Player_1/Resources/Player_D.png"));
	setBrush(brush_player);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFocus();
}

void Player::arrival(Boxes * box)
{
	box->isArrival();
}

void Player::keyPressEvent(QKeyEvent * event)
{
	{
		if (event->key() == Qt::Key_Left)//�����°���ʱ
		{
			left();
		}//������������ͬ��
		else if (event->key() == Qt::Key_Right)
		{
			right();
		}
		else if (event->key() == Qt::Key_Up)
		{
			up();
		}
		else if (event->key() == Qt::Key_Down)
		{
			down();
		}
		/*else if (event->key() == Qt::Key_W)
		{
			up_pull();
		}
		else if (event->key() == Qt::Key_S)
		{
			down_pull();
		}
		else if (event->key() == Qt::Key_A)
		{
			left_pull();
		}
		else if (event->key() == Qt::Key_D)
		{
			right_pull();
		}*/
	}
}

void Player::left()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();//�������ҵ���ײ
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{

		if (typeid(*(colliding_item1[i])) == typeid(Boxes))//�����������ӷ�������ײ
		{
			//scene()->removeItem(this);//ͼƬ������Ƿ�������ײ��

			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//�ڼ������������������ӵ���ײ
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{//����һ������ײ����
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))//����������ϰ������нӴ�
				{/*������ϰ���
					�赲���ӵ��ƶ������ǲ��ܼ���ǰ����,�������� �ϰ���-����-�ˣ�ʩ��������������*/
					if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x() + playerSize
						&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
						&& colliding_item1[i]->pos().x() + playerSize == (pos().x())
						&& colliding_item1[i]->pos().y() == (pos().y()))
					{
						setPos(x() + stepLength, y());
						if(top->view1!=nullptr)
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
					if (colliding_item1[i]->pos().x() + playerSize == (pos().x())
						&& colliding_item1[i]->pos().y() == (pos().y()))//�˴������Ҳ���
					{
						colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - stepLength, colliding_item1[i]->pos().y());
						arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
					}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().x() + playerSize == (pos().x())//�˴��ϰ����Ҳ���
				&& colliding_item1[i]->pos().y() == (pos().y()))
			{
				setPos(x() + stepLength, y());
				if(top->view1!=nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_L(QImage(":/Player_1/Resources/Player_L.png"));//��ÿ���¼���ͬʱ��������ͼƬ��ͬ����setBrush����
	setBrush(brush_L);
	setPos(x() - stepLength, y());
	if(top->view1!=nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if(Boxes::count==Boxes::boxNum)
		top->messagebox = new MessageBox();
}

void Player::right()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{
		if (typeid(*(colliding_item1[i])) == typeid(Boxes))
		{
			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))
				{
					if (colliding_item1[i]->pos().x() + playerSize == colliding_item2[j]->pos().x()
						&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
						&& colliding_item1[i]->pos().x() == (pos().x() + playerSize)
						&& colliding_item1[i]->pos().y() == (pos().y()))
					{
						setPos(x() - stepLength, y());
						if(top->view1!=nullptr)
							top->map1->step->decrease();
						if(top->view2!=nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
					if (colliding_item1[i]->pos().x() == (pos().x() + playerSize)//�˴����������
						&& colliding_item1[i]->pos().y() == (pos().y()))
					{
						colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + stepLength, colliding_item1[i]->pos().y());
						arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
					}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().x() == (pos().x() + playerSize)//�˴��ϰ��������
				&& colliding_item1[i]->pos().y() == (pos().y()))
			{
				setPos(x() - stepLength, y());
				if(top->view1!=nullptr)
					top->map1->step->decrease();
				if(top->view2!=nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_R(QImage(":/Player_1/Resources/Player_R.png"));
	setBrush(brush_R);
	setPos(x() + stepLength, y());
	if(top->view1!=nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)
		top->messagebox = new MessageBox();
}

void Player::up()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{
		if (typeid(*(colliding_item1[i])) == typeid(Boxes))
		{
			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))
				{
					if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
						&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y() + playerSize
						&& colliding_item1[i]->pos().x() == (pos().x())
						&& colliding_item1[i]->pos().y() + playerSize == (pos().y()))
					{
						setPos(x(), y() + stepLength);
						if(top->view1!=nullptr)
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
					if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
						&& colliding_item1[i]->pos().y() + playerSize == (pos().y()))
					{
						colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() - stepLength);
						arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
					}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().y() + playerSize == (pos().y())//�˴��ϰ���������
				&& colliding_item1[i]->pos().x() == (pos().x()))
			{
				setPos(x(), y() + stepLength);
				if(top->view1!=nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_U(QImage(":/Player_1/Resources/Player_U.png"));
	setBrush(brush_U);
	setPos(x(), y() - stepLength);
	if(top->view1!=nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)
		top->messagebox = new MessageBox();
}

void Player::down()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{
		if (typeid(*(colliding_item1[i])) == typeid(Boxes))
		{
			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))
				{
					if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
						&& colliding_item1[i]->pos().y() + playerSize == colliding_item2[j]->pos().y()
						&& colliding_item1[i]->pos().x() == (pos().x())
						&& colliding_item1[i]->pos().y() == (pos().y() + playerSize))
					{
						setPos(x(), y() - stepLength);
						if(top->view1!=nullptr)
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
					if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
						&& colliding_item1[i]->pos().y() == (pos().y() + playerSize))
					{
						colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() + stepLength);
						arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
					}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().y() == (pos().y() + playerSize)//�˴��ϰ���������
				&& colliding_item1[i]->pos().x() == (pos().x()))
			{
				setPos(x(), y() - stepLength);
				if(top->view1!=nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_D(QImage(":/Player_1/Resources/Player_D.png"));
	setBrush(brush_D);
	setPos(x(), y() + stepLength);
	if(top->view1!=nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)
		top->messagebox = new MessageBox();
}
Player::~Player()
{
}

/*void Player::right_pull()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();//�������ҵ���ײ
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{

		if (typeid(*(colliding_item1[i])) == typeid(Boxes))//�����������ӷ�������ײ
		{
			//scene()->removeItem(this);//ͼƬ������Ƿ�������ײ��

			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//�ڼ������������������ӵ���ײ
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{//����һ������ײ����
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))//����������ϰ������нӴ�
				{/*������ϰ���
					�赲���ӵ��ƶ������ǲ��ܼ���ǰ����,�������� �ϰ���-����-�ˣ�ʩ��������������*/
					/*if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x() + playerSize
						&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
						&& colliding_item1[i]->pos().x() + playerSize == (pos().x())
						&& colliding_item1[i]->pos().y() == (pos().y()))
					{
						setPos(x() + stepLength, y());
						if (top->view1 != nullptr)
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
			if (colliding_item1[i]->pos().x() + playerSize == (pos().x())
				&& colliding_item1[i]->pos().y() == (pos().y()))//�˴������Ҳ���
			{
				colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + stepLength, colliding_item1[i]->pos().y());
				arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().x() + playerSize == (pos().x())//�˴��ϰ����Ҳ���
				&& colliding_item1[i]->pos().y() == (pos().y()))
			{
				setPos(x() + stepLength, y());
				if (top->view1 != nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_L(QImage(":/Player_1/Resources/Player_L.png"));//��ÿ���¼���ͬʱ��������ͼƬ��ͬ����setBrush����
	setBrush(brush_L);
	setPos(x() + stepLength, y());
	if (top->view1 != nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)
		top->messagebox = new MessageBox();
}


void Player::left_pull()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{
		if (typeid(*(colliding_item1[i])) == typeid(Boxes))
		{
			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))
				{
					if (colliding_item1[i]->pos().x() + playerSize == colliding_item2[j]->pos().x()
						&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
						&& colliding_item1[i]->pos().x() == (pos().x() + playerSize)
						&& colliding_item1[i]->pos().y() == (pos().y()))
					{
						setPos(x() - stepLength, y());
						if (top->view1 != nullptr)
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
			if (colliding_item1[i]->pos().x() == (pos().x() + playerSize)//�˴����������
				&& colliding_item1[i]->pos().y() == (pos().y()))
			{
				colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - stepLength, colliding_item1[i]->pos().y());
				arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().x() == (pos().x() + playerSize)//�˴��ϰ��������
				&& colliding_item1[i]->pos().y() == (pos().y()))
			{
				setPos(x() - stepLength, y());
				if (top->view1 != nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_R(QImage(":/Player_1/Resources/Player_R.png"));
	setBrush(brush_R);
	setPos(x() - stepLength, y());
	if (top->view1 != nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)
		top->messagebox = new MessageBox();
}


void Player::down_pull()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{
		if (typeid(*(colliding_item1[i])) == typeid(Boxes))
		{
			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))
				{
					if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
						&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y() + playerSize
						&& colliding_item1[i]->pos().x() == (pos().x())
						&& colliding_item1[i]->pos().y() + playerSize == (pos().y()))
					{
						setPos(x(), y() + stepLength);
						if (top->view1 != nullptr)
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
			if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
				&& colliding_item1[i]->pos().y() + playerSize == (pos().y()))
			{
				colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() + stepLength);
				arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().y() + playerSize == (pos().y())//�˴��ϰ���������
				&& colliding_item1[i]->pos().x() == (pos().x()))
			{
				setPos(x(), y() + stepLength);
				if (top->view1 != nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_U(QImage(":/Player_1/Resources/Player_U.png"));
	setBrush(brush_U);
	setPos(x(), y() + stepLength);
	if (top->view1 != nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)
		top->messagebox = new MessageBox();
}


void Player::up_pull()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{
		if (typeid(*(colliding_item1[i])) == typeid(Boxes))
		{
			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))
				{
					if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
						&& colliding_item1[i]->pos().y() + playerSize == colliding_item2[j]->pos().y()
						&& colliding_item1[i]->pos().x() == (pos().x())
						&& colliding_item1[i]->pos().y() == (pos().y() + playerSize))
					{
						setPos(x(), y() - stepLength);
						if (top->view1 != nullptr)
							top->map1->step->decrease();
						if (top->view2 != nullptr)
							top->map2->step->decrease();
						if (top->view3 != nullptr)
							top->map3->step->decrease();
						if (top->view4 != nullptr)
							top->map4->step->decrease();
					}
				}
			}
			if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
				&& colliding_item1[i]->pos().y() == (pos().y() + playerSize))
			{
				colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() - stepLength);
				arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().y() == (pos().y() + playerSize)//�˴��ϰ���������
				&& colliding_item1[i]->pos().x() == (pos().x()))
			{
				setPos(x(), y() - stepLength);
				if (top->view1 != nullptr)
					top->map1->step->decrease();
				if (top->view2 != nullptr)
					top->map2->step->decrease();
				if (top->view3 != nullptr)
					top->map3->step->decrease();
				if (top->view4 != nullptr)
					top->map4->step->decrease();
			}
		}
	}
	QBrush brush_D(QImage(":/Player_1/Resources/Player_D.png"));
	setBrush(brush_D);
	setPos(x(), y() - stepLength);
	if (top->view1 != nullptr)
		top->map1->step->increase();
	if (top->view2 != nullptr)
		top->map2->step->increase();
	if (top->view3 != nullptr)
		top->map3->step->increase();
	if (top->view4 != nullptr)
		top->map4->step->increase();
	if (Boxes::count == Boxes::boxNum)
		top->messagebox = new MessageBox();
}
*/