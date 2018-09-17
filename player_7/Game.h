#pragma once
#include "Player_1.h"
#include <QtWidgets/QApplication>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>
#include<QBrush>
#include<QImage>
#include<QBrush>
#include<qpushbutton.h>
#include<QKeyEvent>

#include"Player.h"
#include"Boxes.h"
#include"Block.h"
#include"Spot.h"
#include"Step.h"
#include"MessageBox.h"
#include"Userfile.h"
#include"parameter.h"
class Game:public QObject,public QGraphicsRectItem
{
	Q_OBJECT
public:
	Game();
	Step * step;
	QGraphicsScene * scene[sceneNum];
	Player * player = new Player();
	Boxes * box[boxNum];//��֪��Ϊʲô��Box��������ͻ��...
	Block * block;
	Spot * spot;
	MessageBox * messagebox;
	Userfile * userfile;
	QGraphicsView * view[sceneNum];
	QPushButton * button[buttonNum];
	//void keyPressEvent(QKeyEvent * event);
	~Game();
public slots:
	void Player_Up();
	void Player_Down();
	void Player_Right();
	void Player_Left();
};

