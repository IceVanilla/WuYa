#include "Baihuxue.h"
#include "war.h"

Baihuxue::Baihuxue(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btnBH, SIGNAL(clicked()), this, SLOT(OpenBH()));

	extern int Schedule;
	if (Schedule != 11)
	{
		ui.btnBH->hide();
	}
}

Baihuxue::~Baihuxue()
{
}

void Baihuxue::mousePressEvent(QMouseEvent *event)
{
	return;
}

int Baihuxue::OpenBH()
{
	extern bool END;
	war wr;
	int ret = wr.exec();
	if (ret == QDialog::Accepted)
	{
		ui.btnBH->hide();
	}
	if (!ret && END)
	{
		this->close();
	}
	return 0;
}
