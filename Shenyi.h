#pragma once

#include <QDialog>
#include "ui_Shenyi.h"

class Shenyi : public QDialog
{
	Q_OBJECT

public:
	Shenyi(QWidget *parent = Q_NULLPTR);
	~Shenyi();

private slots:
	int BuyGBW();
	int BuyPYD();

private:
	Ui::Shenyi ui;
};
