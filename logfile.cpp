#include "logfile.h"
#include "QDebug"
LogFile::LogFile()
{
  std::fstream file_;
  file.open("log.txt", std::fstream::app);
  if (file.is_open())
    qDebug() << "запись";
}
void LogFile::log(const std::string text)
{
  this->file << text << std::endl;
}
LogFile& LogFile::getInstance()
{
  static LogFile instance;
  return &instance;
}
LogFile::~LogFile()
{
  qDebug() << "закрыть запись";
  this->file.close();
}
