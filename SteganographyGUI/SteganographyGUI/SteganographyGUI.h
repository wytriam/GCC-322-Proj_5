#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SteganographyGUI.h"

class SteganographyGUI : public QMainWindow
{
	Q_OBJECT

public:
	SteganographyGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::SteganographyGUIClass ui;
};
