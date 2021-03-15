#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "quessthenumber.h"
#include <QDebug>
#include "logfile.h"
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}
void MainWindow::on_pushButton_clicked()
{
  if (QuessTheNumber::Quess('1'))
  {
    ui->checkBox->setChecked(true);
    // LogFile::getInstance()->log("кнопка 1");
  }
}

void MainWindow::on_pushButton_2_clicked()
{
  if (QuessTheNumber::Quess('2'))
  {
    ui->checkBox_2->setChecked(true);
    //    LogFile::getInstance()->log("кнопка 2");
  }
}

void MainWindow::on_pushButton_3_clicked()
{
  if (QuessTheNumber::Quess('3'))
  {
    ui->checkBox_3->setChecked(true);
    //  LogFile::getInstance()->log("кнопка 3");
  }
}

void MainWindow::on_pushButton_4_clicked()
{
  if (QuessTheNumber::Quess('4'))
  {
    // LogFile::getInstance()->log("кнопка 4");
    ui->checkBox_4->setChecked(true);
  }
}

void MainWindow::on_ResetButton_clicked()
{
  ui->checkBox->setChecked(false);
  ui->checkBox_2->setChecked(false);
  ui->checkBox_3->setChecked(false);
  ui->checkBox_4->setChecked(false);
  // LogFile::getInstance()->log("Рестарт");
  QuessTheNumber::Reset();
}
