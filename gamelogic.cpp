#include "gamelogic.h"

GameLogic::GameLogic()
{
  this->roolOrder = { 1, 2, 3, 4 };
  this->userInputOrder = { 0, 0, 0, 0 };
}

GameLogic::GameLogic(int first, int second, int third, int fourth)
{
  this->roolOrder[0] = first;
  this->roolOrder[1] = second;
  this->roolOrder[2] = third;
  this->roolOrder[3] = fourth;
}

bool GameLogic::isCorrectInput(int inputData)
{
  //Использовать find
}
