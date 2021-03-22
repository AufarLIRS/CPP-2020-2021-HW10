#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

void MainWindow::reset()
{
  Game::Reset();

  ui->Button_1->setEnabled(true);
  ui->Button_2->setEnabled(true);
  ui->Button_3->setEnabled(true);
  ui->Button_4->setEnabled(true);
  ui->ResetButton->setEnabled(false);

  ui->checkBox_1->setChecked(false);
  ui->checkBox_2->setChecked(false);
  ui->checkBox_3->setChecked(false);
  ui->checkBox_4->setChecked(false);

  ui->label->setText("Resetting game");
  Log::GetInstance().Append("Resetting game");
}

void MainWindow::checkButton(int Id)
{
  int button;

  switch (Id)
  {
    case -3:
      button = 1;
      break;
    case -4:
      button = 2;
      break;
    case -5:
      button = 3;
      break;
    case -6:
      button = 4;
      break;
  }

  if (Game::CheckNumbers(button))
  {
    switch (button)
    {
      case 1:
        ui->label->setText("Clicked the first button");
        Log::GetInstance().Append("Clicked the first button");
        break;

      case 2:
        ui->label->setText("Clicked the second button");
        Log::GetInstance().Append("Clicked the second button");
        break;

      case 3:
        ui->label->setText("Clicked the third button");
        Log::GetInstance().Append("Clicked the third button");
        break;

      case 4:
        ui->label->setText("Clicked the fourth button");
        Log::GetInstance().Append("Clicked the fourth button");
        break;
    }

    if (Game::CheckResult())
    {
      ui->label->setText("Win!");
      Log::GetInstance().Append("Player win the game");
      reset();
    }
  }
  else
  {
    ui->label->setText("Lose");
    Log::GetInstance().Append("Player lose the game");
    reset();
  }
}

void MainWindow::on_firstButton_clicked()
{
  ui->checkBox_1->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_secondButton_clicked()
{
  ui->checkBox_2->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_thirdButton_clicked()
{
  ui->checkBox_3->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_fourthButton_clicked()
{
  ui->checkBox_4->setChecked(true);
  checkButton(ui->buttonGroup->checkedId());
}

void MainWindow::on_resetButton_clicked()
{
  reset();
}

MainWindow::~MainWindow()
{
  delete ui;
}
