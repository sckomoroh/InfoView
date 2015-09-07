#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	MainWindow w;
	w.show();

	int exit_code = a.exec();
	return exit_code;
}
