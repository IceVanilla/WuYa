#include "Xuanwuku.h"
#include "war.h"

Xuanwuku::Xuanwuku(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnXW, SIGNAL(clicked()), this, SLOT(OpenXW()));

	extern int Schedule;
	if (Schedule != 10)
	{
		ui.btnXW->hide();
	}
}

Xuanwuku::~Xuanwuku()
{
}

void Xuanwuku::mousePressEvent(QMouseEvent *event)
{
	return;
}

int Xuanwuku::OpenXW()
{
	extern bool END;
	war wr;
	int ret = wr.exec();
	if (ret == QDialog::Accepted)
	{
		ui.btnXW->hide();
	}
	if (!ret && END)
	{
		this->close();
	}
	return 0;
}
