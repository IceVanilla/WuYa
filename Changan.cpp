#include "Changan.h"
#include "KeZhan.h"
#include "Yiguan.h"
#include <QDebug>

Changan::Changan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnKezhan, SIGNAL(clicked()), this, SLOT(OpenKezhan()));
	connect(ui.btnMinju1, SIGNAL(clicked()), this, SLOT(OpenMinju1()));
	connect(ui.btnMinju2, SIGNAL(clicked()), this, SLOT(OpenMinju2()));
	connect(ui.btnYiguan, SIGNAL(clicked()), this, SLOT(OpenYiguan()));
	connect(ui.btnOut, SIGNAL(clicked()), this, SLOT(OpenOut()));

	extern int Schedule;
	if (Schedule == 1)
	{
		ui.btnKezhan->hide();
		ui.btnMinju1->hide();
		ui.btnMinju2->hide();
		ui.btnYiguan->hide();
		ui.btnOut->hide();
	}
	if (Schedule == 6)
	{
		ui.btnKezhan->setEnabled(false);
		ui.btnMinju1->setEnabled(false);
		ui.btnMinju2->setEnabled(false);
		ui.btnOut->setEnabled(false);
	}
}

Changan::~Changan()
{
}

void Changan::mousePressEvent(QMouseEvent *event)
{
	extern int Schedule;
	if (Schedule == 1)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n长安城里行人稀。"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n（初到长安，不妨先找个客栈稍作整顿。）"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n鼠标左键点击进行操作。\n关闭当前界面返回上一级界面。"));
			t++;
			break;
		}
		case 3:
		{
			ui.btnKezhan->show();
			ui.btnMinju1->show();
			ui.btnMinju2->show();
			ui.btnYiguan->show();
			ui.btnOut->show();
			ui.btnMinju1->setEnabled(false);
			ui.btnMinju2->setEnabled(false);
			ui.btnYiguan->setEnabled(false);
			ui.btnOut->setEnabled(false);
			ui.lblText->hide();
			t++;
			Schedule++;
			qDebug() << Schedule;
			break;
		}
		default:
			break;
		}
	}
	if (Schedule == 4 && t == 4)
	{
		ui.lblText->hide();
		ui.btnKezhan->show();
		ui.btnMinju1->show();
		ui.btnMinju2->show();
		ui.btnYiguan->show();
		ui.btnOut->show();
		ui.btnMinju1->setEnabled(false);
		ui.btnMinju2->setEnabled(false);
		ui.btnYiguan->setEnabled(false);
		ui.btnKezhan->setEnabled(false);
		ui.btnOut->setEnabled(true);
	}
	if (Schedule == 17)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n长安城中又下起了雨。"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你漫无目的地在空旷的街道上走着，直到在一条小巷子口看到了一个蜷缩在墙边的男孩子。"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n孩子，这雨一时是停不了的，快回家吧。"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("男孩\n回家？...我已经没有家了。"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n对啊...没有家了。"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你似在回应着男孩，又好像是在对自己说着。"));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n不介意的话，就跟我走吧，我可以教你武功。大概...也只有武功了吧。"));
			t++;
			break;
		}
		case 7:
		{
			ui.lblText->setText(QString::fromLocal8Bit("男孩\n...我有师父。"));
			t++;
			break;
		}
		case 8:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n那你师父呢？"));
			t++;
			break;
		}
		case 9:
		{
			ui.lblText->setText(QString::fromLocal8Bit("男孩\n...死了。"));
			t++;
			break;
		}
		case 10:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n放心，我不会逼你拜我为师。"));
			t++;
			break;
		}
		case 11:
		{
			ui.lblText->setText(QString::fromLocal8Bit("男孩\n...好。"));
			t++;
			break;
		}
		case 12:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你带着这个男孩子，找到师妹的遗骨，回到沧山。"));
			t++;
			break;
		}
		case 13:
		{
			this->accept();
			t++;
			break;
		}
		default:
			break;
		}
	}
	return;
}

int Changan::OpenKezhan()
{
	KeZhan kz;
	kz.exec();
	extern int Schedule;
	if (Schedule == 3)
	{
		Yiguan yg;
		yg.exec();
		ui.btnKezhan->hide();
		ui.btnMinju1->hide();
		ui.btnMinju2->hide();
		ui.btnYiguan->hide();
		ui.btnOut->hide();
		ui.lblText->show();
		ui.lblText->setText(QString::fromLocal8Bit("快回沧山看看吧。"));
	}
	if (Schedule == 8)
	{
		ui.btnMinju1->setEnabled(true);
		ui.btnMinju2->setEnabled(true);
	}
	return 0;
}

int Changan::OpenMinju1()
{
	Minju1 mj1;
	mj1.exec();
	return 0;
}

int Changan::OpenMinju2()
{
	Minju2 mj2;
	mj2.exec();
	extern int Schedule;
	if (Schedule == 9)
	{
		ui.btnMinju1->setEnabled(false);
		ui.btnMinju2->setEnabled(false);
	}
	return 0;
}

int Changan::OpenYiguan()
{
	Yiguan yg;
	yg. exec();
	extern int Schedule;
	if (Schedule == 7)
	{
		ui.btnKezhan->setEnabled(true);
	}
	if (Schedule == 10)
	{
		ui.btnOut->setEnabled(true);
	}
	if (Schedule == 17)
	{
		ui.btnKezhan->hide();
		ui.btnMinju1->hide();
		ui.btnMinju2->hide();
		ui.btnYiguan->hide();
		ui.btnOut->hide();
	}
	extern bool END_h;
	if (END_h)
	{
		this->close();
	}
	return 0;
}

int Changan::OpenOut()
{
	accept();
	return 0;
}
