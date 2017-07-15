#include "Yiguan.h"
#include "Tip.h"
#include "Shenyi.h"
#include "Tip.h"

Yiguan::Yiguan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnSY, SIGNAL(clicked()), this, SLOT(OpenSY()));

	extern int Schedule;
	extern bool Drug_02;
	extern bool Drug_03;
	if (Schedule == 3 || Schedule == 6 || (Schedule == 7 && !Drug_02)
		|| (Schedule == 9 && Drug_02) || (Schedule==14 && Drug_03)
		|| Schedule == 16)
	{
		ui.btnSY->hide();
		ui.lblSY->hide();
	}
	if (Schedule >= 10 && Schedule <= 13 || Schedule == 15
		|| Schedule>=17 && Schedule <= 20)
	{
		ui.lblText->hide();
	}
}

Yiguan::~Yiguan()
{
}

void Yiguan::mousePressEvent(QMouseEvent *event)
{
	extern int Schedule;
	extern bool Drug_02;
	extern bool Drug_03;
	if (Schedule == 3)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你醒转过来，眼前已是换了一幅场景。你躺在床上，一位老者正在看着你。"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n你醒了？"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你点点头，忽地又记起方才听到的消息，只觉得太不真实，只想尽快回沧山看看。"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n我看你面色惨败，印堂发黑，乃是气弱体虚之状啊。不妨备几粒老夫研发的新药——伸腿瞪眼丸，保你一个时辰之内活死人肉白骨。我看与你有缘，便打折卖于你，机不可失，失不再来啊。"));
			t++;
			break;
		}
		case 4:
		{
			Tip tp(QString::fromLocal8Bit("是否花费2000文购买一粒伸腿瞪眼丸？"));
			int ret = tp.exec();
			if (ret == QDialog::Accepted)
			{
				extern bool Drug_01;
				extern int Money;
				Drug_01 = true;
				Money -= 2000;
			}
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n多谢阁下，晚辈尚有要事在身，先走一步了。"));
			t++;
			break;
		}
		case 5:
		{
			extern int Schedule;
			Schedule++;
			this->close();
		}
		default:
			break;
		}
	}
	if (Schedule == 6)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n大夫，我家小妹受了伤，请您无论如何也要治好她。"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n扶她躺下，老夫瞧瞧。"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n大夫诊治片刻..."));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n你家小妹中毒颇深，若不是服用了老夫的伸腿瞪眼丸，恐怕也撑不到现在了。"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n可还有办法医治？"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n办法倒是有，只是要得到所需的药材，怕是要费一番功夫的。"));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n什么药材？"));
			t++;
			break;
		}
		case 7:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n北海巨兕之角和上古青龙之鳞。"));
			t++;
			break;
		}
		case 8:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n我这便去找。"));
			t++;
			break;
		}
		case 9:
		{
			extern int Schedule;
			Schedule++;
			this->close();
			break;
		}
		default:
			break;
		}
	}

	if (Schedule == 7 || (Schedule == 8 && !Drug_02))
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n去打听一下药材的下落吧。"));
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

	if (Schedule == 9 && Drug_02)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n有了北海巨兕之角，这姑娘的毒倒是可以抑制一段时间。但若想痊愈，非上古青龙之鳞不可啊。"));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n只是晚辈如今仍是毫无头绪。"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n这四种神兽之间想必存在某种联系，不妨去试一下。"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n好，晚辈这便去。"));
			t++;
			break;
		}
		case 4:
		{
			Drug_02 = false;
			Schedule++;
			this->close();
			t++;
			break;
		}
		default:
			break;
		}
	}

	if (Schedule == 14)
	{
		int ret;
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n对对对，这就是青龙鳞了，我这就去为那姑娘解读。"));
			Drug_03 = false;
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n两个时辰之后..."));
			extern int Sister_state;
			Sister_state++;
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("师妹\n师兄..."));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n师妹，有了大夫的诊治，你不久就会痊愈了，你先在这里安心修养吧。"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("师妹\n师兄，你要去哪儿？"));
			t++;
			break;
		}
		case 5:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n我已经找齐了四件神装，现在便打上影山，手刃容涉，为沧山上下三百余人报仇。"));
			t++;
			break;
		}
		case 6:
		{
			ui.lblText->setText(QString::fromLocal8Bit("师妹\n师兄，爹爹临死前最后一句话，就是要我们好好活下去，你还是不懂他的苦心吗？冤冤相报何时了，师兄..."));
			t++;
			break;
		}
		case 7:
		{
			Tip tp(QString::fromLocal8Bit("是否选择继续报仇？"));
			ret = tp.exec();
			if (ret == QDialog::Rejected)
			{
				re = true;
			}
			else if (ret == QDialog::Accepted)
			{
				ac = true;
			}
			Schedule++;
			t++;
			break;
		}
		default:
			break;
		}
	}
	if (Schedule == 15)
	{
		switch (t2)
		{
		case 0:
		{
			if (re)
			{
				ui.lblText->setText(QString::fromLocal8Bit("江陵\n好，师兄听你的。我们...回家。"));
				extern bool END_h;
				END_h = true;
				this->close();
			}
			else if (ac)
			{
				ui.lblText->setText(QString::fromLocal8Bit("江陵\n师妹，原谅师兄实在是不忍心看着朝夕相处的同门就这样白白丧命。你在这里安心修养，等师兄报了仇，就回来接你。"));
				t2++;
				break;
			}
		}
		case 1:
		{
			this->close();
			t2++;
			break;
		}
		default:
			break;
		}
	}
	if (Schedule == 16)
	{
		switch (t)
		{
		case 0:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n小兄弟你可回来了，那姑娘怕是不放心你，你走之后便偷偷溜走了，我派去寻她的人只说..."));
			t++;
			break;
		}
		case 1:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你仿佛生生受了一道惊雷，只瞧见大夫的嘴一张一合，却丝毫听不清他说的什么。过了半晌，才缓过来些许。"));
			t++;
			break;
		}
		case 2:
		{
			ui.lblText->setText(QString::fromLocal8Bit("江陵\n他，他说什么？"));
			t++;
			break;
		}
		case 3:
		{
			ui.lblText->setText(QString::fromLocal8Bit("大夫\n那姑娘，在你与影山派混战时，被误杀了。"));
			t++;
			break;
		}
		case 4:
		{
			ui.lblText->setText(QString::fromLocal8Bit("\n你觉得身体仿佛已经不是自己的一般，对大夫道了声“有劳了”，便任由双脚拖着你走出医馆。"));
			t++;
			break;
		}
		case 5:
		{
			extern int Sister_state;
			Sister_state = 0;
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

int Yiguan::OpenSY()
{
	Shenyi sy;
	sy.exec();
	return 0;
}
