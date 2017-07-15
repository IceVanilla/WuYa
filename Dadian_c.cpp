#include "Dadian_c.h"

Dadian_c::Dadian_c(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Dadian_c::~Dadian_c()
{
}

void Dadian_c::mousePressEvent(QMouseEvent * event)
{
	extern int Schedule;
	extern bool Key_cs_ms;
	if (Schedule == 4)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n只见一向对你关爱有加的师父此刻正倒在一片早已干涸的血迹之中，死不瞑目，心中不胜悲愤。你走过去，跪在师傅的身边为他阖上了双眼，却突然发现师父手中仿佛握着什么...原来是一把钥匙。"));
			Key_cs_ms = true;
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n这是...后山密室的钥匙！莫不是师傅留给我的线索。（去密室看看吧）"));
			t++;
			break;
		}
		case 2:
		{
			Schedule++;
			this->close();
			break;
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
			ui.lblText->setText(QString::fromLocal8Bit("\n还是尽快去找密室吧。"));
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
