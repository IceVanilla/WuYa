#include "war.h"
#include <QTime>
#include <QDebug>

extern int Attack;
extern int Defense;
extern int Blood;
extern int Pneuma;
extern int Schedule;
extern bool Drug_03;
extern bool qinglongjian;
extern bool zhuqueguan;
extern bool xuanwuzhongjia;
extern bool baihuxue;
extern int Blood_max;
extern int Pneuma_max;
extern bool Map_xw;
extern bool Map_bh;
extern bool Map_zq;
extern bool Map_ql;
extern bool END;

int bosshuifu;
int bossnowhp;
int m_Attack;
int m_Defense;
int BossHP;
int BossMaxHP;
int BossAttack;
int m_BossAttack;
int BossDefense;
int m_BossDefense;
int atkup = 0;
int Hpup = 0;
int bossdfsup = 0;
int bossatkup = 0;
int dfsdown = 0;
int atkdown = 0;
int Hpdown = 0;
int heroatk;
int bossatk;

war::war(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btnpugong, SIGNAL(clicked()),
		this, SLOT(onbtnPugong()));
	connect(ui.btnzhanyi, SIGNAL(clicked()),
		this, SLOT(onbtnZhanyi()));
	connect(ui.btnmingxiang, SIGNAL(clicked()),
		this, SLOT(onbtnMingxiang()));
	connect(ui.btncangshan, SIGNAL(clicked()),
		this, SLOT(onbtnCangshan()));
	connect(ui.btnzhengyang, SIGNAL(clicked()),
		this, SLOT(onbtnZhengyang()));
	connect(ui.btnqinglong, SIGNAL(clicked()),
		this, SLOT(onbtnQinglong()));

	

	if (Schedule == 10)
	{
		BossAttack = 800;
		BossDefense = 1500;
		BossHP = 30000;
		BossMaxHP = 30000;
		m_BossAttack = 800;
		m_BossDefense = 1500;
		ui.bossname->setText(QString::fromLocal8Bit("  玄武"));
		ui.baihu->hide();
		ui.zhuque->hide();
		ui.qinglong->hide();
		ui.boss->hide();
	}
	if (Schedule == 11)
	{
		BossAttack = 1500;
		BossDefense = 1000;
		BossHP = 20000;
		BossMaxHP = 20000;
		m_BossAttack = 1500;
		m_BossDefense = 1000;
		ui.bossname->setText(QString::fromLocal8Bit("  白虎"));
		ui.xuanwu->hide();
		ui.zhuque->hide();
		ui.qinglong->hide();
		ui.boss->hide();
	}
	if (Schedule == 12)
	{
		BossAttack = 1200;
		BossDefense = 1200;
		BossHP = 10000;
		BossMaxHP = 10000;
		m_BossAttack = 1200;
		m_BossDefense = 1200;
		ui.bossname->setText(QString::fromLocal8Bit("  朱雀"));
		ui.baihu->hide();
		ui.xuanwu->hide();
		ui.qinglong->hide();
		ui.boss->hide();
	}
	if (Schedule == 13)
	{
		BossAttack = 1500;
		BossDefense = 800;
		BossHP = 25000;
		BossMaxHP = 25000;
		m_BossAttack = 1500;
		m_BossDefense = 800;
		ui.bossname->setText(QString::fromLocal8Bit("  青龙"));
		ui.baihu->hide();
		ui.zhuque->hide();
		ui.xuanwu->hide();
		ui.boss->hide();
	}
	if (Schedule == 15)  //Boss
	{
		BossAttack = 2000;
		BossDefense = 1000;
		BossHP = 30000;
		BossMaxHP = 30000;
		m_BossAttack = 2000;
		m_BossDefense = 1000;
		ui.bossname->setText(QString::fromLocal8Bit("  容涉"));
		ui.baihu->hide();
		ui.zhuque->hide();
		ui.qinglong->hide();
		ui.xuanwu->hide();
	}
	if (Schedule <= 13)
	{
		ui.btnqinglong->hide();
	}

	this->state();
}



void war::mousePressEvent(QMouseEvent *event)
{
	if (win)
	{
		accept();
	}
	if (lose)
	{
		reject();
	}
	return;
}

