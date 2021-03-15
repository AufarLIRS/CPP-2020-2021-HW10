#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QUuid>
#include <filesystem>
#include <fstream>
#include <QDebug>

namespace fs = std::filesystem;

class Logger
{
  fs::path Logpath;
  std::ofstream logfile;

public:
  Logger();
  ~Logger() noexcept;

  void persist(fs::path const& path);
  Logger& operator<<(std::string_view msg);

  Logger(Logger const&) = delete;
  Logger& operator=(Logger const&) = delete;
};

#endif  // LOGGER_H
