#pragma once

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
	void openBMP(void);
	void closeBMP(void);
	void saveBMP(void);

	void readBMP(void);
	void writeBMP(QString);

signals:
	void sendPixmap(QPixmap);
	void readMessage(QString);
	void setCharactersAvailable(QString);

private:
	Ui::SteganographyGUIClass ui;
	Steganography s;
	int maxBits;
	int height;
	int width;
};
