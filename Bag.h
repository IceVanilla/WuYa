#pragma once

#include <QDialog>
#include "ui_Bag.h"

class Bag : public QDialog
{
	Q_OBJECT

public:
	Bag(QWidget *parent = Q_NULLPTR);
	~Bag();

private:
	bool play = false;

private slots:
	void btnZhengyangjian();
	void btnQinglongjian();
	void btnZhengyangguan();
	void btnZhengyangxue();
	void btnHuxinjing();
	void btnZhuqueguan();
	void btnXuanwujia();
	void btnBaihuxue();


private:
	Ui::Bag ui;
};
