#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LogFile.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  LogFile::getLogFile().open(QIODevice::WriteOnly);
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  LogFile::getLogFile().close();
  delete ui;
}

void MainWindow::checkWin()
{
  if (ui->checkBox1->checkState() && ui->checkBox2->checkState() && ui->checkBox3->checkState() &&
      ui->checkBox4->checkState())
  {
    LogFile::getLogFile().write("User has won!\n");
  }
}

void MainWindow::resetGame()
{
  ui->checkBox1->setChecked(false);
  ui->checkBox2->setChecked(false);
  ui->checkBox3->setChecked(false);
  ui->checkBox4->setChecked(false);
  i = 0;
}

void MainWindow::on_pushButton1_clicked()
{
  LogFile::getLogFile().write("-First button has been pressed\n");
  if (code.at(i) == '1')
  {
    ui->checkBox1->setChecked(true);
    checkWin();
    i++;
  }
  else
    handleUserLost();
}

void MainWindow::on_pushButton2_clicked()
{
  LogFile::getLogFile().write("-Second button has been pressed\n");
  if (code.at(i) == '2')
  {
    ui->checkBox2->setChecked(true);
    checkWin();
    i++;
  }
  else
    handleUserLost();
}

void MainWindow::on_pushButton3_clicked()
{
  LogFile::getLogFile().write("-Third button has been pressed\n");
  if (code.at(i) == '3')
  {
    ui->checkBox3->setChecked(true);
    checkWin();
    i++;
  }
  else
    handleUserLost();
}

void MainWindow::on_pushButton4_clicked()
{
  LogFile::getLogFile().write("-Fourth button has been pressed\n");
  if (code.at(i) == '4')
  {
    ui->checkBox4->setChecked(true);
    checkWin();
    i++;
  }
  else
    handleUserLost();
}

void MainWindow::on_resetButton_clicked()
{
  LogFile::getLogFile().write("-Reset button has been pressed\n");
  resetGame();
}
