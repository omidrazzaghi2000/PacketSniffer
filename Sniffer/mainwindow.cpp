#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include <PacketSniffer.h>
#include <QTimer>
#include <QMovie>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

MainWindow::MainWindow(int _argc,char**_argv,QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    argc = _argc;
    argv = _argv;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/omidrazzaghi/Sniffer/packets.db");
    sniffer = new Worker(argc,argv,&db);
    connect(ui->Sniff, &QPushButton::released, this, &MainWindow::SniffWorker);
    connect(ui->Stop,&QPushButton::released,this,&MainWindow::StopSniffing);
    updateTable();
    timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::updateTable);
    ui->stackedWidget->setCurrentIndex(1);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateTable(){





    if (db.open())
       {

        QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("select\n"
                            "ethernet_packets.packet_number,ethernet_packets.source_mac_addr,ethernet_packets.dest_mac_address\n"
                            ",ipv4.src_ip,ipv4.des_ip,ipv4.length,ipv4.ttl,ipv4.fragment,tcp_segment.src_port,tcp_segment.dest_port,tcp_segment.sequence,\n"
                            "tcp_segment.ack,tcp_segment.data_offset\n"
                            "from ethernet_packets\n"
                            "Inner JOIN tcp_segment on tcp_segment.packet_number = ethernet_packets.packet_number\n"
                            "Inner Join ipv4 on ipv4.packet_number = ethernet_packets.packet_number");


          ui->tableView->setModel(model);
          ui->tableView->scrollToBottom();
          ui->tableView->show();

          QSqlQueryModel *model_udp = new QSqlQueryModel;
          model_udp->setQuery("select\n"
                          "ethernet_packets.packet_number,ethernet_packets.source_mac_addr,ethernet_packets.dest_mac_address,\n"
                          "ethernet_packets.protocol,ipv4.protocol,ipv4.version,ipv4.length,ipv4.ttl,ipv4.fragment,ipv4.src_ip,ipv4.des_ip,ipv4.protocol,udp_segment.src_port,udp_segment.dest_port,udp_segment.length\n"
                          "from\n"
                          "ethernet_packets\n"
                          "Inner join ipv4 on ipv4.packet_number = ethernet_packets.packet_number\n"
                          "    Inner JOIN udp_segment on udp_segment.packet_number = ethernet_packets.packet_number\n"
                          );
          ui->udp_tableView->setModel(model_udp);
          ui->udp_tableView->scrollToBottom();
          ui->udp_tableView->show();

          QSqlQueryModel *model_icmp = new QSqlQueryModel;
          model_icmp->setQuery("select\n"
                          "  ethernet_packets.packet_number,ethernet_packets.source_mac_addr,ethernet_packets.dest_mac_address,\n"
                          "  ethernet_packets.protocol,icmp_packet.type,icmp_packet.code\n"
                          "  ipv4.protocol,ipv4.length,ipv4.ttl,ipv4.fragment,ipv4.src_ip,ipv4.des_ip,\n"
                          "from\n"
                          "  ethernet_packets Inner JOIN \n"
                          "  icmp_packet on icmp_packet.packet_number = ethernet_packets.packet_number\n"
                          "  Inner JOIN udp_segment on udp_segment.packet_number = ethernet_packets.packet_number\n"
                          );
          ui->icmp_tableView->setModel(model_icmp);
          ui->icmp_tableView->show();
          ui->icmp_tableView->scrollToBottom();

       }else{
        qDebug() << "[Database] Error connecting to database.";
    }
        QSqlQueryModel * model_ip = new QSqlQueryModel;
        model_ip->setQuery("select ipv4.src_ip,count(*) from ipv4 group by ipv4.src_ip order by count(*) desc");
        ui->IP_sender->setModel(model_ip);
        ui->IP_sender->show();
        ui->IP_sender->scrollToTop();

}

void MainWindow::updateInformations(){
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery("select count(ipv4.fragment) from ipv4 where ipv4.fragment");
    int a = model->data(model->index(0, 0)).toInt();
    ui->Frag->display(a);

    QSqlQueryModel * model_max = new QSqlQueryModel;
    model_max->setQuery("select max(length) from ipv4");
    a = model_max->data(model_max->index(0, 0)).toInt();
    ui->Max->display(a);

    QSqlQueryModel * model_min = new QSqlQueryModel;
    model_min->setQuery("select min(length) from ipv4");
    a = model_min->data(model_min->index(0, 0)).toInt();
    ui->Min->display(a);

    QSqlQueryModel * model_avrg = new QSqlQueryModel;
    model_avrg->setQuery("select avg(length) from ipv4");
    a = model_avrg->data(model_avrg->index(0, 0)).toInt();
    ui->Avrg->display(a);



}

void MainWindow::showGif(){

    QMovie *movie = new QMovie("../Sniffer/giphy.gif");

    ui->loadig_sniff_gif->show();
    ui->loadig_sniff_gif->setMovie(movie);
    movie->start();
}

void MainWindow::SniffWorker(){
    sniffer->start();
    resetTables();
    ui->stackedWidget->setCurrentIndex(1);
    showGif();
    ui->Stop->setEnabled(true);
    ui->Sniff->setDisabled(true);



}

void MainWindow::StopSniffing(){
    sniffer->exit();
    ui->Stop->setEnabled(false);
    ui->Sniff->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(0);
    updateTable();
    updateInformations();


}

void MainWindow::resetTables(){
    QSqlQuery query;
    query.prepare("DELETE FROM ethernet_packets");
    query.exec();

    query.prepare("DELETE FROM ipv4");
    query.exec();

    query.prepare("DELETE FROM icmp_packet");
    query.exec();

    query.prepare("DELETE FROM udp_segment");
    query.exec();

    query.prepare("DELETE FROM tcp_segment");
    query.exec();


}
