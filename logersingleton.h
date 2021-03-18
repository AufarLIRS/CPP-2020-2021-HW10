#ifndef LOGERSINGLETON_H
#define LOGERSINGLETON_H

#include "loger.h"
class LogerSingleton
{
public:
  LogerSingleton();
  static Loger& GetInstance();
};

#endif  // LOGERSINGLETON_H