void war::winvalue()
{
	if (Blood > 0 && BossHP <= 0)
	{
		win = true;
		if (Schedule == 10)
		{
			xuanwuzhongjia = 1;
			Map_bh = true;
			ui.warBrowser->append(QString::fromLocal8Bit("战斗胜利，你获得了玄武重甲和白虎穴地图！"));
		}
		if (Schedule == 11)
		{
			baihuxue = 1;
			Map_zq = true;
			ui.warBrowser->append(QString::fromLocal8Bit("战斗胜利，你获得了白虎靴和朱雀巢地图！"));
		}
		if (Schedule == 12)
		{
			zhuqueguan = 1;
			Map_ql = true;
			ui.warBrowser->append(QString::fromLocal8Bit("战斗胜利，你获得了朱雀冠和青龙潭地图！"));
		}
		if (Schedule == 13)
		{
			qinglongjian = 1;
			Drug_03 = 1;
			ui.warBrowser->append(QString::fromLocal8Bit("战斗胜利，你获得了青龙剑和青龙鳞！"));
		}
		if (Schedule == 15)
		{
			ui.warBrowser->append(QString::fromLocal8Bit("战斗胜利，你杀死了容涉。"));
		}
		Schedule++;
		ui.btnpugong->setEnabled(false);
		ui.btnzhanyi->setEnabled(false);
		ui.btnmingxiang->setEnabled(false);
		ui.btncangshan->setEnabled(false);
		ui.btnzhengyang->setEnabled(false);
		ui.btnqinglong->setEnabled(false);
	}
}



void war::buffvalue()
{
	if (atkup==0)
	{
		m_Attack = Attack;
	}
	if (atkdown==0)
	{
		m_Attack = Attack;
	}
	if (dfsdown==0)
	{
		m_Defense = Defense;
	}
	if (bossdfsup==0)
	{
		m_BossDefense = BossDefense;
	}
	if (bossatkup==0)
	{
		m_BossAttack = BossAttack;
	}
	if (Hpup)
	{
		int huifu = Blood_max/10;
		int hpnow = Blood + huifu;
		if (hpnow >= Blood_max)
		{
			Blood = Blood_max;
		}
		else Blood = hpnow;
		ui.warBrowser->append(QString::fromLocal8Bit("你的血量持续回复中... ..."));
	}
	if (Hpdown)
	{
		int diaoxue = Blood_max / 10;
		Blood -= diaoxue;
		this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
	}
}



void war::disbuff()
{
	if (atkup)
	{
		atkup--;
	}
	if (Hpup)
	{
		Hpup--;
	}
	if (atkdown)
	{
		atkdown--;
	}
	if (dfsdown)
	{
		dfsdown--;
	}
	if (bossdfsup)
	{
		bossdfsup--;
	}
	if (bossatkup)
	{
		bossatkup--;
	}
}



