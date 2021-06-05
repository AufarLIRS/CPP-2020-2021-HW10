#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_01_clicked();

    void on_pushButton_02_clicked();

    void on_pushButton_03_clicked();

    void on_pushButton_04_clicked();

    void on_reset_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    static constexpr int button_number = 4;
    static constexpr int sequece[] = {3, 4, 1, 2};

    int buttons_pressed_right = 0;
    void reset_ui();
    void block_ui();
    inline bool check_win();
    void proccess_button(QPushButton*, QCheckBox*);
};
#endif // MAINWINDOW_H
