#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include "Log.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

constexpr int MainWindow::sequece[];

inline bool MainWindow::check_win()
{
    return buttons_pressed_right == button_number;
}

void MainWindow::block_ui()
{
    ui->pushButton_01->setEnabled(false);
    ui->pushButton_02->setEnabled(false);
    ui->pushButton_03->setEnabled(false);
    ui->pushButton_04->setEnabled(false);
    ui->proccess_label->setText("Push reset button");
}

void MainWindow::reset_ui()
{
    Log::getInstance().log("reset button clicked");
    buttons_pressed_right = 0;

    ui->checkBox_01->setChecked(Qt::Unchecked);
    ui->checkBox_02->setChecked(Qt::Unchecked);
    ui->checkBox_03->setChecked(Qt::Unchecked);
    ui->checkBox_04->setChecked(Qt::Unchecked);

    ui->pushButton_01->setEnabled(true);
    ui->pushButton_02->setEnabled(true);
    ui->pushButton_03->setEnabled(true);
    ui->pushButton_04->setEnabled(true);

    ui->proccess_label->setText("Keep press buttons");
}


void MainWindow::proccess_button(QPushButton* button, QCheckBox* check)
{
    Log::getInstance().log("button" + button->text().toStdString() + "clicked");

    if(button->text().toStdString() == std::to_string(sequece[buttons_pressed_right]))
    {
        buttons_pressed_right++;
        check->setChecked(Qt::Checked);
        button->setEnabled(false);

        if(check_win())
        {
            Log::getInstance().log("win");
            block_ui();
        }
    }
    else
    {
        Log::getInstance().log("lose");
        block_ui();
    }

}


void MainWindow::on_pushButton_01_clicked()
{
    proccess_button(ui->pushButton_01, ui->checkBox_01);
}

void MainWindow::on_pushButton_02_clicked()
{
    proccess_button(ui->pushButton_02, ui->checkBox_02);
}

void MainWindow::on_pushButton_03_clicked()
{
    proccess_button(ui->pushButton_03, ui->checkBox_03);
}

void MainWindow::on_pushButton_04_clicked()
{
    proccess_button(ui->pushButton_04, ui->checkBox_04);
}

void MainWindow::on_reset_pushButton_clicked()
{
    reset_ui();
}
