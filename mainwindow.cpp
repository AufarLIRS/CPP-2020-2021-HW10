#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "number_guessing.h"
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
  if (Number_Guessing::IsRightNumber('1'))
  {
    ui->checkBox->setChecked(true);
  }
}

void MainWindow::on_pushButton_2_clicked()
{
  if (Number_Guessing::IsRightNumber('2'))
  {
    ui->checkBox->setChecked(true);
  }
}

void MainWindow::on_pushButton_3_clicked()
{
  if (Number_Guessing::IsRightNumber('3'))
  {
    ui->checkBox->setChecked(true);
  }
}

void MainWindow::on_pushButton_4_clicked()
{
  if (Number_Guessing::IsRightNumber('4'))
  {
    ui->checkBox->setChecked(true);
  }
}

void MainWindow::on_pushButton_5_clicked()
{
  ui->checkBox->setChecked(false);
  ui->checkBox_2->setChecked(false);
  ui->checkBox_3->setChecked(false);
  ui->checkBox_4->setChecked(false);
  Number_Guessing::Reset();
}
