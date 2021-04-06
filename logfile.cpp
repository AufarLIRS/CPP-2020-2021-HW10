#include "logfile.h"
#include "QDebug"
#include <fstream>

Logfile::Logfile()
{
  file.open("log.txt", std::fstream::app);
  if (file.is_open())
    qDebug() << "recording";
}
void Logfile::log(const std::string text)
{
  this->file << text << std::endl;
}
Logfile& Logfile::getInstance()
{
  static LogFile instance;
  return &instance;
}
Logfile::~LogFile()
{
  qDebug() << "Close the record";
  this->file.close();
}
