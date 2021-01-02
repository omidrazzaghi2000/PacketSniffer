#-------------------------------------------------
#
# Project created by QtCreator 2020-12-29T20:16:58
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



TARGET = Sniffer
TEMPLATE = app

LIBS += -l pcap
SOURCES += main.cpp\
        mainwindow.cpp \
    PacketSniffer.cpp \
    worker.cpp

HEADERS  += mainwindow.h \
    PacketSniffer.h \
    workers.h

FORMS    += mainwindow.ui
