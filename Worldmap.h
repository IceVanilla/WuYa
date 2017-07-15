#pragma once

#include <QDialog>
#include "ui_Worldmap.h"

class Worldmap : public QDialog
{
	Q_OBJECT

public:
	Worldmap(QWidget *parent = Q_NULLPTR);
	~Worldmap();

private slots:
	int OpenXuanwu();
	int OpenBaihu();
	int OpenZhuque();
	int OpenQinglong();
	int OpenCangshan();
	int OpenYingshan();
	int OpenChangan();

private:
	Ui::Worldmap ui;
};
