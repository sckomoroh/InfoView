#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <QMessageBox>

#include "ILogClient.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QString path = QCoreApplication::applicationDirPath() + "/info-view.log";
	string strPath = path.toStdString();
	char* sPath = const_cast<char*>(strPath.c_str());

	ILogClient* logClient = getLogClientInstance();
	logClient->initLogger(sPath);
	logClient->Info("Start new session");

	MainWindow w;
	w.show();

	int exit_code = a.exec();

	logClient->Info("End session");

	return exit_code;
}
