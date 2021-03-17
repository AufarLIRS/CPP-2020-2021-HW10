#include "log.h"

Log::Log()
{
  this->file_ = std::fstream("log", std::fstream::app);
}

Log& Log::getInstance()
{
  static Log instance;
  return instance;
}

void Log::log(const std::string s)
{
  this->file_ << s << std::endl;
}

Log::~Log()
{
  this->file_.close();
}
