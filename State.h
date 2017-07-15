#pragma once

#include <QDialog>
#include "ui_State.h"

class State : public QDialog
{
	Q_OBJECT

public:
	State(QWidget *parent = Q_NULLPTR);
	~State();

private:
	Ui::State ui;
};
