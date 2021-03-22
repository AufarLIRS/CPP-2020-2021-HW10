#include "logger.h"

Log::Log()
{
  file.setFileName("Logger.txt");
  file.open(QIODevice::WriteOnly);
}

Log::~Log()
{
  file.close();
}

Log& Log::GetInstance()
{
  static Log log;
  return log;
}

void Log::Append(QByteArray string)
{
  file.write(string + "\n");
}
