#include "Tip.h"

Tip::Tip(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Tip::Tip(QString str)
{
	ui.setupUi(this);

	ui.lblText->setText(str);
	connect(ui.btnAC, SIGNAL(clicked()), this, SLOT(OnbtnAC()));
	connect(ui.btnRE, SIGNAL(clicked()), this, SLOT(OnbtnRE()));
}

Tip::~Tip()
{
}

int Tip::OnbtnAC()
{
	accept();
	return 0;
}

int Tip::OnbtnRE()
{
	reject();
	return 0;
}
