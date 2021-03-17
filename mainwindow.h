#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "log.h"
#include <QPushButton>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void on_button_1_clicked();
  void on_button_2_clicked();
  void on_button_3_clicked();
  void on_button_4_clicked();
  void on_resetButton_clicked();

private:
  Ui::MainWindow* ui;
  static constexpr int buttons_number_ = 4;
  static constexpr int sequence_[] = { 4, 1, 2, 3 };
  int buttons_pressed_right_ = 0;
  void reset_ui();
  void block_ui();
  inline bool check_win();
  void process_button(QPushButton*, QCheckBox*);
};
#endif  // MAINWINDOW_H
