#include "mainwindow.h"
#include <QApplication>
#include <QWidget>


int main(int argc, char *argv[])
{
//	Q_IMPORT_PLUGIN("D:\\QtVersion\\Qt5.13_Build_X64\\Qt5.13_X64\\plugins");
//	QCoreApplication::setLibraryPaths()
//	QStringList list;
//	list << QString("D:\\QtVersion\\Qt5.13_Build_X64\\Qt5.13_X64\\plugins");
//	QCoreApplication::setLibraryPaths(list);

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
