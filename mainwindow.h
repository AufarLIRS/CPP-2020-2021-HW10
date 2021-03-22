#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logger.h"
#include <QPushButton>
#include <QCheckBox>
#include "game.h"

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
  void checkButton(int Id);
  void reset();

  void on_firstButton_clicked();
  void on_secondButton_clicked();
  void on_thirdButton_clicked();
  void on_fourthButton_clicked();
  void on_resetButton_clicked();

private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
