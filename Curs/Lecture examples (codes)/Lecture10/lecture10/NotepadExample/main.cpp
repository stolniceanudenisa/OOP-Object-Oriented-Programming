#include "notepad.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Notepad w;
	w.show();
	return a.exec();
}
