#pragma once

#include <QDialog>
#include <QMouseEvent>
#include "ui_Xuanwuku.h"

class Xuanwuku : public QDialog
{
	Q_OBJECT

public:
	Xuanwuku(QWidget *parent = Q_NULLPTR);
	~Xuanwuku();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private slots:
	int OpenXW();

private:
	Ui::Xuanwuku ui;
};
