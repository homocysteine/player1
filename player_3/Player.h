#pragma once
#include<QGraphicsScene>
#include<QObject>
#include<QGraphicsRectItem>
#include<QKeyEvent>
#include<QBrush>
#include<QList>
#include<Boxes.h>

#include"block.h"
#include"boxes.h"
class Player:public QObject,public QGraphicsRectItem
{
private:
	int stepLength;
	int size;
public:
	Player();
	void keyPressEvent(QKeyEvent* event);
	void arrival(Boxes * box);
	~Player();
};

