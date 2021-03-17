#ifndef LOGFILE_H
#define LOGFILE_H
#include <fstream>

class LogFile
{
public:
  static LogFile& getInstance();
  void log(const std::string);
  LogFile(const LogFile&) = delete;
  void operator=(const LogFile&) = delete;
  ~LogFile();

private:
  LogFile();
  static LogFile* instance_;
  std::fstream file;
};

#endif  // LOGFILE_H
