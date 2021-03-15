#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <array>

class GameLogic
{
  /*int firstInOrder;
  int secondInOrder;
  int thirdInOrder;
  int fourthInOrder;*/
  std::array<int, 4> roolOrder;
  std::array<int, 4> userInputOrder;
  GameLogic();

public:
  GameLogic(int first, int second, int third, int fourth);
  bool isCorrectInput(int inputData);
};

#endif  // GAMELOGIC_H
