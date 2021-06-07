#include "numberguess.h"

Number_Guessing::Number_Guessing(){

};

std::string Number_Guessing::password = "4132";
int Number_Guessing::iterator = 0;
bool Number_Guessing::IsRightNumber(char number)
{
  std::string s = "Button ";
  if (iterator == 4)
  {
    return true;
  }
  if (password[iterator] == number)
  {
    s += number;
    s += " is Right";
    Logfile::getInstance().log(s);
    iterator++;
    return true;
  }
  else
  {
    s += number;
    s += " is Wrong";
    Logfile::getInstance().log(s);
    return false;
  }
};

void Number_Guessing::Reset()
{
  iterator = 0;
};
