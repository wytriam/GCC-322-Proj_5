#pragma once

/*
	This is the class that glues all the other classes together. The GUI window manages all the other widgets
	and includes a reference to the Steganography class. 
*/

#include <BMP_Handler.h>
#include <QtWidgets/QMainWindow>
#include "ui_SteganographyGUI.h"
#include "Steganography.h"
#include <string>

class SteganographyGUI : public QMainWindow
{
	Q_OBJECT

public:
	SteganographyGUI(QWidget *parent = Q_NULLPTR);

public slots:
	// open a BMP
	void openBMP(void);
	// close the BMP, reset everything
	void closeBMP(void);
	// save the current, open BMP
	void saveBMP(void);
	// read any hidden messages contained in the BMP
	void readBMP(void);
	// use the steganography class to write a hidden message in the BMP
	void writeBMP(QString);
	// update the display for remaining available characters
	void updateCharRemainingSlot(QString);

signals:
	// set the BMP picture
	void sendPixmap(QPixmap);
	// set the message textbox
	void setMessageBox(QString);
	// set the total number of characters available display
	void setCharactersAvailable(QString);
	// set the total number of characters remaining display
	void updateCharRemaining(QString);
	// turn elements on/off
	void toggleEnabled(bool);

private:
	Ui::SteganographyGUIClass ui;
	// A reference to the steganography class. Minimizes passing data back and forth
	Steganography s;
	// The maximum number of bits the current open image can store
	int maxBits;
	// The height of the current image
	int height;
	// The width of the current image
	int width;
};
