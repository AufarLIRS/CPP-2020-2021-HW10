#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamestate.h"
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
  void Update(GameState state, QCheckBox* updatingCheckbox);
  void ResetGame();
  ~MainWindow();

private slots:
  void on_pushButton_1_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_resetButton_clicked();

private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
