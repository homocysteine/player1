#pragma once
#include<QGraphicsRectItem>
#include<QObject>
#include<QBrush>
#include<QPen>
#include"spot.h"
#include"MessageBox.h"
#include"parameter.h"
class Boxes :public QGraphicsRectItem, public QObject
{
public:
	Boxes();
	bool getFlag();
	void isArrival();//�����ж�����Ƿ����յ�
	static int getCount();
	~Boxes();
private:
	int flag1 = 0;
	int flag2 = 0;
	static int count;
};
