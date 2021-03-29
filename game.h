#ifndef GAME_H
#define GAME_H

#include <array>
#include "gameResult.h"

class Game
{
    std::array<int, 4> roolOrder;
    std::array<int, 4> userInputOrder;
    GameResult state;

public:
    Game();
    Game(int first, int second, int third, int fourth);

    GameResult getGameResult(int inputData);
};

#endif // GAME_H
