#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HW5_Starter.h"

class HW5_Starter : public QMainWindow
{
	Q_OBJECT

public:
	HW5_Starter(QWidget *parent = Q_NULLPTR);

public slots: 
	void loadFile(void);

signals:
	void sendPixmap(QPixmap);

private:
	Ui::HW5_StarterClass ui;
};
