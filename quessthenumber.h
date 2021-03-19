#ifndef QUESSTHENUMBER_H
#define QUESSTHENUMBER_H
#include <string>

class QuessTheNumber
{
private:
public:
  static std::string passcode;
  static int iterator;
  QuessTheNumber();
  static bool Quess(char number);
  static void Reset();
};

#endif  // QUESSTHENUMBER_H
