#pragma once

#include <QDialog>
#include "ui_Tip.h"

class Tip : public QDialog
{
	Q_OBJECT

public:
	Tip(QWidget *parent = Q_NULLPTR);
	Tip(QString str);
	~Tip();

private slots:
	int OnbtnAC();
	int OnbtnRE();

private:
	Ui::Tip ui;
};
