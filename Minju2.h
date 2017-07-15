#pragma once

#include <QDialog>
#include <QMouseEvent>
#include "ui_Minju2.h"

class Minju2 : public QDialog
{
	Q_OBJECT

public:
	Minju2(QWidget *parent = Q_NULLPTR);
	~Minju2();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private:
	Ui::Minju2 ui;
};
