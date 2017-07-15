#pragma once

#include <QDialog>
#include <QMouseEvent>
#include "ui_Baihuxue.h"

class Baihuxue : public QDialog
{
	Q_OBJECT

public:
	Baihuxue(QWidget *parent = Q_NULLPTR);
	~Baihuxue();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private slots:
	int OpenBH();

private:
	Ui::Baihuxue ui;
};
