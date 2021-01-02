#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QTimer>
#include "workers.h"
namespace Ui {
class MainWindow;
}
class Worker;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int , char** ,QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow* getUi(){return ui;}
    void addToTable();
    void updateTable();
    void updateInformations();
    void SniffWorker();
    void StopSniffing();
    void resetTables();
    void showGif();


private:
    Ui::MainWindow *ui;
    int argc;
    char** argv;
    QSqlDatabase db;
    Worker  * sniffer;
    QTimer * timer;

};

#endif // MAINWINDOW_H
