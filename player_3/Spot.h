#pragma once
#include<QObject>
#include<QGraphicsRectItem>
#include<QBrush>
class Spot :public QObject,public QGraphicsRectItem
{
public:
	Spot();
	~Spot();
};
