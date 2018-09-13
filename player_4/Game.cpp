#include "Game.h"



Game::Game()
{
	scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 1000, 1000);
	scene->setBackgroundBrush(QBrush(QImage(":/Player_1/Resources/Floor.png")));

	player = new Player();
	scene->addItem(player);

	box[0] = new Boxes();
	scene->addItem(box[0]);

	box[1] = new Boxes();
	scene->addItem(box[1]);

	block = new Block();
	scene->addItem(block);

	spot = new Spot();
	scene->addItem(spot);

	Spot * spot1 = new Spot();
	scene->addItem(spot1);

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	step = new Step();
	scene->addItem(step);

	QGraphicsView * view = new QGraphicsView(scene);
	view->setFixedSize(1000, 1000);
	view->show();

	player->setPos(800, 800);
	box[0]->setPos(500, 500);
	block->setPos(200, 200);
	spot->setPos(600, 600);
	box[1]->setPos(700, 700);
	spot1->setPos(500, 700);

}


Game::~Game()
{
}
