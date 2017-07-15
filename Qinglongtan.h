#pragma once

#include <QDialog>
#include <QMouseEvent>
#include "ui_Qinglongtan.h"

class Qinglongtan : public QDialog
{
	Q_OBJECT

public:
	Qinglongtan(QWidget *parent = Q_NULLPTR);
	~Qinglongtan();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private slots:
	int OpenQL();

private:
	Ui::Qinglongtan ui;
};
