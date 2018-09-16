#include "Step.h"
#include<QFont>


Step::Step(QGraphicsTextItem * parent): QGraphicsTextItem(parent)
{
	step = 0;
	setPlainText(QString("Step: ") + QString::number(step));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times", 30));//������ʾ��ʽ
}

void Step::increase()
{
	step++;
	setPlainText(QString("Step: ") + QString::number(step));//���Ӳ�����ʵʱ��ʾ
}

int Step::getStep()
{
	return step;
}

void Step::decrease()
{
	step--;//����ʵ���߲���ʱ���Ӳ��Ĺ���
}

Step::~Step()
{
}
