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
	void updateCharRemainingSlot(QString);

signals:
	void sendPixmap(QPixmap);
	void setMessageBox(QString);
	void setCharactersAvailable(QString);
	void updateCharRemaining(QString);
	void toggleEnabled(bool);

private:
	Ui::SteganographyGUIClass ui;
	Steganography s;
	int maxBits;
	int height;
	int width;
};
