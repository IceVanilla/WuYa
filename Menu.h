#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Menu.h"

class Menu : public QMainWindow
{
	Q_OBJECT

public:
	Menu(QWidget *parent = Q_NULLPTR);

private slots:
	int openBegining();
	int openSetting();
	int openFile();
	int Quit();

private:
	Ui::MenuClass ui;
};
