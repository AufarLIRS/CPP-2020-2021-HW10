#include "game.h"
#include "log_file.h"

Game::Game(){

};

std::string Game::password = "1234";
int Game::iterator = 0;
bool Game::IsRightNumber(char number)
{
    std::string s = "Button ";
    if (iterator == 4)
    {
        log_file::getInstance().log("Victory!");
        return true;
    }
    if (password[iterator] == number)
    {
        s += number;
        s += " is Right";
        log_file::getInstance().log(s);
        iterator++;
        return true;
    }
    else
    {
        s += number;
        s += " is Wrong";
        log_file::getInstance().log(s);
        return false;
    }
};

void Game::Reset()
{
    log_file::getInstance().log("Restart");
    iterator = 0;
};
