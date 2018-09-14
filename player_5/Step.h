#pragma once
#include<QGraphicsTextItem>
class Step:public QGraphicsTextItem
{
public:
	Step(QGraphicsTextItem * parent=0);
	void increase();
	void decrease();
	int getStep();
	~Step();
private:
	int step;
};

