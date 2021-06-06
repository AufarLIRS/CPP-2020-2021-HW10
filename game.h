#ifndef GAME_H
#define GAME_H
#include <string>

class Game
{
public:
    Game();
    static std::string password;
    static int iterator;
    static bool IsRightNumber(char number);
    static void Reset();
};

#endif // GAME_H
