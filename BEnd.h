#pragma once

#include <QDialog>
#include "ui_BEnd.h"

class BEnd : public QDialog
{
	Q_OBJECT

public:
	BEnd(QWidget *parent = Q_NULLPTR);
	~BEnd();

private:
	Ui::BEnd ui;
};
