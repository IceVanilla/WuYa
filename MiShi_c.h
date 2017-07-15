#pragma once

#include <QDialog>
#include "ui_MiShi_c.h"
#include <QMouseEvent>

class MiShi_c : public QDialog
{
	Q_OBJECT

public:
	MiShi_c(QWidget *parent = Q_NULLPTR);
	~MiShi_c();

private:
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private:
	Ui::MiShi_c ui;
};
