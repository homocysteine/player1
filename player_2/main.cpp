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
#include"box.h"
#include"block.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QGraphicsScene* scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 1000, 1000);
	scene->setBackgroundBrush(QBrush(QImage(":/Player_1/Resources/Floor.png")));


	Player * player = new Player();
	player->setRect(0, 0, 100, 100);
	QBrush brush1(QImage(":/Player_1/Resources/Player_D.png"));
	player->setBrush(brush1);//采用QGrpahicsRectItem类继承自QAbstractGraphicsShapeItem类的setBrush函数在矩形框中插入图片
	scene->addItem(player);//之前采用的setPixmap函数插入图片的方法因为不可抗因素坐标计算无效，所以采用往矩形框里插图片
	                       //代价就是在图片周围会有黑框
	Box * box = new Box();
	box->setRect(0, 0, 100, 100);
	QBrush brush2(QImage(":/Player_1/Resources/box.png"));
	box->setBrush(brush2);
	scene->addItem(box);

	Block * block = new Block();
	block->setRect(0, 0, 100, 100);
	QBrush brush3(QImage(":/Player_1/Resources/Block.png"));
	block->setBrush(brush3);
	scene->addItem(block);

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	QGraphicsView * view = new QGraphicsView(scene);
	view->setFixedSize(1000,1000);
	view->show();

	box->setPos(500, 500);
	block->setPos(200, 200);
	return a.exec();
}
