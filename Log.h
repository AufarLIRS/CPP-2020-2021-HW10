#ifndef LOG_H
#define LOG_H

#include <fstream>

class Log
{
public:
    static Log& getInstance();
    void log(const std::string str);
    Log(const Log&) = delete;
    void operator=(const Log&) = delete;
    ~Log();

private:
  Log();
  static Log& instance_;
  std::fstream file_;
};


#endif // LOG_H
