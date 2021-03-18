#include "loger.h"
#include <fstream>
#include <QCoreApplication>

Loger::Loger()
{
  // std::string path = QCoreApplication::applicationFilePath().toStdString() + "/log.txt";
  // std::replace(path.begin(), path.end(), '/', '\\');
  fileStream.open("log.txt", std::ios::app);
}

void Loger::Log(std::string logString)
{
  fileStream << logString << std::endl;
}

Loger::~Loger()
{
  this->Log("End!");
  fileStream.close();
}
