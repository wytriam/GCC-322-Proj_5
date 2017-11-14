#include "HW5_Starter.h"
#include <QFileDialog>
#include <QString>

HW5_Starter::HW5_Starter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void HW5_Starter::loadFile()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Images (*.bmp)"));

	emit sendPixmap(QPixmap(filename));
}