#pragma once

#include <QDialog>
#include "ui_Begining.h"
#include <QMouseEvent>

class Begining : public QDialog
{
	Q_OBJECT

public:
	Begining(QWidget *parent = Q_NULLPTR);
	~Begining();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private:
	Ui::Begining ui;
};
