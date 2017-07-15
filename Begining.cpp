#include "Begining.h"

Begining::Begining(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Begining::~Begining()
{
}


void Begining::mousePressEvent(QMouseEvent *event)
{
	switch (t)
	{
	case 0:
	{
		ui.lblText->setText(QString::fromLocal8Bit("这场雨已经连续了半月有余"));
		break;
	}
	case 1:
	{
		ui.lblText->setText(QString::fromLocal8Bit("你孤身一人下山执行任务也有半年之久了..."));
		break;
	}
	default:
		this->close();
		break;
	}
	t++;
	return;
}
