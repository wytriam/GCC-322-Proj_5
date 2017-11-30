#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SteganographyGUI.h"
#include <BMP_Handler.h>
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

	void readBMP(void);
	void writeBMP(std::string);

signals:
	void sendPixmap(QPixmap);

private:
	Ui::SteganographyGUIClass ui;
};
