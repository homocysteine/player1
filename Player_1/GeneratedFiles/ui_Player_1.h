/********************************************************************************
** Form generated from reading UI file 'Player_1.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_1_H
#define UI_PLAYER_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Player_1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Player_1Class)
    {
        if (Player_1Class->objectName().isEmpty())
            Player_1Class->setObjectName(QStringLiteral("Player_1Class"));
        Player_1Class->resize(600, 400);
        menuBar = new QMenuBar(Player_1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Player_1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Player_1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Player_1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Player_1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Player_1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Player_1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Player_1Class->setStatusBar(statusBar);

        retranslateUi(Player_1Class);

        QMetaObject::connectSlotsByName(Player_1Class);
    } // setupUi

    void retranslateUi(QMainWindow *Player_1Class)
    {
        Player_1Class->setWindowTitle(QApplication::translate("Player_1Class", "Player_1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Player_1Class: public Ui_Player_1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_1_H
