#pragma once
#include<QGraphicsScene>
#include<QObject>
#include<QGraphicsRectItem>
#include<QKeyEvent>
#include<QBrush>
#include<QList>

#include"block.h"
#include"box.h"
class Player:public QObject,public QGraphicsRectItem
{
private:
	int step;
	int size;
public:
	Player();
	void keyPressEvent(QKeyEvent* event);
	~Player();
};

