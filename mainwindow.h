#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <LogFile.h>

// Secret quest's code; code's length must be equal 4 symbols
const std::string code = "3142";

static int i = 0;

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
  // Handle User's defeat
  void handleUserLost()
  {
    MainWindow::resetGame();
    LogFile::getLogFile().write("User has lost...\n");
  };

private slots:
  void on_pushButton1_clicked();

  void on_pushButton2_clicked();

  void on_pushButton3_clicked();

  void on_pushButton4_clicked();

  void on_resetButton_clicked();

  void resetGame();

  void checkWin();

private:
  Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
