#pragma once

#include <QDialog>
#include "ui_Yiguan.h"
#include <QMouseEvent>

class Yiguan : public QDialog
{
	Q_OBJECT

public:
	Yiguan(QWidget *parent = Q_NULLPTR);
	~Yiguan();

private:
	bool ac = false, re = false;
	int t = 0;
	int t2 = 0;
	void mousePressEvent(QMouseEvent *event);

private slots:
	int OpenSY();

private:
	Ui::Yiguan ui;
};
