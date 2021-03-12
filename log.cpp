#include "log.h"

Log::Log()
{
    std::fstream file;
    file.open("log", std::fstream::app);
    this->file_ = std::move(file);
}

Log* Log::getInstance()
{
    static Log instance;
    return &instance;
}

void Log::log(const std::string s)
{
    this->file_ << s << std::endl;
}

Log::~Log()
{
    this->file_.close();
}
