#include "Player.h"
#include"Step.h"
#include"Game.h"
extern Game * game;
Player::Player()
{
	setRect(0, 0, playerSize, playerSize);
	QBrush brush_player(QImage(":/Player_1/Resources/Player_D.png"));
	setBrush(brush_player);
}

void Player::arrival(Boxes * box)
{
	box->isArrival();
}

void Player::keyPressEvent(QKeyEvent * event)
{
	{
		if (event->key() == Qt::Key_Left)//当按下按键时
		{
			left();
		}//其它几个按键同理
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
	}
}

void Player::left()
{
	QList<QGraphicsItem* >colliding_item1 = collidingItems();//检测与玩家的碰撞
	for (int i = 0, n = colliding_item1.size(); i < n; i++)
	{

		if (typeid(*(colliding_item1[i])) == typeid(Boxes))//如果玩家与箱子发生了碰撞
		{
			//scene()->removeItem(this);//图片情况下是发生了碰撞的

			QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//在检测在这种情况下与箱子的碰撞
			for (int j = 0, m = colliding_item2.size(); j < m; j++)
			{//还差一个箱子撞箱子
				if (typeid(*(colliding_item2[j])) == typeid(Block)
					|| typeid(*(colliding_item2[j])) == typeid(Boxes))//如果箱子与障碍物又有接触
				{/*如果有障碍物
					阻挡箱子的推动则人是不能继续前进的,下述就是 障碍物-箱子-人，施力方向向左的情况*/
					if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x() + playerSize
						&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
						&& colliding_item1[i]->pos().x() + playerSize == (pos().x())
						&& colliding_item1[i]->pos().y() == (pos().y()))
					{
						setPos(x() + stepLength, y());
						game->step->decrease();
					}
				}
				else
				{
					if (colliding_item1[i]->pos().x() + playerSize == (pos().x())
						&& colliding_item1[i]->pos().y() == (pos().y()))//人从箱子右侧推
					{
						colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - stepLength, colliding_item1[i]->pos().y());
						arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
					}
				}
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().x() + playerSize == (pos().x())//人从障碍物右侧推
				&& colliding_item1[i]->pos().y() == (pos().y()))
			{
				setPos(x() + stepLength, y());
				game->step->decrease();
			}
		}
	}
	QBrush brush_L(QImage(":/Player_1/Resources/Player_L.png"));//在每按下键的同时更换朝向图片，同样用setBrush函数
	setBrush(brush_L);
	setPos(x() - stepLength, y());
	game->step->increase();
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
						game->step->decrease();
					}
				}
				else
					if (colliding_item1[i]->pos().x() == (pos().x() + playerSize)//人从箱子左侧推
						&& colliding_item1[i]->pos().y() == (pos().y()))
					{
						colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + stepLength, colliding_item1[i]->pos().y());
						arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
					}
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().x() == (pos().x() + playerSize)//人从障碍物左侧推
				&& colliding_item1[i]->pos().y() == (pos().y()))
			{
				setPos(x() - stepLength, y());
				game->step->decrease();
			}
		}
	}
	QBrush brush_R(QImage(":/Player_1/Resources/Player_R.png"));
	setBrush(brush_R);
	setPos(x() + stepLength, y());
	game->step->increase();
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
						game->step->decrease();
					}
				}
				else
				{
					if (colliding_item1[i]->pos().x() == (pos().x())//人从箱子下面推
						&& colliding_item1[i]->pos().y() + playerSize == (pos().y()))
					{
						colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() - stepLength);
						arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
					}
				}
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().y() + playerSize == (pos().y())//人从障碍物下面推
				&& colliding_item1[i]->pos().x() == (pos().x()))
			{
				setPos(x(), y() + stepLength);
				game->step->decrease();
			}
		}
	}
	QBrush brush_U(QImage(":/Player_1/Resources/Player_U.png"));
	setBrush(brush_U);
	setPos(x(), y() - stepLength);
	game->step->increase();
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
						game->step->decrease();
					}
				}
				else
				{
					if (colliding_item1[i]->pos().x() == (pos().x())//人从箱子上面推
						&& colliding_item1[i]->pos().y() == (pos().y() + playerSize))
					{
						colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() + stepLength);
						arrival(dynamic_cast<Boxes*>(colliding_item1[i]));
					}
				}
			}
		}
		else if (typeid(*(colliding_item1[i])) == typeid(Block))
		{
			if (colliding_item1[i]->pos().y() == (pos().y() + playerSize)//人从障碍物上面推
				&& colliding_item1[i]->pos().x() == (pos().x()))
			{
				setPos(x(), y() - stepLength);
				game->step->decrease();
			}
		}
	}
	QBrush brush_D(QImage(":/Player_1/Resources/Player_D.png"));
	setBrush(brush_D);
	setPos(x(), y() + stepLength);
	game->step->increase();
}
Player::~Player()
{
}
