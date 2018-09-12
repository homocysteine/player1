#include "Game.h"



Game::Game()
{
	scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 1000, 1000);
	scene->setBackgroundBrush(QBrush(QImage(":/Player_1/Resources/Floor.png")));

	player = new Player();
	scene->addItem(player);
						   
	box = new Boxes();
	scene->addItem(box);

	Boxes * box1 = new Boxes();
	scene->addItem(box1);

	block = new Block();
	scene->addItem(block);

	spot = new Spot();
	scene->addItem(spot);

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	step = new Step();
	scene->addItem(step);

	QGraphicsView * view = new QGraphicsView(scene);
	view->setFixedSize(1000, 1000);
	view->show();

	player->setPos(800, 800);
	box->setPos(500, 500);
	block->setPos(200, 200);
	spot->setPos(600, 600);
	box1->setPos(700, 700);
}


Game::~Game()
{
}
