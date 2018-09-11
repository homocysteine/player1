#include "Player.h"
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include"box.h"
#include<QList>
#include<QDebug>
#include"block.h"

Player::Player()
{
	step = 100;
}

Player::Player(QGraphicsItem* parent):QObject()//,QGraphicsPixmapItem(parent)
{
	//setPixmap(QPixmap(":/Resources/test.png"));
}

void Player::keyPressEvent(QKeyEvent* event)
{
	{
		if (event->key() == Qt::Key_Left)//�����°���ʱ
		{
			QList<QGraphicsItem* >colliding_item1 = collidingItems();//�������ҵ���ײ
			for (int i = 0, n = colliding_item1.size(); i < n; i++)
			{
				if (typeid(*(colliding_item1[i])) == typeid(Box))//�����������ӷ�������ײ
				{
					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//�ڼ������������������ӵ���ײ
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))//����������ϰ������нӴ�
						{/*������ϰ���
							�赲���ӵ��ƶ������ǲ��ܼ���ǰ����,�������� �ϰ���-����-�ˣ�ʩ��������������*/
						if(colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()+100
							&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
							&& colliding_item1[i]->pos().x() + 100 == (pos().x())
							&& colliding_item1[i]->pos().y() == (pos().y()))
							setPos(x() + step, y());
						}
						else
						{
							if (colliding_item1[i]->pos().x() + 100 == (pos().x())
								&& colliding_item1[i]->pos().y() == (pos().y()))//�˴������Ҳ���
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - step, colliding_item1[i]->pos().y());
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() + 100 == (pos().x())//�˴��ϰ����Ҳ���
						&& colliding_item1[i]->pos().y() == (pos().y()))
						setPos(x() + step, y());
				}
			}
			setPos(x() - step, y());
		}//������������ͬ��
		else if (event->key() == Qt::Key_Right)
		{
			QList<QGraphicsItem* >colliding_item1 = collidingItems();
			for (int i = 0, n = colliding_item1.size(); i < n; i++)
			{
				if (typeid(*(colliding_item1[i])) == typeid(Box))
				{
					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))
						{
							if (colliding_item1[i]->pos().x() + 100 == colliding_item2[j]->pos().x()
								&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
								&& colliding_item1[i]->pos().x() == (pos().x() + 100)
								&& colliding_item1[i]->pos().y() == (pos().y()))
								setPos(x() - step, y());
						}
						else
							if (colliding_item1[i]->pos().x() == (pos().x() + 100)//�˴����������
								&& colliding_item1[i]->pos().y() == (pos().y()))
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + step, colliding_item1[i]->pos().y());
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() == (pos().x()+100)//�˴��ϰ��������
						&& colliding_item1[i]->pos().y() == (pos().y()))
						setPos(x() - step, y());
				}
			}
			setPos(x() + step, y());
		}
		else if (event->key() == Qt::Key_Up)
		{
			QList<QGraphicsItem* >colliding_item1 = collidingItems();
			for (int i = 0, n = colliding_item1.size(); i < n; i++)
			{
				if (typeid(*(colliding_item1[i])) == typeid(Box))
				{
					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))
						{
							if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
								&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y() + 100
								&& colliding_item1[i]->pos().x() == (pos().x())
								&& colliding_item1[i]->pos().y() + 100 == (pos().y()))
								setPos(x(), y() + step);
						}
						else
						{
							if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
								&& colliding_item1[i]->pos().y() + 100 == (pos().y()))
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() - step);
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().y() + 100 == (pos().y())//�˴��ϰ���������
						&& colliding_item1[i]->pos().x() == (pos().x()))
						setPos(x(), y()+step);
				}
			}
			setPos(x(), y() - step);
		}
	else if (event->key() == Qt::Key_Down)
		{
		QList<QGraphicsItem* >colliding_item1 = collidingItems();
		for (int i = 0, n = colliding_item1.size(); i < n; i++)
		{
			if (typeid(*(colliding_item1[i])) == typeid(Box))
			{
				QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
				for (int j = 0, m = colliding_item2.size(); j < m; j++)
				{
					if (typeid(*(colliding_item2[j])) == typeid(Block))
					{
						if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
							&& colliding_item1[i]->pos().y() + 100 == colliding_item2[j]->pos().y()
							&& colliding_item1[i]->pos().x() == (pos().x())
							&& colliding_item1[i]->pos().y() == (pos().y() + 100))
							setPos(x(), y() - step);
					}
					else
					{
						if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
							&& colliding_item1[i]->pos().y() == (pos().y() + 100))
							colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() + step);
					}
				}
			}
			else if (typeid(*(colliding_item1[i])) == typeid(Block))
			{
					if (colliding_item1[i]->pos().y() == (pos().y()+100)//�˴��ϰ���������
						&& colliding_item1[i]->pos().x() == (pos().x()))
						setPos(x(), y()-step);
			}
		}
			setPos(x(), y() + step);
		}
	}
}

Player::~Player()
{
}
