#pragma once
#include<QGraphicsRectItem>
#include<QObject>
class Block :public QGraphicsRectItem, public QObject
{
public:
	Block();
	~Block();
};
