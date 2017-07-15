#pragma once

#include <QDialog>
#include <QMouseEvent>
#include "ui_Zhuquechao.h"

class Zhuquechao : public QDialog
{
	Q_OBJECT

public:
	Zhuquechao(QWidget *parent = Q_NULLPTR);
	~Zhuquechao();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private slots:
	int OpenZQ();

private:
	Ui::Zhuquechao ui;
};
