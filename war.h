#pragma once

#include <QDialog>
#include "ui_war.h"
#include <QMouseEvent>

class war : public QDialog
{
	Q_OBJECT

public:
	war(QWidget *parent = Q_NULLPTR);
	~war();
	
private:
	bool win = false;
	bool lose = false;
	void mousePressEvent(QMouseEvent *event);
	void winvalue();
	void losevalue();
	void bossjineng();
	void buffvalue();
	void disbuff();
	void state();

private slots:
	void onbtnPugong();
	void onbtnZhanyi();
	void onbtnMingxiang();
	void onbtnCangshan();
	void onbtnZhengyang();
	void onbtnQinglong();

private:
	Ui::war ui;
};
