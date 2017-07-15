#include "Cangshan.h"
#include "Dadian_c.h"
#include "MiShi_c.h"

Cangshan::Cangshan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnDadian, SIGNAL(clicked()), this, SLOT(OpenDadian()));
	connect(ui.btnMishi, SIGNAL(clicked()), this, SLOT(OpenMishi()));
	connect(ui.btnOut, SIGNAL(clicked()), this, SLOT(OpenOut()));

	extern int Schedule;
	if (Schedule == 4 || Schedule == 17)
	{
		ui.btnDadian->hide();
		ui.btnMishi->hide();
		ui.btnOut->hide();
	}
}

Cangshan::~Cangshan()
{
}

void Cangshan::mousePressEvent(QMouseEvent * event)
{
	extern int Schedule;
	if (Schedule == 4)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你连夜赶回沧山，只见血水沿着山门的阶梯蜿蜒而下，山门上下三百余人的尸体尽皆倒在血泊之中。"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->hide();
			ui.btnDadian->show();
			ui.btnMishi->show();
			t++;
			break;
		}
		default:
			break;
		}
	}
	if (Schedule == 17)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n十年后..."));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n此次下山游历，我也不多说什么了，只是要注意小心..."));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你正在给当年带回来的孩子准备着行囊，顺便嘱咐几句。忽地心口一凉，胸前冒出了半尺长的剑刃。"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n...为什么？"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("男孩\n对不起，我的师父是容涉。"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n原来...怪不得，怪不得这十年来你从未叫过我一声“师父”。"));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("男孩\n...对不起。"));
			t++;
			break;
		}
		case 7:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n罢了罢了，苦海无涯，回头是岸。好好活下去吧。"));
			t++;
			break;
		}
		case 8:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n师妹，果然是冤冤相报何时了啊，师兄现在来找你，可还算不晚？"));
			t++;
			break;
		}
		case 9:
		{
			extern bool END_b;
			END_b = true;
			this->close();
			t++;
			break;
		}
		default:
			break;
		}
	}
	return;
}

int Cangshan::OpenDadian()
{
	Dadian_c dd;
	dd.exec();
	extern int Schedule;
	if (Schedule == 6)
	{
		ui.btnOut->show();
	}
	return 0;
}

int Cangshan::OpenMishi()
{
	MiShi_c ms;
	ms.exec();
	extern int Schedule;
	if (Schedule == 6)
	{
		ui.btnOut->show();
	}
	extern bool END;
	if (END)
	{
		this->close();
	}
	return 0;
}

int Cangshan::OpenOut()
{
	this->close();
	return 0;
}
