#ifndef LOG_FILE_H
#define LOG_FILE_H
#include <fstream>

class log_file
{
public:
    static log_file& getInstance();
    void log(const std::string);
    log_file(const log_file&) = delete;
    void operator=(const log_file&) = delete;
    ~log_file();

private:
    log_file();
    static log_file* instance_;
    std::fstream file;
};

#endif // LOG_FILE_H
