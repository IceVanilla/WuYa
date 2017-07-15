#include "Qinglongtan.h"
#include "war.h"

Qinglongtan::Qinglongtan(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnQL, SIGNAL(clicked()), this, SLOT(OpenQL()));

	extern int Schedule;
	if (Schedule != 13)
	{
		ui.btnQL->hide();
	}
}

Qinglongtan::~Qinglongtan()
{
}

void Qinglongtan::mousePressEvent(QMouseEvent *event)
{
	return;
}

int Qinglongtan::OpenQL()
{
	extern bool END;
	war wr;
	int ret = wr.exec();
	if (ret == QDialog::Accepted)
	{
		ui.btnQL->hide();
	}
	if (!ret && END)
	{
		this->close();
	}
	return 0;
}
