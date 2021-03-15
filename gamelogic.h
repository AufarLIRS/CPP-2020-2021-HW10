#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <array>
#include "gamestate.h"
class GameLogic
{
  std::array<int, 4> roolOrder;
  std::array<int, 4> userInputOrder;
  GameState state;

public:
  GameLogic();
  GameLogic(int first, int second, int third, int fourth);

  GameState GetStatusFromUserStep(int inputData);
};

#endif  // GAMELOGIC_H
