#include "Player_1.h"
#include <QtWidgets/QApplication>
#include"LevelChoose.h"
#include"QGraphicsView"
#include"Top.h"
Top * top;//top类是全局类，是凌驾于一切之上的一个类
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	top = new Top();
	return a.exec();
}