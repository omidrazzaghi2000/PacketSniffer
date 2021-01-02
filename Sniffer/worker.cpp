#include "workers.h"
#include "PacketSniffer.h"
#include <iostream>
#include <QDebug>
void Worker::run(){
    qDebug() << "In the name of Allah \n Packet sniffing is starting ...\n";
    startSniffing(argc,argv,db);
}
void Worker::exit(){
    stopSniffing();
}
