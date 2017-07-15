#include "Minju2.h"

Minju2::Minju2(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Minju2::~Minju2()
{
}

void Minju2::mousePressEvent(QMouseEvent *event)
{
	extern int Schedule;
	if (Schedule == 8)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n前辈可知北海巨兕与上古青龙的下落？小妹急需两种药材解毒。"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("老者\n老夫倒是在多年前斩过一只北海巨兕，既是救人，这北海巨兕之角你便拿去吧。"));
			extern bool Drug_02;
			Drug_02 = true;
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n多谢前辈了。"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("老者\n老夫早已退出江湖，这东西搁着也是占地儿，倒不如你拿了去救人。只是这上古青龙...老夫也是无能为力了。"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n多谢前辈慷慨相赠，晚辈也不便继续叨扰了，告辞。"));
			t++;
			break;
		}
		case 5:
		{
			Schedule++;
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
