#include "Yingshan.h"
#include "war.h"

Yingshan::Yingshan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnRS, SIGNAL(clicked()), this, SLOT(OnRongshe()));

	ui.btnRS->hide();
	extern int Schedule;
	if (Schedule != 15)
	{
		ui.lblText->hide();
	}
}

Yingshan::~Yingshan()
{
}

int Yingshan::OnRongshe()
{
	extern bool END;
	war wr;
	int ret = wr.exec();
	if (ret == QDialog::Accepted)
	{
		ui.btnRS->hide();
	}
	if (!ret && END)
	{
		this->close();
	}
	return 0;
}

void Yingshan::mousePressEvent(QMouseEvent *event)
{
	extern int Schedule;
	if (Schedule == 15)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你一路杀上影山，凭着一身神装，神挡弑神，佛挡杀佛，终于逼出了掌门容涉。"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n我乃沧山派大弟子江陵，今日便来为我沧山派报仇！"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("容涉\n无知小儿，那你便去陪他们吧。"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->hide();
			ui.btnRS->show();
			t++;
			break;
		}
		default:
			break;
		}
	}
	return;
}
