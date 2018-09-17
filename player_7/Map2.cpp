#include "Map2.h"
#define unit 100
//extern int boxesNumber;

Map2::Map2()
{

}

Map2::Map2(QGraphicsScene *scene)
{
	//userfile = new Userfile(QString("Cys"), QString("1111"));
	//initialize the scene
	scene_ = scene;
	scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
	scene->setBackgroundBrush(QBrush(QImage(":/Player_1/Resources/Floor.png")));
	//create the map

	//block*55,player*1,,box*3
	for (int i = 0; i < 57; i++)
	{
		block[i] = new Block();
	}
	player = new Player();
	for (int i = 0; i < 3; i++)
	{
		box[i] = new Boxes();
		spot[i] = new Spot();
	}

	int boxesNumber = 3;

	//row0
	for (int i = 0; i < 9; i++)
	{
		block[i]->setPos(unit*i, 0);
	}

	//row1
	int row1 = unit;
	for (int i = 9; i < 15; i++)
	{
		block[i]->setPos(unit*(i - 9), row1);
	}
	block[15]->setPos(unit * 8, row1);
	block[55]->setPos(unit * 6, row1);
	block[56]->setPos(unit * 7, row1);

	//row2
	int row2 = unit * 2;
	for (int i = 16; i < 19; i++)
	{
		block[i]->setPos(unit*(i - 16), row2);
	}
	for (int i = 19; i < 23; i++)
	{
		block[i]->setPos(unit*(i - 14), row2);
	}
	player->setPos(unit * 3, row2);

	//row3
	int row3 = unit * 3;
	for (int i = 23; i < 26; i++)
	{
		block[i]->setPos(unit*(i - 23), row3);
	}
	box[0]->setPos(unit * 4, row3);
	block[26]->setPos(unit * 7, row3);
	block[27]->setPos(unit * 8, row3);

	//row4
	int row4 = unit * 4;
	for (int i = 28; i < 32; i++)
	{
		block[i]->setPos(unit*(i - 28), row4);
	}
	block[32]->setPos(unit * 5, row4);
	block[33]->setPos(unit * 7, row4);
	block[34]->setPos(unit * 8, row4);

	//row5
	int row5 = unit * 5;
	block[35]->setPos(0, row5);
	block[36]->setPos(unit, row5);
	block[37]->setPos(unit * 5, row5);
	block[38]->setPos(unit * 8, row5);
	spot[0]->setPos(unit * 2, row5);

	//row6
	int row6 = unit * 6;
	block[39]->setPos(0, row6);
	block[40]->setPos(unit, row6);
	block[41]->setPos(unit * 6, row6);
	block[42]->setPos(unit * 8, row6);
	spot[1]->setPos(unit * 2, row6);
	box[1]->setPos(unit * 3, row6);

	//row7
	int row7 = unit * 7;
	block[43]->setPos(0, row7);
	block[44]->setPos(unit, row7);
	block[45]->setPos(unit * 8, row7);
	spot[2]->setPos(unit * 2, row7);
	box[2]->setPos(unit * 6, row7);

	//row8
	int row8 = unit * 8;
	for (int i = 46; i < 55; i++)
	{
		block[i]->setPos(unit*(i - 46), row8);
	}

	//add items to the scene
	scene->addItem(player);
	for (int i = 0; i < 57; i++)
	{
		scene->addItem(block[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		scene->addItem(box[i]);
		scene->addItem(spot[i]);

	}

	button[0] = new QPushButton("Up");
	button[1] = new QPushButton("Down");
	button[2] = new QPushButton("Left");
	button[3] = new QPushButton("Right");
	button[4] = new QPushButton("Restart");

	button[0]->setGeometry(800, 700, 100, 100);
	button[1]->setGeometry(800, 900, 100, 100);
	button[2]->setGeometry(700, 800, 100, 100);
	button[3]->setGeometry(900, 800, 100, 100);
	button[4]->setGeometry(800, 800, 100, 100);

	QGraphicsProxyWidget* proxy1 = scene_->addWidget(button[0]);
	QGraphicsProxyWidget* proxy2 = scene_->addWidget(button[1]);
	QGraphicsProxyWidget* proxy3 = scene_->addWidget(button[2]);
	QGraphicsProxyWidget* proxy4 = scene_->addWidget(button[3]);
	QGraphicsProxyWidget* proxy5 = scene_->addWidget(button[4]);

	QObject::connect(button[0], SIGNAL(clicked()), this, SLOT(Player_Up()));
	QObject::connect(button[1], SIGNAL(clicked()), this, SLOT(Player_Down()));
	QObject::connect(button[2], SIGNAL(clicked()), this, SLOT(Player_Left()));
	QObject::connect(button[3], SIGNAL(clicked()), this, SLOT(Player_Right()));
	QObject::connect(button[4], SIGNAL(clicked()), this, SLOT(Player_Restart()));

	step = new Step();
	scene_->addItem(step);//����Ҫ������󴴽�

	Boxes::boxNum = 1;

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
}


Map2::~Map2()
{
}

void Map2::Player_Up()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->up();
}
void Map2::Player_Down()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->down();
}

void Map2::Player_Right()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->right();
}

void Map2::Player_Left()
{
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
	player->left();
}

void Map2::Player_Restart()
{
	int boxesNumber = 3;
	//row2
	int row2 = unit * 2;
	player->setPos(unit * 3, row2);

	//row3
	int row3 = unit * 3;
	box[0]->setPos(unit * 4, row3);

	//row6
	int row6 = unit * 6;
	box[1]->setPos(unit * 3, row6);

	//row7
	int row7 = unit * 7;
	box[2]->setPos(unit * 6, row7);

	for (int i = 0; i < boxesNumber; i++) {
		QBrush brush_Box(QImage(":/Player_1/Resources/box.png"));
		box[i]->setBrush(brush_Box);
	}

	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	Boxes::count = 0;
	step->setStep(0);
}