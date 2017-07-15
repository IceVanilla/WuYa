#include "Worldmap.h"
#include "Cangshan.h"
#include "Xuanwuku.h"
#include "Baihuxue.h"
#include "Qinglongtan.h"
#include "Zhuquechao.h"
#include "Yingshan.h"

Worldmap::Worldmap(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnXuanwu, SIGNAL(clicked()), this, SLOT(OpenXuanwu()));
	connect(ui.btnBaihu, SIGNAL(clicked()), this, SLOT(OpenBaihu()));
	connect(ui.btnZhuque, SIGNAL(clicked()), this, SLOT(OpenZhuque()));
	connect(ui.btnQinglong, SIGNAL(clicked()), this, SLOT(OpenQinglong()));
	connect(ui.btnCangshan, SIGNAL(clicked()), this, SLOT(OpenCangshan()));
	connect(ui.btnYingshan, SIGNAL(clicked()), this, SLOT(OpenYingshan()));
	connect(ui.btnChangan, SIGNAL(clicked()), this, SLOT(OpenChangan()));

	extern bool Map_xw;
	extern bool Map_bh;
	extern bool Map_zq;
	extern bool Map_ql;
	ui.btnBaihu->hide();
	ui.btnXuanwu->hide();
	ui.btnQinglong->hide();
	ui.btnZhuque->hide();
	ui.btnYingshan->setEnabled(false);
	if (Map_xw)
	{
		ui.btnXuanwu->show();
	}
	if (Map_bh)
	{
		ui.btnBaihu->show();
	}
	if (Map_zq)
	{
		ui.btnZhuque->show();
	}
	if (Map_ql)
	{
		ui.btnQinglong->show();
	}

	extern int Schedule;
	if (Schedule == 4)
	{
		ui.btnChangan->setEnabled(false);
	}
	if (Schedule >= 6)
	{
		ui.btnCangshan->setEnabled(false);
	}
	if (Schedule == 15)
	{
		ui.btnYingshan->setEnabled(true);
	}
	if (Schedule == 17)
	{
		OpenCangshan();
	}
}

Worldmap::~Worldmap()
{
}

int Worldmap::OpenXuanwu()
{
	Xuanwuku xw;
	xw.exec();
	extern bool Map_bh;
	if (Map_bh)
	{
		ui.btnBaihu->show();
	}
	extern bool END;
	extern bool END_b;
	extern bool END_h;
	if (END || END_b || END_h)
	{
		this->close();
	}
	return 0;
}

int Worldmap::OpenBaihu()
{
	Baihuxue bh;
	bh.exec();
	extern bool Map_zq;
	if (Map_zq)
	{
		ui.btnZhuque->show();
	}
	extern bool END;
	extern bool END_b;
	extern bool END_h;
	if (END || END_b || END_h)
	{
		this->close();
	}
	return 0;
}

int Worldmap::OpenZhuque()
{
	Zhuquechao zq;
	zq.exec();
	extern bool Map_ql;
	if (Map_ql)
	{
		ui.btnQinglong->show();
	}
	extern bool END;
	extern bool END_b;
	extern bool END_h;
	if (END || END_b || END_h)
	{
		this->close();
	}
	return 0;
}

int Worldmap::OpenQinglong()
{
	Qinglongtan ql;
	ql.exec();
	extern bool END;
	extern bool END_b;
	extern bool END_h;
	if (END || END_b || END_h)
	{
		this->close();
	}
	return 0;
}

int Worldmap::OpenCangshan()
{
	Cangshan cs;
	cs.exec();
	extern int Schedule;
	if (Schedule == 6)
	{
		ui.btnXuanwu->show();
		ui.btnCangshan->setEnabled(false);
		ui.btnXuanwu->setEnabled(false);
		ui.btnChangan->setEnabled(true);
	}
	if (Schedule == 17)
	{
		this->close();
	}
	extern bool END;
	extern bool END_b;
	extern bool END_h;
	if (END || END_b || END_h)
	{
		this->close();
	}
	return 0;
}

int Worldmap::OpenYingshan()
{
	Yingshan ys;
	ys.exec();
	extern bool END;
	extern bool END_b;
	extern bool END_h;
	if (END || END_b || END_h)
	{
		this->close();
	}
	return 0;
}

int Worldmap::OpenChangan()
{
	accept();
	return 0;
}
