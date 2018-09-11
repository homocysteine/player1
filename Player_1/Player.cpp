#include "Player.h"
#include<QGraphicsScene>
#include"box.h"
#include<QList>
#include<QDebug>
#include"block.h"

Player::Player()
{
	step = 100;
}

Player::Player(QGraphicsItem* parent)//QGraphicsPixmapItem(parent)
{
	//setPixmap(QPixmap(":/Resources/test.png"));
}

void Player::keyPressEvent(QKeyEvent* event)
{
	{
		if (event->key() == Qt::Key_Left)
		{
			QList<QGraphicsItem* >colliding_items = collidingItems();
			for (int i = 0, n = colliding_items.size(); i < n; i++)
			{
				if (typeid(*(colliding_items[i])) == typeid(Box))
				{
					if (colliding_items[i]->pos().x() + 100 == (pos().x())//�˴������Ҳ���
						&& colliding_items[i]->pos().y() == (pos().y()))
						colliding_items[i]->setPos(colliding_items[i]->pos().x() - step, colliding_items[i]->pos().y());
				}
				else if (typeid(*(colliding_items[i])) == typeid(Block))
				{
					if (colliding_items[i]->pos().x() + 100 == (pos().x())//�˴��ϰ����Ҳ���
						&& colliding_items[i]->pos().y() == (pos().y()))
						setPos(x() + step, y());
				}
			}
			setPos(x() - step, y());
		}
		else if (event->key() == Qt::Key_Right)
		{
			QList<QGraphicsItem* >colliding_items = collidingItems();
			for (int i = 0, n = colliding_items.size(); i < n; i++)
			{
				if (typeid(*(colliding_items[i])) == typeid(Box))
				{
					if (colliding_items[i]->pos().x() == (pos().x() + 100)//�˴����������
						&& colliding_items[i]->pos().y() == (pos().y()))
						colliding_items[i]->setPos(colliding_items[i]->pos().x() + step, colliding_items[i]->pos().y());
				}
				else if (typeid(*(colliding_items[i])) == typeid(Block))
				{
					if (colliding_items[i]->pos().x() == (pos().x()+100)//�˴��ϰ��������
						&& colliding_items[i]->pos().y() == (pos().y()))
						setPos(x() - step, y());
				}
			}
			setPos(x() + step, y());
		}
		else if (event->key() == Qt::Key_Up)
		{
			QList<QGraphicsItem* >colliding_items = collidingItems();
			for (int i = 0, n = colliding_items.size(); i < n; i++)
			{
				if (typeid(*(colliding_items[i])) == typeid(Box))
				{
					if (colliding_items[i]->pos().x() == (pos().x())//�˴�����������
						&& colliding_items[i]->pos().y() + 100 == (pos().y()))
						colliding_items[i]->setPos(colliding_items[i]->pos().x(), colliding_items[i]->pos().y() - step);
				}
				else if (typeid(*(colliding_items[i])) == typeid(Block))
				{
					if (colliding_items[i]->pos().y() + 100 == (pos().y())//�˴��ϰ���������
						&& colliding_items[i]->pos().x() == (pos().x()))
						setPos(x(), y()+step);
				}
			}
			setPos(x(), y() - step);
		}
	else if (event->key() == Qt::Key_Down)
		{
		QList<QGraphicsItem* >colliding_items = collidingItems();
		for (int i = 0, n = colliding_items.size(); i < n; i++)
		{
			if (typeid(*(colliding_items[i])) == typeid(Box))
			{
				if (colliding_items[i]->pos().x() == (pos().x())//�˴�����������
					&& colliding_items[i]->pos().y() == (pos().y() + 100))
					colliding_items[i]->setPos(colliding_items[i]->pos().x(), colliding_items[i]->pos().y() + step);
			}
			else if (typeid(*(colliding_items[i])) == typeid(Block))
			{
					if (colliding_items[i]->pos().y() == (pos().y()+100)//�˴��ϰ���������
						&& colliding_items[i]->pos().x() == (pos().x()))
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
