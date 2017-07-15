#include "Menu.h"
#include <QtWidgets/QApplication>
#include <string>

using namespace std;

bool END = false;
bool END_h = false;
bool END_b = false;
int Schedule = 0;
int Money = 5000;
int Attack = 2000;
int Defense = 500;
int Blood_max = 6000;
int Blood = 6000;
int Pneuma_max = 2000;
int Pneuma = 2000;
int Sister_state = 1;
static QString Hero = QString::fromLocal8Bit("Ω≠¡Í");
static QString Sister = QString::fromLocal8Bit(" ¶√√");
static QString Boss = QString::fromLatin1("»›…Ê");
bool Key_cs_ms = false;
bool Drug_01 = false;
bool Drug_02 = false;
bool Drug_03 = false;
bool Map_xw = false;
bool Map_bh = false;
bool Map_zq = false;
bool Map_ql = false;
bool qinglongjian = 0;
bool baihuxue = 0;
bool zhuqueguan = 0;
bool xuanwuzhongjia = 0;
int jian = 1;
int guan = 1;
int jia = 1;
int xue = 1;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Menu w;
	w.show();
	return a.exec();
}
