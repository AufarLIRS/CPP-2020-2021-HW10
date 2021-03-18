#ifndef LOGFILE_H
#define LOGFILE_H
#include <fstream>

class LogFile
{
private:
  std::ofstream logFile;  // logs
  LogFile();              // constructor

public:
  ~LogFile();                                   // destructor
  LogFile(LogFile const&) = delete;             // copy
  LogFile& operator=(LogFile const&) = delete;  //=
  void write(std::string);                      // write into log
  static LogFile& getInstance();
};

#endif  // LOGFILE_H
