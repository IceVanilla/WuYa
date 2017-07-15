#include "Shenyi.h"
#include "Tip.h"

Shenyi::Shenyi(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnGBW, SIGNAL(clicked()), this, SLOT(BuyGBW()));
	connect(ui.btnPYD, SIGNAL(clicked()), this, SLOT(BuyPYD()));

	ui.lblText->hide();
}

Shenyi::~Shenyi()
{
}

int Shenyi::BuyGBW()
{
	ui.lblText->hide();
	extern int Money;
	extern int Blood_max;
	extern int Blood;
	Tip tp(QString::fromLocal8Bit("是否花费2000文购买一粒固本丸？"));
	int ret = tp.exec();
	if (ret == QDialog::Accepted && Money >= 2000)
	{
		Blood_max += 2000;
		Blood = Blood_max;
		Money -= 2000;
	}
	else if (ret == QDialog::Accepted && Money < 2000)
	{
		ui.lblText->show();
	}
	return 0;
}

int Shenyi::BuyPYD()
{
	ui.lblText->hide();
	extern int Money;
	extern int Pneuma_max;
	extern int Pneuma;
	Tip tp(QString::fromLocal8Bit("是否花费2000文购买一粒培元丹？"));
	int ret = tp.exec();
	if (ret == QDialog::Accepted && Money >= 2000)
	{
		Pneuma_max += 1000;
		Pneuma = Pneuma_max;
		Money -= 2000;
	}
	else if (ret == QDialog::Accepted && Money < 2000)
	{
		ui.lblText->show();
	}
	return 0;
}
