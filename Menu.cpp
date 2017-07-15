#include "Menu.h"
#include "File.h"
#include "Setting.h"
#include "Begining.h"
#include "Changan.h"
#include "Worldmap.h"
#include "gameover.h"
#include "HEnd.h"
#include "BEnd.h"

Menu::Menu(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.btnNew, SIGNAL(clicked()),
		this, SLOT(openBegining()));
	connect(ui.btnContinue, SIGNAL(clicked()),
		this, SLOT(openFile()));
	connect(ui.btnSetting, SIGNAL(clicked()),
		this, SLOT(openSetting()));
	connect(ui.btnQuit, SIGNAL(clicked()),
		this, SLOT(Quit()));

	ui.btnContinue->setEnabled(false);
	ui.btnSetting->setEnabled(false);
}

int Menu::openBegining()
{
	extern bool END;
	END = false;
	extern bool END_h;
	END_h = false;
	extern bool END_b;
	END_b = false;
	extern int Schedule;
	Schedule = 0;
	extern int Money;
	Money = 5000;
	extern int Attack;
	Attack = 2000;
	extern int Defense;
	Defense = 500;
	extern int Blood_max;
	Blood_max = 6000;
	extern int Blood;
	Blood = 6000;
	extern int Pneuma_max;
	Pneuma_max = 2000;
	extern int Pneuma;
	Pneuma = 2000;
	extern int Sister_state;
	Sister_state = 1;
	extern bool Key_cs_ms;
	Key_cs_ms = false;
	extern bool Drug_01;
	Drug_01 = false;
	extern bool Drug_02;
	Drug_02 = false;
	extern bool Drug_03;
	Drug_03 = false;
	extern bool Map_xw;
	Map_xw = false;
	extern bool Map_bh;
	Map_bh = false;
	extern bool Map_zq;
	Map_zq = false;
	extern bool Map_ql;
	Map_ql = false;
	extern bool qinglongjian;
	qinglongjian = 0;
	extern bool baihuxue;
	baihuxue = 0;
	extern bool zhuqueguan;
	zhuqueguan = 0;
	extern bool xuanwuzhongjia;
	xuanwuzhongjia = 0;
	extern int jian;
	extern int jia;
	extern int guan;
	extern int xue;
	jian = 1;
	guan = 1;
	jia = 1;
	xue = 1;

	extern bool END;
	extern bool END_h;
	extern bool END_b;
	extern int Schedule;
	Schedule++;
	this->hide();
	Begining bg;
	int ret = bg.exec();
	if (ret == QDialog::Rejected)
	{
		ret = QDialog::Accepted;
		Changan ca;
		ret = ca.exec();
	}
	while (true)
	{
		if (ret == QDialog::Accepted)
		{
			ret = QDialog::Rejected;
			Worldmap wm;
			ret = wm.exec();
			if (END || END_b || END_h)
			{
				break;
			}
		}
		else
		{
			break;
		}
		if (ret == QDialog::Accepted)
		{
			ret = QDialog::Rejected;
			Changan ca;
			ret = ca.exec();
			if (END || END_b || END_h)
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	if (END)
	{
		gameover go;
		go.exec();
	}
	if (END_b)
	{
		BEnd be;
		be.exec();
	}
	if (END_h)
	{
		HEnd he;
		he.exec();
	}
	extern bool END;
	END = false;
	extern bool END_h;
	END_h = false;
	extern bool END_b;
	END_b = false;
	extern int Schedule;
	Schedule = 0;
	extern int Money;
	Money = 5000;
	extern int Attack;
	Attack = 2000;
	extern int Defense;
	Defense = 500;
	extern int Blood_max;
	Blood_max = 6000;
	extern int Blood;
	Blood = 6000;
	extern int Pneuma_max;
	Pneuma_max = 2000;
	extern int Pneuma;
	Pneuma = 2000;
	extern int Sister_state;
	Sister_state = 1;
	extern bool Key_cs_ms;
	Key_cs_ms = false;
	extern bool Drug_01;
	Drug_01 = false;
	extern bool Drug_02;
	Drug_02 = false;
	extern bool Drug_03;
	Drug_03 = false;
	extern bool Map_xw;
	Map_xw = false;
	extern bool Map_bh;
	Map_bh = false;
	extern bool Map_zq;
	Map_zq = false;
	extern bool Map_ql;
	Map_ql = false;
	extern bool qinglongjian;
	qinglongjian = 0;
	extern bool baihuxue;
	baihuxue = 0;
	extern bool zhuqueguan;
	zhuqueguan = 0;
	extern bool xuanwuzhongjia;
	xuanwuzhongjia = 0;
	extern int jian;
	extern int jia;
	extern int guan;
	extern int xue;
	jian = 1;
	guan = 1;
	jia = 1;
	xue = 1;
	this->show();
	return 0;
}

int Menu::openSetting()
{
	this->hide();
	Setting set;
	set.exec();
	this->show();
	return 0;
}

int Menu::openFile()
{
	this->hide();
	File fil;
	fil.exec();
	this->show();
	return 0;
}

int Menu::Quit()
{
	this->close();
	return 0;
}
