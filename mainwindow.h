#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QCheckBox>
#include "logger.h"

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

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    int button_pressed_right_ = 0;
    static constexpr int buttons_number_ = 4;
    static constexpr int sequence_[] = {4, 3, 2, 1};
    void process_button(QPushButton*, QCheckBox*);
    void reset_ui();
    inline bool check_win();
    void block_buttons();
    Logger &logger = Logger::instance();
};
#endif // MAINWINDOW_H
