#pragma once

#include <QDialog>
#include "ui_File.h"

class File : public QDialog
{
	Q_OBJECT

public:
	File(QWidget *parent = Q_NULLPTR);
	~File();

	
private:
	Ui::File ui;
};
