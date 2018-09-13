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
	static int getCount();
	void judgeArrival();
	~Boxes();
private:
	int flag1 = 0;
	int flag2 = 0;
	static int count;
};
