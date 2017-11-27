#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SteganographyGUI.h"

class SteganographyGUI : public QMainWindow
{
	Q_OBJECT

public:
	SteganographyGUI(QWidget *parent = Q_NULLPTR);

public slots:
	void openBMP(void);
	void closeBMP(void);

signals:
	void sendPixmap(QPixmap);

private:
	Ui::SteganographyGUIClass ui;
};
