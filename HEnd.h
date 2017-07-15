#pragma once

#include <QDialog>
#include "ui_HEnd.h"

class HEnd : public QDialog
{
	Q_OBJECT

public:
	HEnd(QWidget *parent = Q_NULLPTR);
	~HEnd();

private:
	Ui::HEnd ui;
};
