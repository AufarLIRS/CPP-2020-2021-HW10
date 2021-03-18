#ifndef LOGER_H
#define LOGER_H
#include <fstream>

class Loger
{
  Loger();
  std::ofstream fileStream;
  Loger(const Loger&) = delete;
  Loger& operator=(Loger&) = delete;

public:
  void Log(std::string logString);
  ~Loger();
  friend class LogerSingleton;
};

#endif  // LOGER_H
