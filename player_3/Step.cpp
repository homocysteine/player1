#include "Step.h"
#include<QFont>


Step::Step(QGraphicsTextItem * parent): QGraphicsTextItem(parent)
{
	step = 0;
	setPlainText(QString("Step: ") + QString::number(step));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times", 30));
}

void Step::increase()
{
	step++;
	setPlainText(QString("Step: ") + QString::number(step));
}

int Step::getStep()
{
	return step;
}

void Step::decrease()
{
	step--;
}

Step::~Step()
{
}
