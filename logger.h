#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <fstream>
#include <QDebug>
#include "QFileInfo"

class Log
{
  QFile file;

  Log();
  ~Log();

public:
  static Log& GetInstance();
  void Append(QByteArray string);

  Log(const Log&) = delete;
  Log& operator=(const Log&) = delete;
  Log(Log&&) = delete;
  Log& operator=(Log&&) = delete;
};

#endif  // LOGGER_H
