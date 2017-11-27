#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Steganography.h"

class Steganography : public QMainWindow
{
	Q_OBJECT

public:
	Steganography(QWidget *parent = Q_NULLPTR);

private:
	Ui::SteganographyClass ui;
};
