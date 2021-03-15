#ifndef GAMEGEN_H
#define GAMEGEN_H

#include <QDebug>
#include <QApplication>
#include <QProcess>

#include <algorithm>
#include <random>
#include <logger.h>
#include <vector>

class Game
{
  static std::vector<int> game_numbers;
  static int now;

public:
  static Logger log_;
  static void RandomNumbers();
  static bool CheckNumbers(int button);
  static bool CheckResult();
  static void Reset();
};

#endif  // GAMEGEN_H
