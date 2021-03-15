#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

Logger log_;

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

  try
  {
    log_ << "Resetting game";
    throw std::runtime_error("error");
  }
  catch (...)
  {
//    log_.persist(R"(lastlog.txt)");
  }
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
        try
        {
          log_ << "Clicked the first button";
          throw std::runtime_error("error");
        }
        catch (...)
        {
//          log_.persist(R"(lastlog.txt)");
        }
        break;

      case 2:
        ui->label->setText("Clicked the second button");
        try
        {
          log_ << "Clicked the second button";
          throw std::runtime_error("error");
        }
        catch (...)
        {
//          log_.persist(R"(lastlog.txt)");
        }
        break;

      case 3:
        ui->label->setText("Clicked the third button");
        try
        {
          log_ << "Clicked the third button";
          throw std::runtime_error("error");
        }
        catch (...)
        {
//          log_.persist(R"(lastlog.txt)");
        }
        break;

      case 4:
        ui->label->setText("Clicked the fourth button");
        try
        {
          log_ << "Clicked the fourth button";
          throw std::runtime_error("error");
        }
        catch (...)
        {
//          log_.persist(R"(lastlog.txt)");
        }
        break;
    }

    if (Game::CheckResult())
    {
      ui->label->setText("Win!");
      try
      {
        log_ << "Win";
        throw std::runtime_error("error");
      }
      catch (...)
      {
//        log_.persist(R"(lastlog.txt)");
      }
      reset();
    }
  }
  else
  {
    ui->label->setText("Lose");
    try
    {
      log_ << "Lose";
      throw std::runtime_error("error");
    }
    catch (...)
    {
//      log_.persist(R"(lastlog.txt)");
    }
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
