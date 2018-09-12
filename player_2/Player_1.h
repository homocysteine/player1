#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Player_1.h"

class Player_1 : public QMainWindow
{
	Q_OBJECT

public:
	Player_1(QWidget *parent = Q_NULLPTR);

private:
	Ui::Player_1Class ui;
};
