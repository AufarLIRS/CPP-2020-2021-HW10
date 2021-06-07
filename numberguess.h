#ifndef NUMBER_GUESSING_H
#define NUMBER_GUESSING_H
#include <string>

class Number_Guessing
{
public:
  Number_Guessing();
  static std::string password;
  static int iterator;
  static bool IsRightNumber(char number);
  static void Reset();
};

#endif  // NUMBER_GUESSING_H
