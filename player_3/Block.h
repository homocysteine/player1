#pragma once
#include<QGraphicsRectItem>
#include<QObject>
#include<QBrush>
class Block :public QGraphicsRectItem, public QObject
{
public:
	Block();
	~Block();
};
