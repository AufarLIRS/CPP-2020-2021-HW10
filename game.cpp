#include "game.h"

std::vector<int> Game::game_numbers;
int Game::now;

void Game::Reset()
{
  game_numbers.clear();
  RandomNumbers();
}

bool Game::CheckNumbers(int button)
{
  return (button == game_numbers[now]);
}

void Game::RandomNumbers()
{
  now = 0;
  game_numbers = std::vector<int>{ 1, 2, 3, 4 };

  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(game_numbers), std::end(game_numbers), rng);

  QByteArray nums = "";
  for (auto n : game_numbers)
  {
    nums += n;
  }

  qDebug() << "Последовательность:" << game_numbers[now];
}

bool Game::CheckResult()
{
  if (now == 3)
  {
    return true;
  }
  else
  {
    now++;
    return false;
  }
}
