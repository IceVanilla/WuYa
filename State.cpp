#include "State.h"

extern int jian;
extern int guan;
extern int jia;
extern int xue;
extern int Blood;
extern int Blood_max;
extern int Pneuma;
extern int Pneuma_max;
extern int Attack;
extern int Defense;
extern int Sister_state;
extern int Schedule;

State::State(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	if (Schedule <= 13)
	{
		ui.lableqinglong->hide();
		ui.labelqinglong2->hide();
	}
	QString str_hp = QString::number(Blood) + QString::fromLocal8Bit("/") + QString::number(Blood_max);
	QString str_sp = QString::number(Pneuma) + QString::fromLocal8Bit("/") + QString::number(Pneuma_max);
	ui.HP->setText(str_hp);
	ui.SP->setText(str_sp);
	ui.Attack->setText(QString::number(Attack));
	ui.Defense->setText(QString::number(Defense));
	if (jian == 1)
	{
		ui.jian->setText(QString::fromLocal8Bit("ÕıÑô½£"));
	}
	else ui.jian->setText(QString::fromLocal8Bit("ÇàÁú½£"));
	if (jia == 1)
	{
		ui.jia->setText(QString::fromLocal8Bit("»¤ĞÄ¾µ"));
	}
	else ui.jia->setText(QString::fromLocal8Bit("ĞşÎäÖØ¼×"));
	if (xue == 1)
	{
		ui.xue->setText(QString::fromLocal8Bit("ÕıÑôÑ¥"));
	}
	else ui.xue->setText(QString::fromLocal8Bit("°×»¢Ñ¥"));
	if (guan == 1)
	{
		ui.guan->setText(QString::fromLocal8Bit("ÕıÑô¹Ú"));
	}
	else ui.guan->setText(QString::fromLocal8Bit("ÖìÈ¸¹Ú"));
	if (Sister_state == 1)
	{
		ui.sisterstate->setText(QString::fromLocal8Bit("±ôËÀ"));
	}
	if (Sister_state == 2)
	{
		ui.sisterstate->setText(QString::fromLocal8Bit("ÖĞ¶¾"));
	}
	if (Sister_state == 3)
	{
		ui.sisterstate->setText(QString::fromLocal8Bit("È¬Óú"));
	}
	if (Sister_state == 0)
	{
		ui.sisterstate->setText(QString::fromLocal8Bit("ËÀÍö"));
	}
}

State::~State()
{
}
