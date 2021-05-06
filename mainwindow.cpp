#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singleton.h"
#include <QDebug>
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}
void MainWindow::stopGame(){
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
    ui->checkBox_4->setCheckState(Qt::Unchecked);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    auto game = Singleton::getInstance();
    bool res = false;
    QMessageBox msgBox;
    if (game->getCounter() == 0) {
       res = game->start("Buttom 1\n");
       ui->checkBox->setCheckState(Qt::Checked);
       if(res){
           msgBox.setInformativeText("You won!!");
           int ret = msgBox.exec();
           MainWindow::stopGame();
       }
    }
    else {
        res = game->gameOver("Buttom 1\n");
         msgBox.setInformativeText("Game over!");
         int ret = msgBox.exec();
         MainWindow::stopGame();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    Singleton * game = Singleton::getInstance();
    bool res = false;
    QMessageBox msgBox;
    if (game->getCounter() == 1) {
       res = game->start("Buttom 2\n");
       ui->checkBox_2->setCheckState(Qt::Checked);
       if(res){
           msgBox.setInformativeText("You won!!");
           int ret = msgBox.exec();
           MainWindow::stopGame();
       }
    }
    else {
        res = game->gameOver("Buttom 2\n");
        msgBox.setInformativeText("Game over!");
        int ret = msgBox.exec();
        MainWindow::stopGame();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    auto game = Singleton::getInstance();
    bool res = false;
    QMessageBox msgBox;
    if (game->getCounter() == 2) {
       res = game->start("Buttom 3\n");
       ui->checkBox_3->setCheckState(Qt::Checked);
       if(res){
           msgBox.setInformativeText("You won!!");
           int ret = msgBox.exec();
           MainWindow::stopGame();
       }
    }
    else {
        res = game->gameOver("Buttom 3\n");
        msgBox.setInformativeText("Game over!");
        int ret = msgBox.exec();
        MainWindow::stopGame();

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    auto game = Singleton::getInstance();
    bool res = false;
    QMessageBox msgBox;
    if (game->getCounter() == 3) {
       res = game->start("Buttom 4\n");
       ui->checkBox_4->setCheckState(Qt::Checked);
       if(res){
           msgBox.setInformativeText("You won!!");
           int ret = msgBox.exec();
           MainWindow::stopGame();
       }
    }
    else {
        res = game->gameOver("Buttom 4\n");
        msgBox.setInformativeText("Game over!");
        int ret = msgBox.exec();
        MainWindow::stopGame();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    auto game = Singleton::getInstance();
    bool res = false;
    res = game->gameOver("Reset game\n");
    MainWindow::stopGame();
}
