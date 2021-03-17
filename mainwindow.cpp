#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

constexpr int MainWindow::sequence_[];

void MainWindow::reset_ui()
{
  Log::getInstance().log("clicked reset button");
  buttons_pressed_right_ = 0;
  ui->checkBox_1->setChecked(Qt::Unchecked);
  ui->checkBox_2->setChecked(Qt::Unchecked);
  ui->checkBox_3->setChecked(Qt::Unchecked);
  ui->checkBox_4->setChecked(Qt::Unchecked);
  ui->button_1->setEnabled(true);
  ui->button_2->setEnabled(true);
  ui->button_3->setEnabled(true);
  ui->button_4->setEnabled(true);
  ui->label->setText("Keep pressing buttons!");
}

void MainWindow::block_ui()
{
  ui->button_1->setEnabled(false);
  ui->button_2->setEnabled(false);
  ui->button_3->setEnabled(false);
  ui->button_4->setEnabled(false);
  ui->label->setText("Push RESET button!");
}

inline bool MainWindow::check_win()
{
  return buttons_pressed_right_ == buttons_number_;
}

void MainWindow::process_button(QPushButton* button, QCheckBox* check)
{
  Log::getInstance().log("button " + button->text().toStdString() + " clicked");
  if (button->text().toStdString() == std::to_string(sequence_[buttons_pressed_right_]))
  {
    buttons_pressed_right_++;
    check->setChecked(Qt::Checked);
    button->setEnabled(false);
    if (check_win())
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

void MainWindow::on_button_1_clicked()
{
  process_button(ui->button_1, ui->checkBox_1);
}

void MainWindow::on_button_2_clicked()
{
  process_button(ui->button_2, ui->checkBox_2);
}

void MainWindow::on_button_3_clicked()
{
  process_button(ui->button_3, ui->checkBox_3);
}

void MainWindow::on_button_4_clicked()
{
  process_button(ui->button_4, ui->checkBox_4);
}

void MainWindow::on_resetButton_clicked()
{
  reset_ui();
}
