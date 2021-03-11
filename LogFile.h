#ifndef LOGFILE_H
#define LOGFILE_H
#include <QFile>

class LogFile
{
private:
  LogFile()
  {
  }
  LogFile(const LogFile&);
  LogFile& operator=(LogFile&);

public:
  static QFile& getLogFile()
  {
    static QFile logFile("d:\\log.txt");
    return logFile;
  }
};

#endif  // LOGFILE_H
