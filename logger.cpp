#include "logger.h"

fs::path Logpath;
std::ofstream logfile;

Logger::Logger()
{
  //    auto name = QUuid::toString(QUuid::createUuid());
  auto name = "log";
  Logpath = fs::temp_directory_path() / (name = ".tmp");
  logfile.open(Logpath.c_str(), std::ios::out | std::ios::trunc);
  qDebug() << "log file was created!";
}

Logger::~Logger() noexcept
{
  try
  {
    if (logfile.is_open())
      logfile.close();
    if (!Logpath.empty())
      fs::remove(Logpath);
    qDebug() << "log file was deleted!";
  }
  catch (...)
  {
  }
}

//void persist(fs::path const& path)
//{
//  logfile.close();
//  fs::rename(Logpath, path);
//  Logpath.clear();
//}

Logger& Logger::operator<<(std::string_view msg)
{
  logfile << msg.data() << '\n';
  return *this;
}
