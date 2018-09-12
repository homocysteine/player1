#pragma once
#include "Player_1.h"
#include <QtWidgets/QApplication>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>
#include<QBrush>
#include<QImage>
#include<QBrush>

#include"Player.h"
#include"Boxes.h"
#include"Block.h"
#include"Spot.h"
#include"Step.h"
#include"MessageBox.h"
class Game:public QGraphicsView
{
public:
	Game();
	Step * step;
	QGraphicsScene * scene;
	Player * player;
	Boxes * box;//不知道为什么用Box做类名冲突了...
	Block * block;
	Spot * spot;
	MessageBox * messagebox;
	~Game();
};

