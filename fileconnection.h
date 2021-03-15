#ifndef FILECONNECTION_H
#define FILECONNECTION_H

#include "loger.h"
class LogerSingleton
{
public:
    LogerSingleton();
    static Loger* GetLogerInstance();
};

#endif // FILECONNECTION_H
