/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonEnd;
    QSlider *horizontalSliderMin;
    QSlider *horizontalSliderMax;
    QLCDNumber *lcdNumberMin;
    QLCDNumber *lcdNumberMax;
    QTextBrowser *textBrowser;
    QSlider *horizontalSliderTime;
    QLCDNumber *lcdNumberTime;
    QLabel *labelMin;
    QLabel *labelMax;
    QLabel *labelTime;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(555, 454);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        pushButtonEnd = new QPushButton(centralWidget);
        pushButtonEnd->setObjectName("pushButtonEnd");
        pushButtonEnd->setGeometry(QRect(150, 350, 80, 24));
        horizontalSliderMin = new QSlider(centralWidget);
        horizontalSliderMin->setObjectName("horizontalSliderMin");
        horizontalSliderMin->setGeometry(QRect(10, 120, 160, 16));
        horizontalSliderMin->setOrientation(Qt::Horizontal);
        horizontalSliderMax = new QSlider(centralWidget);
        horizontalSliderMax->setObjectName("horizontalSliderMax");
        horizontalSliderMax->setGeometry(QRect(10, 160, 160, 16));
        horizontalSliderMax->setOrientation(Qt::Horizontal);
        lcdNumberMin = new QLCDNumber(centralWidget);
        lcdNumberMin->setObjectName("lcdNumberMin");
        lcdNumberMin->setGeometry(QRect(180, 110, 64, 23));
        lcdNumberMax = new QLCDNumber(centralWidget);
        lcdNumberMax->setObjectName("lcdNumberMax");
        lcdNumberMax->setGeometry(QRect(190, 150, 64, 23));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(270, 10, 256, 361));
        horizontalSliderTime = new QSlider(centralWidget);
        horizontalSliderTime->setObjectName("horizontalSliderTime");
        horizontalSliderTime->setGeometry(QRect(10, 220, 160, 16));
        horizontalSliderTime->setOrientation(Qt::Horizontal);
        lcdNumberTime = new QLCDNumber(centralWidget);
        lcdNumberTime->setObjectName("lcdNumberTime");
        lcdNumberTime->setGeometry(QRect(180, 220, 64, 23));
        labelMin = new QLabel(centralWidget);
        labelMin->setObjectName("labelMin");
        labelMin->setGeometry(QRect(30, 100, 49, 16));
        labelMax = new QLabel(centralWidget);
        labelMax->setObjectName("labelMax");
        labelMax->setGeometry(QRect(30, 140, 49, 16));
        labelTime = new QLabel(centralWidget);
        labelTime->setObjectName("labelTime");
        labelTime->setGeometry(QRect(30, 200, 49, 16));
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(20, 20, 181, 31));
        pushButtonStart = new QPushButton(centralWidget);
        pushButtonStart->setObjectName("pushButtonStart");
        pushButtonStart->setGeometry(QRect(10, 260, 80, 24));
        pushButtonStop = new QPushButton(centralWidget);
        pushButtonStop->setObjectName("pushButtonStop");
        pushButtonStop->setGeometry(QRect(130, 260, 80, 24));
        pushButtonConnect = new QPushButton(centralWidget);
        pushButtonConnect->setObjectName("pushButtonConnect");
        pushButtonConnect->setGeometry(QRect(20, 60, 80, 24));
        pushButtonDisconnect = new QPushButton(centralWidget);
        pushButtonDisconnect->setObjectName("pushButtonDisconnect");
        pushButtonDisconnect->setGeometry(QRect(130, 60, 80, 24));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 555, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSliderMin, SIGNAL(valueChanged(int)), lcdNumberMin, SLOT(display(int)));
        QObject::connect(horizontalSliderMax, SIGNAL(valueChanged(int)), lcdNumberMax, SLOT(display(int)));
        QObject::connect(horizontalSliderTime, SIGNAL(valueChanged(int)), lcdNumberTime, SLOT(display(int)));
        QObject::connect(pushButtonStart, SIGNAL(clicked()), MainWindow, SLOT(startDataTransmission()));
        QObject::connect(pushButtonStop, SIGNAL(clicked()), MainWindow, SLOT(stopDataTransmission()));
        QObject::connect(pushButtonConnect, SIGNAL(clicked()), MainWindow, SLOT(tcpConnect()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonEnd->setText(QCoreApplication::translate("MainWindow", "Encerrar", nullptr));
        labelMin->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        labelMax->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        labelTime->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">127.0.0.1</span></p></body></html>", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
