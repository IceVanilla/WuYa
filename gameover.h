#pragma once

#include <QDialog>
#include "ui_gameover.h"

class gameover : public QDialog
{
	Q_OBJECT

public:
	gameover(QWidget *parent = Q_NULLPTR);
	~gameover();

private:
	Ui::gameover ui;
};
