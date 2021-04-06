#include "number_guessing.h"
#include "logfile.h"

Number_Guessing::Number_Guessing(){

};

std::string Number_Guessing::password = "4132";
int Number_Guessing::iterator = 0;
bool Number_Guessing::IsRightNumber(char number)
{
  std::string s = "кнопка ";
  if (iterator == 4)
  {
    LogFile::getInstance()->log("You Win!");
    return true;
  }
  if (password[iterator] == number)
  {
    s += number;
    s += "is Right";
    LogFile::getInstance()->log(s);
    iterator++;
    return true;
  }
  else
  {
    s += number;
    s += "is Wrong";
    LogFile::getInstance()->log(s);
    return false;
  }
};

void Number_Guessing::Reset()
{
  LogFile::getInstance()->log("Restart");
  iterator = 0;
};
