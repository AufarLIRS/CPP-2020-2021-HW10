#include "quessthenumber.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "logfile.h"
#include <vector>

QuessTheNumber::QuessTheNumber()
{
}
int QuessTheNumber::iterator = 0;
std::string QuessTheNumber::passcode = "3421";

bool QuessTheNumber::Quess(char number)
{
  std::string s = "кнопка ";
  if (iterator == 4)
  {
    LogFile::getInstance()->log("победа!");
    return true;
  }
  if (passcode[iterator] == number)
  {
    s += "правильная ";
    s += number;
    LogFile::getInstance()->log(s);
    iterator++;
    return true;
  }
  else
  {
    s += "неправильная ";
    s += number;
    LogFile::getInstance()->log(s);
    return false;
  }
}
void QuessTheNumber::Reset()
{
  LogFile::getInstance()->log("рестарт");
  iterator = 0;
}
