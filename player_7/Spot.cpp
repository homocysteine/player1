#include "Spot.h"



Spot::Spot()
{
	setRect(0, 0, spotSize, spotSize);
	QBrush brush_spot(QImage(":/Player_1/Resources/Spot.png"));
	setBrush(brush_spot);
}

Spot::~Spot()
{
}
