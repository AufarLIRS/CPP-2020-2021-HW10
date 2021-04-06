#ifndef LOGFILE_H
#define LOGFILE_H
#include <fstream>

class Logfile
{
public:
  static Logfile& getInstance();
  void log(const std::string);
  Logfile(const Logfile&) = delete;
  void operator=(const Logfile&) = delete;
  ~Logfile();

private:
  Logfile();
  static Logfile* instance_;
  std::fstream file;
};

#endif  // LOGFILE_H
