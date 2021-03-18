#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "gamelogic.h"
#include "gamestate.h"
#include "logersingleton.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  game = GameLogic(4, 3, 2, 1);
  logerAcces.GetInstance().Log("New game!");
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{
  if (!ui->checkBox_1->isChecked())
  {
    logerAcces.GetInstance().Log("1");
    GameState state = game.GetStatusFromUserStep(1);
    Update(state, ui->checkBox_1);
  }
}

void MainWindow::on_pushButton_2_clicked()
{
  if (!ui->checkBox_2->isChecked())
  {
    logerAcces.GetInstance().Log("2");
    GameState state = game.GetStatusFromUserStep(2);
    Update(state, ui->checkBox_2);
  }
}

void MainWindow::on_pushButton_3_clicked()
{
  if (!ui->checkBox_3->isChecked())
  {
    logerAcces.GetInstance().Log("3");
    GameState state = game.GetStatusFromUserStep(3);
    Update(state, ui->checkBox_3);
  }
}

void MainWindow::on_pushButton_4_clicked()
{
  if (!ui->checkBox_4->isChecked())
  {
    logerAcces.GetInstance().Log("4");
    GameState state = game.GetStatusFromUserStep(4);
    Update(state, ui->checkBox_4);
  }
}

void MainWindow::on_resetButton_clicked()
{
  ResetGame();
}

//Начинает новую игру
void MainWindow::ResetGame()
{
  game = GameLogic(4, 3, 2, 1);
  logerAcces.GetInstance().Log("New game!");
  ui->checkBox_1->setChecked(false);
  ui->checkBox_2->setChecked(false);
  ui->checkBox_3->setChecked(false);
  ui->checkBox_4->setChecked(false);
}

void MainWindow::Update(GameState state, QCheckBox* updatingCheckbox)
{
  //логирование
  if (state != GameState::Play)
  {
    if (state == GameState::Losing)
    {
      logerAcces.GetInstance().Log("Losing!");
    }
    else
    {
      logerAcces.GetInstance().Log("Win!");
    }
  }
  // обновление checkbox в случае угадывания
  if (state == GameState::Play || state == GameState::Win)
  {
    updatingCheckbox->setChecked(true);
  }
  else
  {
    ResetGame();
  }
}
