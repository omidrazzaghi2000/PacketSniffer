#include "mainwindow.h"
#include <QApplication>
#include <stdlib.h>
#include <QStyle>

int main(int argc, char *argv[])
{
    //Capture Packets
        system("clear");
        QApplication app(argc,argv);
        MainWindow * m = new MainWindow (argc,argv);
        m->show();


        return app.exec();

}