void war::bossjineng()
{
	QTime t = QTime::currentTime();
    qsrand(t.msec() + t.second() * 1000);
	int i = qrand() % 5;
	if (Schedule==10)    //玄武
	{ 
		switch (i)
		{
		case 0:
			bossatk=BossAttack * 2 - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("玄武咬中了你，你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		case 1:
			m_BossDefense = BossDefense * 2;
			bossdfsup = 2;
			ui.warBrowser->append(QString::fromLocal8Bit("玄武缩回龟壳里，它的防御暂时提高了。"));
			break;
		case 2:
			ui.warBrowser->append(QString::fromLocal8Bit("玄武什么都没做，似乎在观察你。"));
			break;
		default:
			bossatk = m_BossAttack - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("玄武的蛇尾扫中了你。你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		}
	}

	if (Schedule == 11)   //白虎
	{
		switch (i)
		{
		case 0:
			m_Defense -= 250;
			dfsdown = 3;
			ui.warBrowser->append(QString::fromLocal8Bit("白虎咆哮一声，你的防御暂时下降了。"));
			break;
		case 1:
			bossatk = BossAttack * 2 - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("白虎奋力向你扑来，你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		case 2:
			bossatk = m_BossAttack*1.5-m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("白虎的利齿划开了你的皮肤，你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		default:
			bossatk = m_BossAttack - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("白虎的利爪拍中了你。你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		}
	}

	if (Schedule == 12)   //朱雀
	{
		switch (i)
		{
		case 0:
			m_Defense = Defense*1.5;
			bossdfsup = 2;
			ui.warBrowser->append(QString::fromLocal8Bit("朱雀飞到空中，它受到的伤害暂时下降了。"));
			break;
		case 1:
			bossatk = BossAttack * 2;
			ui.warBrowser->append(QString::fromLocal8Bit("朱雀喷出的火焰灼伤了你，你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		case 2:
			bosshuifu = BossMaxHP / 10;
			bossnowhp = BossHP + bosshuifu;
			if (bossnowhp>=BossMaxHP)
			{
				BossHP = BossMaxHP;
			}
			else BossHP = bossnowhp;
			ui.warBrowser->append(QString::fromLocal8Bit("朱雀在空中盘旋，它回复了部分血量。"));
			break;
		default:
			bossatk = m_BossAttack - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("朱雀的尖喙啄伤了你。你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		}
	}

	if (Schedule == 13)   //青龙
	{
		switch (i)
		{
		case 0:
			bossatk = m_BossAttack * 2 - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("龙尾横扫击中了你。你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		case 1:
			m_BossAttack = BossAttack*1.5;
			bossatkup = 3;
			ui.warBrowser->append(QString::fromLocal8Bit("青龙震怒，龙吟声震耳欲聋，它的伤害暂时提高了；"));
			break;
		case 2:
			m_BossDefense = BossDefense * 3;
			bossdfsup = 2;
			ui.warBrowser->append(QString::fromLocal8Bit("青龙按兵不动，似乎在窥伺，它的防御暂时提高了。"));
			break;
		default:
			bossatk = m_BossAttack - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("青龙向你俯冲过来。你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		}
	}

	if (Schedule == 15)   //容涉
	{
		switch (i)
		{
		case 0:
			bossatk = m_BossAttack * 2 - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("容涉释放南冥神功。你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		case 1:
			Blood -= 2000;
			Hpdown = 3;
			ui.warBrowser->append(QString::fromLocal8Bit("容涉使出一记三阴毒爪，你中毒了。"));
			break;
		case 2:
			if (Pneuma>=Pneuma_max/5)
			{
				Pneuma -= Pneuma_max / 5;
				BossHP += BossMaxHP / 10;
				if (BossHP>=BossMaxHP)
				{
					BossHP = BossMaxHP;
				}
				this->state();
			}
			else
			{
				int absorb = Pneuma;
				Pneuma = 0;
				BossHP += (BossMaxHP / 10) * (absorb / Pneuma_max * 5);
				if (BossHP >= BossMaxHP)
				{
					BossHP = BossMaxHP;
				}
				this->state();
			}
			ui.warBrowser->append(QString::fromLocal8Bit("容涉发动了斗转星移。"));
			break;
		default:
			bossatk = m_BossAttack - m_Defense;
			Blood -= bossatk;
			ui.warBrowser->append(QString::fromLocal8Bit("容涉运功对你发动攻击。你受到了") + QString::number(bossatk) + QString::fromLocal8Bit("点伤害。"));
			break;
		}
	}
}



void war::losevalue()
{
	if (Blood <= 0)
	{
		lose = true;
		ui.warBrowser->append(QString::fromLocal8Bit("你倒下了。"));
		END = true;
		ui.btnpugong->setEnabled(false);
		ui.btnzhanyi->setEnabled(false);
		ui.btnmingxiang->setEnabled(false);
		ui.btncangshan->setEnabled(false);
		ui.btnzhengyang->setEnabled(false);
		ui.btnqinglong->setEnabled(false);
	}
}



void war::state()
{
	ui.hp->setText(QString::number(Blood));
	ui.maxhp->setText(QString::number(Blood_max));
	ui.sp->setText(QString::number(Pneuma));
	ui.maxsp->setText(QString::number(Pneuma_max));
	ui.bossstate->setText(QString::number(BossHP));
}



void war::onbtnPugong()
{
	buffvalue();
	QTime T = QTime::currentTime();
	qsrand(T.msec() + T.second() * 1000);
	int j = qrand() % 10;
	heroatk = m_Attack - m_BossDefense;
	if (j == 0)
	{
		heroatk = 2*m_Attack-m_BossDefense;
		BossHP -= heroatk;
		ui.warBrowser->append(QString::fromLocal8Bit("会心一击！你对敌人造成了") + QString::number(heroatk) + QString::fromLocal8Bit("点伤害。"));
	}
	else
	{
		BossHP -= heroatk;
		ui.warBrowser->append(QString::fromLocal8Bit("你提剑刺去，你对敌人造成了") + QString::number(heroatk) + QString::fromLocal8Bit("点伤害。"));
	}
	int sphuifu = Pneuma_max / 10;
	int spnow = Pneuma + sphuifu;
	if (spnow>Pneuma_max)
	{
		Pneuma = Pneuma_max;
	}
	else Pneuma = spnow;
	this->state();
	this->winvalue();
	if (win)
	{
		this->state();
		return;
	}
	this->bossjineng();
	this->state();
	this->losevalue();
	if (lose)
	{
		this->state();
		return;
	}
	this->disbuff();
}



void war::onbtnZhanyi()
{
	if (Pneuma>=200)
	{
		Pneuma -= 200;
	    this->buffvalue();
	    m_Attack = Attack*1.2;
	    atkup = 3;
	    ui.warBrowser->append(QString::fromLocal8Bit("你蓄势待发，攻击力暂时提升了。"));
		this->state();
		this->bossjineng();
	    this->state();
	    this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
	    this->disbuff();
	}
	else
	{
		ui.warBrowser->append(QString::fromLocal8Bit("你的气力不足，技能施放失败。"));
	}
}



void war::onbtnMingxiang()
{
	if (Pneuma>=400)
	{
		Pneuma -= 400;
        this->buffvalue();
		int hphuifu = Blood_max / 5;
		int hpnow = Blood + hphuifu;
		if (hpnow>=Blood_max)
		{
			Blood = Blood_max;
		}
		else Blood = hpnow;
		Hpup = 3;
	    ui.warBrowser->append(QString::fromLocal8Bit("你进入冥想状态，你的血量回复了。"));
		this->state();
		this->bossjineng();
		this->state();
		this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
		this->disbuff();
	}
	else
	{
		ui.warBrowser->append(QString::fromLocal8Bit("你的气力不足，技能施放失败。"));
	}
}



void war::onbtnCangshan()
{
	if (Pneuma >= 400)
	{
		Pneuma -= 400;
		this->buffvalue();
		heroatk = m_Attack * 2-m_BossDefense;
		BossHP -= heroatk;
		ui.warBrowser->append(QString::fromLocal8Bit("你使出一套沧山剑法，对敌人造成了") + QString::number(heroatk) + QString::fromLocal8Bit("点伤害。"));
		this->state();
		this->winvalue();
		if (win)
		{
			this->state();
			return;
		}
		this->bossjineng();
		this->state();
		this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
		this->disbuff();
	}
	else
	{
		ui.warBrowser->append(QString::fromLocal8Bit("你的气力不足，技能施放失败。"));
	}
}



void war::onbtnZhengyang()
{
	if (Pneuma >= 800)
	{
		Pneuma -= 800;
		this->buffvalue();
		heroatk = m_Attack * 3;
		BossHP -= heroatk;
		ui.warBrowser->append(QString::fromLocal8Bit("你使出一套正阳剑法，对敌人造成了") + QString::number(heroatk) + QString::fromLocal8Bit("点伤害。"));
		this->state();
		this->winvalue();
		if (win)
		{
			this->state();
			return;
		}
		this->bossjineng();
		this->state();
		this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
		this->disbuff();
	}
	else
	{
		ui.warBrowser->append(QString::fromLocal8Bit("你的气力不足，技能施放失败。"));
	}
}



void war::onbtnQinglong()
{
	if (Pneuma >= Pneuma_max/2&&Blood<=Blood_max/4)
	{
		Pneuma =0;
		this->buffvalue();
		heroatk = m_Attack * 5;
		BossHP -= heroatk;
		ui.warBrowser->append(QString::fromLocal8Bit("你拼尽全力使出青龙剑法，对敌人造成了") + QString::number(heroatk) + QString::fromLocal8Bit("点伤害！"));
		this->state();
		this->winvalue();
		if (win)
		{
			this->state();
			return;
		}
		this->bossjineng();
		this->state();
		this->losevalue();
		if (lose)
		{
			this->state();
			return;
		}
		this->disbuff();
	}
	else
	{
		ui.warBrowser->append(QString::fromLocal8Bit("你未达成施放条件（气力高于50%，血量低于25%），技能施放失败。"));
	}
}

war::~war()
{
}
