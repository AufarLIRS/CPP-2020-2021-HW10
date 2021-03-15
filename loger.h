#ifndef LOGER_H
#define LOGER_H

#include "QString"

class Loger
{
  Loger();
  Loger(const Loger&) = delete;
  Loger& operator=(Loger&) = delete;
public:
  void Log(QString logString);
};

#endif  // LOGER_H
