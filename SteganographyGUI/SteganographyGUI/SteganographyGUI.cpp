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
	// Select the correct file
	QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Images (*.bmp)"));

	// Send the file to the label to be displayed
	emit sendPixmap(QPixmap(filename));

	// Use the DLL to extract the bool array 

	// determine the maximum number of bits that can be stored in this image

	// Send the pixel array to the Steganography class
}

void SteganographyGUI::closeBMP(void)
{
	emit sendPixmap(QPixmap());
}

void SteganographyGUI::readBMP(void)
{

}

void SteganographyGUI::writeBMP(std::string message)
{

}
