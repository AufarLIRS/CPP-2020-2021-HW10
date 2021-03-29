#include "game.h"

Game::Game()
{
    this->roolOrder = {1, 2, 3, 4};
    this->userInputOrder = {0, 0, 0, 0};
}

Game::Game(int first, int second, int third, int fourth)
{
    roolOrder = {first, second, third, fourth};
    userInputOrder = {0, 0, 0, 0};
}
