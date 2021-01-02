#ifndef WORKERS
#define WORKERS
#include <QThread>
#include <QtCore>
#include <QSqlDatabase>
#include <mainwindow.h>
class Worker:public QThread{
public:
    Worker(int _argc,char ** _argv,QSqlDatabase * _db){
        argc=_argc;
        argv=_argv;
        db = _db;
    }
    Worker(){}
    void run();
    void exit();
private:
    int argc;
    char** argv;
    QSqlDatabase * db;

};


#endif // WORKERS

