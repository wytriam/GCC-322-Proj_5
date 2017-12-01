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
	width;
	height;
	unsigned char* data = BMP_Handler::loadBMP(filename.toStdString().data(), width, height);

	// determine the maximum number of bits that can be stored in this image
	maxBits = ((width * 3) * height) / 8;

	// Send the pixel array to the Steganography class
	s = Steganography(data, maxBits);

	std::string message = "Characters Available: " + std::to_string(maxBits);

	emit setCharactersAvailable(QString(message.data()));
}

void SteganographyGUI::closeBMP(void)
{
	emit sendPixmap(QPixmap());
	emit setCharactersAvailable(QString("Characters Available:"));
}

void SteganographyGUI::readBMP(void)
{
	QString emitVal = QString(s.read().data());
	
	emit readMessage(emitVal);
}

void SteganographyGUI::writeBMP(QString message)
{
	s.write(message.toStdString());
}

void SteganographyGUI::saveBMP(void)
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), QString(), tr("Images (*.bmp)"));
	BMP_Handler::saveBMP(filename.toStdString().data(), s.getData(), height, width);
}
