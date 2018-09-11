#pragma once
#include<QGraphicsScene>
#include<QObject>
#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
class Player:public QObject,public QGraphicsRectItem
{
private:
	int step;
public:
	Player();
	Player(QGraphicsItem* parent);
	void keyPressEvent(QKeyEvent* event);
	~Player();
};

