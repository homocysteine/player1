#pragma once
#include<QGraphicsRectItem>
#include<QObject>
#include<QBrush>
#include"spot.h"
#include"MessageBox.h"
class Boxes :public QGraphicsRectItem, public QObject
{
public:
	Boxes();
	bool getFlag();
	void isArrival();
	~Boxes();
private:
	bool flag = 0;
};

