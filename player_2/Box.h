#pragma once
#include<QGraphicsRectItem>
#include<QObject>
class Box:public QGraphicsRectItem,public QObject
{
public:
	Box();
	~Box();
};

