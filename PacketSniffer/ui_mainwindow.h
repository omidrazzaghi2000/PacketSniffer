/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_to_csv;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Sniff;
    QPushButton *Stop;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *MainPage;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tcp_tab;
    QVBoxLayout *verticalLayout_5;
    QTableView *tableView;
    QWidget *udp_tab;
    QVBoxLayout *verticalLayout_6;
    QTableView *udp_tableView;
    QWidget *icmp_tab;
    QVBoxLayout *verticalLayout_7;
    QTableView *icmp_tableView;
    QWidget *details;
    QHBoxLayout *horizontalLayout_3;
    QTableView *IP_sender;
    QGridLayout *gridLayout_2;
    QLabel *Fragmented_lab;
    QLCDNumber *Avrg;
    QLCDNumber *Max;
    QLabel *Max_lab;
    QLabel *Avrg_lab;
    QLCDNumber *Frag;
    QLabel *Min_lab;
    QLCDNumber *Min;
    QWidget *LoadingPage;
    QLabel *loadig_sniff_gif;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(896, 567);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionSave_to_csv = new QAction(MainWindow);
        actionSave_to_csv->setObjectName(QStringLiteral("actionSave_to_csv"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Sniff = new QPushButton(centralWidget);
        Sniff->setObjectName(QStringLiteral("Sniff"));

        horizontalLayout_2->addWidget(Sniff);

        Stop = new QPushButton(centralWidget);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setEnabled(false);

        horizontalLayout_2->addWidget(Stop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        stackedWidget->setFrameShadow(QFrame::Raised);
        stackedWidget->setLineWidth(0);
        MainPage = new QWidget();
        MainPage->setObjectName(QStringLiteral("MainPage"));
        verticalLayout_4 = new QVBoxLayout(MainPage);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        tabWidget = new QTabWidget(MainPage);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setPointSize(12);
        tabWidget->setFont(font);
        tabWidget->setTabsClosable(false);
        tcp_tab = new QWidget();
        tcp_tab->setObjectName(QStringLiteral("tcp_tab"));
        tcp_tab->setEnabled(true);
        tcp_tab->setAcceptDrops(false);
        tcp_tab->setAutoFillBackground(false);
        verticalLayout_5 = new QVBoxLayout(tcp_tab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tableView = new QTableView(tcp_tab);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_5->addWidget(tableView);

        tabWidget->addTab(tcp_tab, QString());
        udp_tab = new QWidget();
        udp_tab->setObjectName(QStringLiteral("udp_tab"));
        verticalLayout_6 = new QVBoxLayout(udp_tab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        udp_tableView = new QTableView(udp_tab);
        udp_tableView->setObjectName(QStringLiteral("udp_tableView"));

        verticalLayout_6->addWidget(udp_tableView);

        tabWidget->addTab(udp_tab, QString());
        icmp_tab = new QWidget();
        icmp_tab->setObjectName(QStringLiteral("icmp_tab"));
        verticalLayout_7 = new QVBoxLayout(icmp_tab);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        icmp_tableView = new QTableView(icmp_tab);
        icmp_tableView->setObjectName(QStringLiteral("icmp_tableView"));

        verticalLayout_7->addWidget(icmp_tableView);

        tabWidget->addTab(icmp_tab, QString());
        details = new QWidget();
        details->setObjectName(QStringLiteral("details"));
        horizontalLayout_3 = new QHBoxLayout(details);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        IP_sender = new QTableView(details);
        IP_sender->setObjectName(QStringLiteral("IP_sender"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IP_sender->sizePolicy().hasHeightForWidth());
        IP_sender->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(IP_sender);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Fragmented_lab = new QLabel(details);
        Fragmented_lab->setObjectName(QStringLiteral("Fragmented_lab"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Fragmented_lab->sizePolicy().hasHeightForWidth());
        Fragmented_lab->setSizePolicy(sizePolicy1);
        Fragmented_lab->setFrameShape(QFrame::NoFrame);
        Fragmented_lab->setFrameShadow(QFrame::Plain);
        Fragmented_lab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(Fragmented_lab, 0, 0, 1, 1);

        Avrg = new QLCDNumber(details);
        Avrg->setObjectName(QStringLiteral("Avrg"));
        Avrg->setFrameShape(QFrame::NoFrame);
        Avrg->setLineWidth(2);
        Avrg->setMidLineWidth(0);
        Avrg->setSmallDecimalPoint(false);
        Avrg->setSegmentStyle(QLCDNumber::Flat);
        Avrg->setProperty("intValue", QVariant(0));

        gridLayout_2->addWidget(Avrg, 3, 1, 1, 1);

        Max = new QLCDNumber(details);
        Max->setObjectName(QStringLiteral("Max"));
        sizePolicy1.setHeightForWidth(Max->sizePolicy().hasHeightForWidth());
        Max->setSizePolicy(sizePolicy1);
        Max->setFrameShape(QFrame::NoFrame);
        Max->setLineWidth(2);
        Max->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(Max, 1, 1, 1, 1);

        Max_lab = new QLabel(details);
        Max_lab->setObjectName(QStringLiteral("Max_lab"));
        sizePolicy1.setHeightForWidth(Max_lab->sizePolicy().hasHeightForWidth());
        Max_lab->setSizePolicy(sizePolicy1);
        Max_lab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(Max_lab, 1, 0, 1, 1);

        Avrg_lab = new QLabel(details);
        Avrg_lab->setObjectName(QStringLiteral("Avrg_lab"));
        Avrg_lab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(Avrg_lab, 3, 0, 1, 1);

        Frag = new QLCDNumber(details);
        Frag->setObjectName(QStringLiteral("Frag"));
        sizePolicy1.setHeightForWidth(Frag->sizePolicy().hasHeightForWidth());
        Frag->setSizePolicy(sizePolicy1);
        Frag->setFrameShape(QFrame::NoFrame);
        Frag->setFrameShadow(QFrame::Raised);
        Frag->setLineWidth(2);
        Frag->setDigitCount(5);
        Frag->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(Frag, 0, 1, 1, 1);

        Min_lab = new QLabel(details);
        Min_lab->setObjectName(QStringLiteral("Min_lab"));
        sizePolicy1.setHeightForWidth(Min_lab->sizePolicy().hasHeightForWidth());
        Min_lab->setSizePolicy(sizePolicy1);
        Min_lab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(Min_lab, 2, 0, 1, 1);

        Min = new QLCDNumber(details);
        Min->setObjectName(QStringLiteral("Min"));
        sizePolicy1.setHeightForWidth(Min->sizePolicy().hasHeightForWidth());
        Min->setSizePolicy(sizePolicy1);
        Min->setFrameShape(QFrame::NoFrame);
        Min->setLineWidth(2);
        Min->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_2->addWidget(Min, 2, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        tabWidget->addTab(details, QString());

        verticalLayout->addWidget(tabWidget);


        verticalLayout_4->addLayout(verticalLayout);

        stackedWidget->addWidget(MainPage);
        LoadingPage = new QWidget();
        LoadingPage->setObjectName(QStringLiteral("LoadingPage"));
        loadig_sniff_gif = new QLabel(LoadingPage);
        loadig_sniff_gif->setObjectName(QStringLiteral("loadig_sniff_gif"));
        loadig_sniff_gif->setGeometry(QRect(160, 80, 511, 251));
        loadig_sniff_gif->setFrameShape(QFrame::NoFrame);
        loadig_sniff_gif->setFrameShadow(QFrame::Sunken);
        loadig_sniff_gif->setLineWidth(0);
        stackedWidget->addWidget(LoadingPage);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 896, 25));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSave_to_csv->setText(QApplication::translate("MainWindow", "save to csv ...", 0));
        Sniff->setText(QApplication::translate("MainWindow", "Sniff", 0));
        Stop->setText(QApplication::translate("MainWindow", "Stop", 0));
#ifndef QT_NO_TOOLTIP
        tcp_tab->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tcp_tab), QApplication::translate("MainWindow", "TCP", 0));
        tabWidget->setTabText(tabWidget->indexOf(udp_tab), QApplication::translate("MainWindow", "UDP", 0));
        tabWidget->setTabText(tabWidget->indexOf(icmp_tab), QApplication::translate("MainWindow", "ICMP", 0));
        Fragmented_lab->setText(QApplication::translate("MainWindow", "# Fragmented packets", 0));
        Max_lab->setText(QApplication::translate("MainWindow", "Maximum size of packets", 0));
        Avrg_lab->setText(QApplication::translate("MainWindow", "Average size of packets", 0));
        Min_lab->setText(QApplication::translate("MainWindow", "Minimum size of packets", 0));
        tabWidget->setTabText(tabWidget->indexOf(details), QApplication::translate("MainWindow", "Statistics", 0));
        loadig_sniff_gif->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
