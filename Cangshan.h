#pragma once

#include <QDialog>
#include "ui_Cangshan.h"
#include <QMouseEvent>

class Cangshan : public QDialog
{
	Q_OBJECT

public:
	Cangshan(QWidget *parent = Q_NULLPTR);
	~Cangshan();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private  slots:
	int OpenDadian();
	int OpenMishi();
	int OpenOut();

private:
	Ui::Cangshan ui;
};
