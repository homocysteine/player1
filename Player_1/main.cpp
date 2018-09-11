#include "Player_1.h"
#include <QtWidgets/QApplication>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include"Player.h"
#include"box.h"
#include"block.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QGraphicsScene* scene = new QGraphicsScene();
	Player * player = new Player();
	player->setRect(0, 0, 100, 100);
	scene->addItem(player);

	Box * box = new Box();
	box->setRect(0, 0, 100, 100);
	scene->addItem(box);

	Block * block = new Block();
	block->setRect(0, 0, 100, 100);
	scene->addItem(block);

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	QGraphicsView * view = new QGraphicsView(scene);
	view->show();
	view->setFixedSize(800,600);
	view->setSceneRect(0, 0, 800, 600);

	box->setPos(view->width() / 2, view->height()/2);
	block->setPos(view->width() / 2, view->height() / 2+100);
	return a.exec();
}
