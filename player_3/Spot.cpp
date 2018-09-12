#include "Spot.h"



Spot::Spot()
{
	setRect(0, 0, 100, 100);
	QBrush brush_spot(QImage(":/Player_1/Resources/Spot.png"));
	setBrush(brush_spot);
}

Spot::~Spot()
{
}
