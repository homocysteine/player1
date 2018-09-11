/*
-修改了“人把箱子推进墙里”的bug
-在控制玩家操作与交互的函数中加入注释
*/
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
		if (event->key() == Qt::Key_Left)//当按下按键时
		{
			QList<QGraphicsItem* >colliding_item1 = collidingItems();//检测与玩家的碰撞
			for (int i = 0, n = colliding_item1.size(); i < n; i++)
			{
				if (typeid(*(colliding_item1[i])) == typeid(Box))//如果玩家与箱子发生了碰撞
				{
					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//在检测在这种情况下与箱子的碰撞
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))//如果箱子与障碍物又有接触
						{/*如果有障碍物
							阻挡箱子的推动则人是不能继续前进的,下述就是 障碍物-箱子-人，施力方向向左的情况*/
						if(colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()+100
							&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
							&& colliding_item1[i]->pos().x() + 100 == (pos().x())
							&& colliding_item1[i]->pos().y() == (pos().y()))
							setPos(x() + step, y());
						}
						else
						{
							if (colliding_item1[i]->pos().x() + 100 == (pos().x())
								&& colliding_item1[i]->pos().y() == (pos().y()))//人从箱子右侧推
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - step, colliding_item1[i]->pos().y());
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() + 100 == (pos().x())//人从障碍物右侧推
						&& colliding_item1[i]->pos().y() == (pos().y()))
						setPos(x() + step, y());
				}
			}
			setPos(x() - step, y());
		}//其它几个按键同理
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
							if (colliding_item1[i]->pos().x() == (pos().x() + 100)//人从箱子左侧推
								&& colliding_item1[i]->pos().y() == (pos().y()))
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + step, colliding_item1[i]->pos().y());
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() == (pos().x()+100)//人从障碍物左侧推
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
							if (colliding_item1[i]->pos().x() == (pos().x())//人从箱子下面推
								&& colliding_item1[i]->pos().y() + 100 == (pos().y()))
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() - step);
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().y() + 100 == (pos().y())//人从障碍物下面推
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
						if (colliding_item1[i]->pos().x() == (pos().x())//人从箱子上面推
							&& colliding_item1[i]->pos().y() == (pos().y() + 100))
							colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() + step);
					}
				}
			}
			else if (typeid(*(colliding_item1[i])) == typeid(Block))
			{
					if (colliding_item1[i]->pos().y() == (pos().y()+100)//人从障碍物上面推
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
