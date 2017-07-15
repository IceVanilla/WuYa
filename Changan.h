#pragma once

#include <QDialog>
#include "ui_Changan.h"
#include "Minju1.h"
#include "Minju2.h"
#include <QMouseEvent>

class Changan : public QDialog
{
	Q_OBJECT

public:
	Changan(QWidget *parent = Q_NULLPTR);
	~Changan();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private slots:
	int OpenKezhan();
	int OpenMinju1();
	int OpenMinju2();
	int OpenYiguan();
	int OpenOut();

private:
	Ui::Changan ui;
};
