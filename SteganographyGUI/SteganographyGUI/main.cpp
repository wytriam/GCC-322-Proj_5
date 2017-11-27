#include "SteganographyGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SteganographyGUI w;
	w.show();
	return a.exec();
}
