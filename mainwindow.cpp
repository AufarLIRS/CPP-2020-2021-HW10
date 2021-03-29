#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "game.h"
#include "gameResult.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    Logger::init("file");
    ui->setupUi(this);
    ui->label->setText("Keep pressing buttons!");
}

constexpr int MainWindow::sequence_[];

MainWindow::~MainWindow()
{
    logger.flush();
    delete ui;
}

void MainWindow::reset_ui()
{
    logger.out("Reset button has clicked");
    button_pressed_right_ = 0;
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
    ui->checkBox_4->setCheckState(Qt::Unchecked);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->label->setText("Keep pressing buttons!");
}

void MainWindow::block_buttons()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->label->setText("Push Reset to start new Game");
}

inline bool MainWindow::check_win()
{
    return button_pressed_right_ == buttons_number_;
}
void MainWindow::process_button(QPushButton* button, QCheckBox* check)
{
    logger.out("Button " + button->text().toStdString() + " has clicked");
    if(button->text().toStdString() == std::to_string(sequence_[button_pressed_right_]))
    {
        button_pressed_right_++;
        check->setChecked(Qt::Checked);
        button->setEnabled(false);
             if (check_win())
             {
               logger.out("Win!");
               block_buttons();
             }
    } else
    {
         logger.out("Lose!");
         block_buttons();
    }
}

void MainWindow::on_pushButton_clicked()
{
    process_button(ui->pushButton, ui->checkBox);
}

void MainWindow::on_pushButton_2_clicked()
{
    process_button(ui->pushButton_2, ui->checkBox_2);
}

void MainWindow::on_pushButton_3_clicked()
{
    process_button(ui->pushButton_3, ui->checkBox_3);
}

void MainWindow::on_pushButton_4_clicked()
{
    process_button(ui->pushButton_4, ui->checkBox_4);
}

void MainWindow::on_pushButton_5_clicked()
{
    reset_ui();
}
