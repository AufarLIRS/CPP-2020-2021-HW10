#ifndef SINGLETON_H
#define SINGLETON_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QtCore/QCoreApplication>



class Singleton
{
  private:
    static Singleton * p_instance;
    int counter = 0;

    // Конструкторы и оператор присваивания недоступны клиентам
    Singleton() {
    }
    Singleton( const Singleton& );
    Singleton& operator=( Singleton& );
  public:
    static Singleton * getInstance();
    int getCounter() {
        return counter;
    }


    bool start(QString str) {
        QFile fileOut("fileout.txt");
        if (fileOut.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream writeStream(&fileOut);
            writeStream << counter++ << " :" << str;
            if(counter == 4){
                 writeStream << "You Won!!\n";
                 counter = 0;
                 fileOut.close();
                 return true;
            }
            fileOut.close();
        }

        return false;
    }
    bool gameOver(QString str){
        QFile fileOut("fileout.txt");
        if (fileOut.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream writeStream(&fileOut);
            writeStream << counter << " :" << str;
            writeStream << "Game Over!\n";
            counter = 0;
            fileOut.close();
        }
        else
            return false;
        return true;
    }


};

#endif // SINGLETON_H
