#include "Zhuquechao.h"
#include "war.h"

Zhuquechao::Zhuquechao(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnZQ, SIGNAL(clicked()), this, SLOT(OpenZQ()));


	extern int Schedule;
	if (Schedule != 12)
	{
		ui.btnZQ->hide();
	}
}

Zhuquechao::~Zhuquechao()
{
}

void Zhuquechao::mousePressEvent(QMouseEvent *event)
{
	return;
}

int Zhuquechao::OpenZQ()
{
	extern bool END;
	war wr;
	int ret = wr.exec();
	if (ret == QDialog::Accepted)
	{
		ui.btnZQ->hide();
	}
	if (!ret && END)
	{
		this->close();
	}
	return 0;
}
