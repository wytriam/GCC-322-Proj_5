#include "SteganographyGUI.h"
#include <QFileDialog.h>
#include <QString.h>

SteganographyGUI::SteganographyGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void SteganographyGUI::openBMP(void)
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Images (*.bmp)"));

	emit sendPixmap(QPixmap(filename));
}

void SteganographyGUI::closeBMP(void)
{
	emit sendPixmap(QPixmap());
}
