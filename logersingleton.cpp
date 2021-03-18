#include "logersingleton.h"

LogerSingleton::LogerSingleton()
{
}

Loger& LogerSingleton::GetInstance()
{
  static Loger instance;
  return instance;
}
