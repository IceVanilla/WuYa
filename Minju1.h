#pragma once

#include <QDialog>
#include "ui_Minju1.h"

class Minju1 : public QDialog
{
	Q_OBJECT

public:
	Minju1(QWidget *parent = Q_NULLPTR);
	~Minju1();

private:
	Ui::Minju1 ui;
};
