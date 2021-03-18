#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LogFile.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::checkWin()
{
  if (ui->checkBox1->checkState() && ui->checkBox2->checkState() && ui->checkBox3->checkState() &&
      ui->checkBox4->checkState())
  {
    LogFile::getInstance().write("User has won!\n");
  }
}

void MainWindow::resetGame()
{
  ui->checkBox1->setChecked(false);
  ui->checkBox2->setChecked(false);
  ui->checkBox3->setChecked(false);
  ui->checkBox4->setChecked(false);
  correctPushes = 0;
}

void MainWindow::on_pushButton1_clicked()
{
  LogFile::getInstance().write("-First button has been pressed\n");
  if (code.at(correctPushes) == '1')
  {
    ui->checkBox1->setChecked(true);
    checkWin();
    correctPushes++;
  }
  else
    handleUserLost();
}

void MainWindow::on_pushButton2_clicked()
{
  LogFile::getInstance().write("-Second button has been pressed\n");
  if (code.at(correctPushes) == '2')
  {
    ui->checkBox2->setChecked(true);
    checkWin();
    correctPushes++;
  }
  else
    handleUserLost();
}

void MainWindow::on_pushButton3_clicked()
{
  LogFile::getInstance().write("-Third button has been pressed\n");
  if (code.at(correctPushes) == '3')
  {
    ui->checkBox3->setChecked(true);
    checkWin();
    correctPushes++;
  }
  else
    handleUserLost();
}

void MainWindow::on_pushButton4_clicked()
{
  LogFile::getInstance().write("-Fourth button has been pressed\n");
  if (code.at(correctPushes) == '4')
  {
    ui->checkBox4->setChecked(true);
    checkWin();
    correctPushes++;
  }
  else
    handleUserLost();
}

void MainWindow::on_resetButton_clicked()
{
  LogFile::getInstance().write("-Reset button has been pressed\n");
  resetGame();
}
