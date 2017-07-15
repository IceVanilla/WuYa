#include "Bag.h"


extern int Money;
extern int jian;
extern int guan;
extern int jia;
extern int xue;
extern int Blood;
extern int Pneuma;
extern int Blood_max;
extern int Pneuma_max;
extern int Attack;
extern int Defense;
extern bool qinglongjian;
extern bool baihuxue;
extern bool zhuqueguan;
extern bool xuanwuzhongjia;
extern bool Drug_01;
extern bool Drug_02;
extern bool Drug_03;


Bag::Bag(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.qinglongjian, SIGNAL(clicked()),
		this, SLOT(btnQinglongjian()));
	connect(ui.zhengyangjian, SIGNAL(clicked()),
		this, SLOT(btnZhengyangjian()));
	connect(ui.btnzhengyangguan, SIGNAL(clicked()),
		this, SLOT(btnZhengyangguan()));
	connect(ui.btnzhengyangxue, SIGNAL(clicked()),
		this, SLOT(btnZhengyangxue()));
	connect(ui.btnhuxinjing, SIGNAL(clicked()),
		this, SLOT(btnHuxinjing()));
	connect(ui.btnzhuqueguan, SIGNAL(clicked()),
		this, SLOT(btnZhuqueguan()));
	connect(ui.btnxuanwujia, SIGNAL(clicked()),
		this, SLOT(btnXuanwujia()));
	connect(ui.btnbaihuxue, SIGNAL(clicked()),
		this, SLOT(btnBaihuxue()));

	ui.money_2->setText(QString::number(Money));
	ui.lablebrowser->hide();

	if (qinglongjian == 0)
	{
		ui.qinglongjian->hide();
		ui.zhengyangjian->hide();
	}
	else
	{
		if (jian==1)
		{
			ui.zhengyangjian->hide();
		}
		if (jian==2)
		{
			ui.qinglongjian->hide();
		}
	}
	if (zhuqueguan==0)
	{
		ui.btnzhuqueguan->hide();
		ui.btnzhengyangguan->hide();
	}
	else
	{
		if (guan == 1)
		{
			ui.btnzhengyangguan->hide();
		}
		if (guan == 2)
		{
			ui.btnzhuqueguan->hide();
		}
	}
	if (baihuxue == 0)
	{
		ui.btnbaihuxue->hide();
		ui.btnzhengyangxue->hide();
	}
	else
	{
		if (xue == 1)
		{
			ui.btnzhengyangxue->hide();
		}
		if (xue == 2)
		{
			ui.btnbaihuxue->hide();
		}
	}
	if (xuanwuzhongjia == 0)
	{
		ui.btnxuanwujia->hide();
		ui.btnhuxinjing->hide();
	}
	else
	{
		if (jia == 1)
		{
			ui.btnhuxinjing->hide();
		}
		if (jia == 2)
		{
			ui.btnxuanwujia->hide();
		}
	}
	if (Drug_01==0)
	{
		ui.btndrug1->hide();
		ui.drug12->hide();
	}
	if (Drug_02==0)
	{
		ui.btndrug2->hide();
		ui.drug22->hide();
	}
	if (Drug_03 == 0)
	{
		ui.btndrug3->hide();
		ui.drug32->hide();
	}
}

void Bag::btnZhengyangjian()
{
	ui.zhengyangjian->hide();
	ui.qinglongjian->show();
	jian = 1;
	Attack = 2000;
	ui.lablebrowser->setText(QString::fromLocal8Bit("你装备了正阳剑。"));
	ui.lablebrowser->show();
	play = true;
}
void Bag::btnZhengyangguan()
{
	ui.btnzhengyangguan->hide();
	ui.btnzhuqueguan->show();
	guan = 1;
	Blood_max -= 4000;
	if (Blood>=Blood_max)
	{
		Blood = Blood_max;
	}
	ui.lablebrowser->setText(QString::fromLocal8Bit("你装备了正阳冠。"));
	ui.lablebrowser->show();
	play = true;
}
void Bag::btnZhengyangxue()
{
	ui.btnzhengyangxue->hide();
	ui.btnbaihuxue->show();
	xue = 1;
	Pneuma -= 1000;
	if (Pneuma >= Pneuma_max)
	{
		Pneuma = Pneuma_max;
	}
	ui.lablebrowser->setText(QString::fromLocal8Bit("你装备了正阳靴。"));
	ui.lablebrowser->show();
	play = true;
}
void Bag::btnHuxinjing()
{
	ui.btnhuxinjing->hide();
	ui.btnxuanwujia->show();
	jia = 1;
	Defense = 500;
	ui.lablebrowser->setText(QString::fromLocal8Bit("你装备了护心镜。"));
	ui.lablebrowser->show();
	play = true;
}
void Bag::btnQinglongjian()
{
	ui.zhengyangjian->show();
	ui.qinglongjian->hide();
	jian = 2;
	Attack = 3000;
	ui.lablebrowser->setText(QString::fromLocal8Bit("你装备了青龙剑。"));
	ui.lablebrowser->show();
	play = true;
}
void Bag::btnBaihuxue()
{
	ui.btnzhengyangxue->show();
	ui.btnbaihuxue->hide();
	xue = 2;
	Pneuma += 1000;
	Pneuma_max += 1000;
	ui.lablebrowser->setText(QString::fromLocal8Bit("你装备了白虎靴。"));
	ui.lablebrowser->show();
	play = true;
}
void Bag::btnXuanwujia()
{

	ui.btnhuxinjing->show();
	ui.btnxuanwujia->hide();
	jia = 2;
	Defense = 1000;
	ui.lablebrowser->setText(QString::fromLocal8Bit("你装备了玄武重甲。"));
	ui.lablebrowser->show();
	play = true;
}
void Bag::btnZhuqueguan()
{
	ui.btnzhengyangguan->show();
	ui.btnzhuqueguan->hide();
	guan = 2;
	Blood_max += 4000;
	Blood += 4000;
	ui.lablebrowser->setText(QString::fromLocal8Bit("你装备了朱雀冠。"));
	ui.lablebrowser->show();
	play = true;
}

Bag::~Bag()
{

}
