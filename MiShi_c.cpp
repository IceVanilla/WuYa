#include "MiShi_c.h"

MiShi_c::MiShi_c(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

MiShi_c::~MiShi_c()
{
}

void MiShi_c::mousePressEvent(QMouseEvent *event)
{
	extern bool Key_cs_ms;
	extern int Schedule;
	if (!Key_cs_ms)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n密室锁上了，去四处转转，找一下钥匙吧。"));
			t++;
			break;
		}
		case 1:
		{
			this->close();
		}
		default:
			break;
		}
	}
	if (Key_cs_ms && Schedule == 5)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n（是师妹！她还活着！只是气息微弱，似是收了内伤。）"));
			t++;
			break;
		}
		case 1:
		{
			extern bool Drug_01;
			if (Drug_01)
			{
				ui.lblText->setText(QString::fromLocal8Bit("江陵\n（幸亏回沧山之前做了准备，快给师妹服药吧。）"));
				Drug_01 = false;
				extern int Sister_state;
				Sister_state = 2;
				t++;
				break;
			}
			if (!Drug_01)
			{
				ui.lblText->setText(QString::fromLocal8Bit("你身上没有任何可以救师妹的药，眼睁睁地看着师妹断了气，悲愤之下，你冲上影山欲为沧山派上下三百余人报仇，结果却惨死影山派掌门手下。"));
				extern bool END;
				extern int Sister_state;
				Sister_state = 0;
				END = true;
				this->close();
			}
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n师妹悠悠醒来，见是师兄，抱着你“哇”地哭了出来。"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("师妹\n师兄，你终于回来了，爹爹和师叔们都..."));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你安慰了师妹。片刻后，师妹的情绪稳定下来，拿出一个盒子。"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("师妹\n师兄，这是爹爹临死前让我交给你的。爹爹说，让你不要冲动，要好好活下去..."));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你打开盒子，发现里面有一张地图。"));
			extern bool Map_xw;
			Map_xw = true;
			t++;
			break;
		}
		case 7:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n得到玄武窟地图，玄武窟开启。"));
			t++;
			break;
		}
		case 8:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n师妹似乎伤得很重，你处置了山门上下的尸体，决定先带师妹回城疗伤。"));
			t++;
			break;
		}
		case 9:
		{
			extern int Schedule;
			Schedule++;
			this->close();
		}
		default:
			break;
		}
	}
	if (Key_cs_ms && Schedule == 6)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n还是尽快带师妹去疗伤吧。"));
			t++;
			break;
		}
		case 1:
		{
			this->close();
			t++;
		}
		default:
			break;
		}
	}
	return;
}
