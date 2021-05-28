#include "LogFile.h"

LogFile::LogFile()
{
  this->logFile = std::ofstream();
  logFile.open("d:\\log.txt");
}

LogFile::~LogFile()
{
  this->logFile.close();
}

void LogFile::write(std::string txt)
{
  this->logFile << txt;
}

LogFile& LogFile::getInstance()
{
  static LogFile instance;
  return instance;
}
