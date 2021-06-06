#include "log_file.h"
#include "QDebug"
#include <fstream>

log_file::log_file()
{
  file.open("log_file.txt", std::fstream::app);
  if (file.is_open())
    qDebug() << "recording";
}
void log_file::log(const std::string text)
{
  this->file << text << std::endl;
}
log_file& log_file::getInstance()
{
  static log_file instance;
  return instance;
}
log_file::~log_file()
{
  qDebug() << "Close the record";
  this->file.close();
}
