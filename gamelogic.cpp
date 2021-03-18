#include "gamelogic.h"
#include <algorithm>
#include "gamestate.h"
GameLogic::GameLogic()
{
  this->roolOrder = { 1, 2, 3, 4 };
  this->userInputOrder = { 0, 0, 0, 0 };
}

GameLogic::GameLogic(int first, int second, int third, int fourth)
{
  roolOrder = { first, second, third, fourth };
  userInputOrder = { 0, 0, 0, 0 };
  state = GameState::Play;
}

GameState GameLogic::GetStatusFromUserStep(int inputData)
{
  int indexOfLastZeroInInputOrder =
      std::distance(userInputOrder.begin(), std::find(userInputOrder.begin(), userInputOrder.end(), 0));
  userInputOrder[indexOfLastZeroInInputOrder] = inputData;
  if (roolOrder[indexOfLastZeroInInputOrder] == inputData)
  {
    if (indexOfLastZeroInInputOrder == (int)roolOrder.size() - 1)
    {
      state = GameState::Win;
    }
  }
  else
  {
    state = GameState::Losing;
  }
  return state;
}
