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
	int width;
	int height;
	unsigned char* data = BMP_Handler::loadBMP(filename.toStdString().c_str(), width, height);

	// determine the maximum number of bits that can be stored in this image
	int maxBits = (width * 3) * height;

	// Send the pixel array to the Steganography class
	s = Steganography(data, maxBits);
}

void SteganographyGUI::closeBMP(void)
{
	emit sendPixmap(QPixmap());
}

void SteganographyGUI::readBMP(void)
{
	QString emitVal = QString(s.read().c_str());
	
	emit readMessage(emitVal);
}

void SteganographyGUI::writeBMP()
{

}
