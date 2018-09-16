#include "Top.h"



Top::Top()
{
	ch = new QGraphicsScene();
	c = new LevelChoose(ch);
	c->show();
}


Top::~Top()
{
}
