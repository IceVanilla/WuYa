#pragma once

#include <QDialog>
#include "ui_KeZhan.h"
#include <QMouseEvent>

class KeZhan : public QDialog
{
	Q_OBJECT

public:
	KeZhan(QWidget *parent = Q_NULLPTR);
	~KeZhan();

private:
	bool bxs = false;
	int tb = 0;
	int t = 0;
	void mousePressEvent(QMouseEvent *event);

private slots:
	int OpenBXS();
	int OpenRest();
	int OpenBag();
	int OpenState();

private:
	Ui::KeZhan ui;
};
