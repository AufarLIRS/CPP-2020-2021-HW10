#include "singleton.h"

 Singleton* Singleton::getInstance()
    {
            if(!p_instance)
                p_instance = new Singleton();
            return p_instance;

        }
Singleton * Singleton::p_instance;
