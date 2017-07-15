#include "KeZhan.h"
#include "Tip.h"
#include <QTime>
#include "Bag.h"
#include "State.h"

KeZhan::KeZhan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnBXS, SIGNAL(clicked()), this, SLOT(OpenBXS()));
	connect(ui.btnRest, SIGNAL(clicked()), this, SLOT(OpenRest()));
	connect(ui.btnBag, SIGNAL(clicked()), this, SLOT(OpenBag()));
	connect(ui.btnState, SIGNAL(clicked()), this, SLOT(OpenState()));

	QTime tm;
	tm = QTime::currentTime();
	qsrand(tm.msec() + tm.second() * 1000);

	extern int Schedule;
	if (Schedule == 2)
	{
		ui.btnBXS->hide();
		ui.lblBXS->hide();
		ui.btnRest->hide();
		ui.btnBag->hide();
		ui.btnState->hide();
	}
	if (Schedule >= 7 && Schedule <= 20)
	{
		ui.lblText->hide();
	}
}

KeZhan::~KeZhan()
{
}

void KeZhan::mousePressEvent(QMouseEvent * event)
{
	extern int Schedule;
	if (Schedule == 2)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("酒客甲\n这雨下了半个多月，生意都做不了，真是晦气。"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("酒客乙\n唉，兴许是那沧山派死的人太多了，怨气过重..."));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n（那边好像提到了沧山派，我也许久未曾听到师门的消息了，不妨过去探听一下。）"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n两位仁兄，方才听二位提到了沧山派，可是最近发生了什么大事？"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("酒客甲\n这事儿闹得整个武林是人尽皆知，这位小哥竟还未曾听说？"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("酒客乙\n这事儿要从半个月前说起了...半个月前，那影山派掌门带人杀上沧山，激战一天一夜，沧山门前血流成河，沧山派百年基业，一夜之间，轰然倾塌。真是可惜啊，可惜。"));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你忽然觉得眼前发黑，耳中轰鸣一片，只听两个酒客朦胧之中似在唤你，不久便失去了知觉..."));
			t++;
			break;
		}
		case 7:
		{
			Schedule++;
			t++;
			this->close();
			break;
		}
		default:
			break;
		}
	}
	if (bxs)
	{
		switch (tb)
		{
		case 0:
		{
			QString str;
			int n = qrand() % 8;
			switch (n)
			{
			case 0:
			{
				str = QString::fromLocal8Bit("百晓生\n江湖上传闻有青白朱玄四种神装，分别被镇在东四南北四个方位，由四种神兽守护。若能够得到这四种神装，便可称霸武林，翻覆天下。");
				break;
			}
			case 1:
			{
				str = QString::fromLocal8Bit("百晓生\n长安城医馆的大夫，真实身份可是药王谷的前任谷主，真是大隐隐于市啊。");
				break;
			}
			case 2:
			{
				str = QString::fromLocal8Bit("百晓生\n冤冤相报何时了...");
				break;
			}
			case 3:
			{
				str = QString::fromLocal8Bit("百晓生\n有人的地方，就是江湖。");
				break;
			}
			case 4:
			{
				str = QString::fromLocal8Bit("百晓生\n影山派掌门容涉是当今武林中武功第一高强之人，传闻他是二十年前沧山派剿灭魔教时幸存下来的魔教遗孤。");
				break;
			}
			case 5:
			{
				str = QString::fromLocal8Bit("百晓生\n长安城里的老者，相传曾是一位武林高手，如今退隐江湖，逍遥自在。");
				if (Schedule == 7)
				{
					Schedule++;
				}
				break;
			}
			case 6:
			{
				str = QString::fromLocal8Bit("百晓生\n在客栈休息一晚，便能回复所有的气血，少侠不妨一试。");
				break;
			}
			case 7:
			{
				str = QString::fromLocal8Bit("百晓生\n沧山派大弟子江陵，是个放浪不羁之人，以一套正阳剑法闻名于世。影山派屠山之时，他正在外游历，这才躲过一劫，如今也不知怎么样了。");
				break;
			}
			default:
				break;
			}
			ui.lblText->setText(str);
			tb++;
			break;
		}
		case 1:
		{
			ui.lblText->clear();
			ui.lblText->hide();
			ui.btnBXS->show();
			ui.lblBXS->show();
			ui.btnRest->show();
			ui.btnBag->show();
			ui.btnState->show();
			bxs = false;
			tb++;
			break;
		}
		default:
			break;
		}
	}
}

int KeZhan::OpenBXS()
{
	ui.btnBXS->hide();
	ui.lblBXS->hide();
	ui.btnRest->hide();
	ui.btnBag->hide();
	ui.btnState->hide();
	ui.lblText->show();
	tb = 0;
	bxs = true;
	return 0;
}

int KeZhan::OpenRest()
{
	ui.btnBXS->hide();
	ui.btnBag->hide();
	ui.btnState->hide();
	ui.btnRest->hide();
	ui.lblBXS->hide();
	Tip tp(QString::fromLocal8Bit("是否花费100文休息一晚？"));
	int ret = tp.exec();
	extern int Money;
	extern int Blood;
	extern int Blood_max;
	extern int Pneuma_max;
	extern int Pneuma;
	if (ret == QDialog::Accepted && Money >= 100)
	{
		Money -= 100;
		Blood = Blood_max;
		Pneuma = Pneuma_max;
	}
	else if (ret == QDialog::Accepted && Money < 100)
	{
		Tip tp(QString::fromLocal8Bit("余额不足！"));
		tp.exec();
	}
	ui.btnBXS->show();
	ui.btnBag->show();
	ui.btnState->show();
	ui.btnRest->show();
	ui.lblBXS->show();
	return 0;
}

int KeZhan::OpenBag()
{
	Bag bg;
	bg.exec();
	return 0;
}

int KeZhan::OpenState()
{
	State st;
	st.exec();
	return 0;
}
