#pragma once

#include <QDialog>
#include "ui_Yingshan.h"
#include <QMouseEvent>

class Yingshan : public QDialog
{
	Q_OBJECT

public:
	Yingshan(QWidget *parent = Q_NULLPTR);
	~Yingshan();

private slots:
	int OnRongshe();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private:
	Ui::Yingshan ui;
};
