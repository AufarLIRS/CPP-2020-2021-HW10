#include "mainwindow.h"
#include "logfile.h"
#include <QApplication>

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  LogFile::getInstance()->log("тест");
  MainWindow w;
  w.show();
  return a.exec();
}
