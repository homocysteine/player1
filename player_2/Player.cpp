#include "Player.h"

Player::Player()
{
	step = 100;
	size = 100;
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
					//scene()->removeItem(this);//ͼƬ������Ƿ�������ײ��
					
					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//�ڼ������������������ӵ���ײ
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))//����������ϰ������нӴ�
						{/*������ϰ���
							�赲���ӵ��ƶ������ǲ��ܼ���ǰ����,�������� �ϰ���-����-�ˣ�ʩ��������������*/
						if(colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()+size
							&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
							&& colliding_item1[i]->pos().x() + size == (pos().x())
							&& colliding_item1[i]->pos().y() == (pos().y()))
							setPos(x() + step, y());
						}
						else
						{
							if (colliding_item1[i]->pos().x() + size == (pos().x())
								&& colliding_item1[i]->pos().y() == (pos().y()))//�˴������Ҳ���
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - step, colliding_item1[i]->pos().y());
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() + size == (pos().x())//�˴��ϰ����Ҳ���
						&& colliding_item1[i]->pos().y() == (pos().y()))
						setPos(x() + step, y());
				}
			}
			QBrush brush4(QImage(":/Player_1/Resources/Player_L.png"));//��ÿ���¼���ͬʱ��������ͼƬ��ͬ����setBrush����
			setBrush(brush4);
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
							if (colliding_item1[i]->pos().x() + size == colliding_item2[j]->pos().x()
								&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
								&& colliding_item1[i]->pos().x() == (pos().x() + size)
								&& colliding_item1[i]->pos().y() == (pos().y()))
								setPos(x() - step, y());
						}
						else
							if (colliding_item1[i]->pos().x() == (pos().x() + size)//�˴����������
								&& colliding_item1[i]->pos().y() == (pos().y()))
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + step, colliding_item1[i]->pos().y());
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() == (pos().x()+size)//�˴��ϰ��������
						&& colliding_item1[i]->pos().y() == (pos().y()))
						setPos(x() - step, y());
				}
			}
			QBrush brush5(QImage(":/Player_1/Resources/Player_R.png"));
			setBrush(brush5);
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
								&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y() + size
								&& colliding_item1[i]->pos().x() == (pos().x())
								&& colliding_item1[i]->pos().y() + size == (pos().y()))
								setPos(x(), y() + step);
						}
						else
						{
							if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
								&& colliding_item1[i]->pos().y() + size == (pos().y()))
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() - step);
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().y() + size == (pos().y())//�˴��ϰ���������
						&& colliding_item1[i]->pos().x() == (pos().x()))
						setPos(x(), y()+step);
				}
			}
			QBrush brush6(QImage(":/Player_1/Resources/Player_U.png"));
			setBrush(brush6);
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
							&& colliding_item1[i]->pos().y() + size == colliding_item2[j]->pos().y()
							&& colliding_item1[i]->pos().x() == (pos().x())
							&& colliding_item1[i]->pos().y() == (pos().y() + size))
							setPos(x(), y() - step);
					}
					else
					{
						if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
							&& colliding_item1[i]->pos().y() == (pos().y() + size))
							colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() + step);
					}
				}
			}
			else if (typeid(*(colliding_item1[i])) == typeid(Block))
			{
					if (colliding_item1[i]->pos().y() == (pos().y()+size)//�˴��ϰ���������
						&& colliding_item1[i]->pos().x() == (pos().x()))
						setPos(x(), y()-step);
			}
		}
		QBrush brush7(QImage(":/Player_1/Resources/Player_D.png"));
		setBrush(brush7);
			setPos(x(), y() + step);
		}
	}
}


Player::~Player()
{
}
