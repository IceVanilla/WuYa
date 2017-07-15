#pragma once

#include <QDialog>
#include "ui_Dadian_c.h"
#include <QMouseEvent>

class Dadian_c : public QDialog
{
	Q_OBJECT

public:
	Dadian_c(QWidget *parent = Q_NULLPTR);
	~Dadian_c();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private:
	Ui::Dadian_c ui;
};
