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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "plotter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QTextBrowser *textBrowser;
    QPushButton *pushButtonGet;
    QPushButton *pushButtonDisconnect;
    QPushButton *pushButtonUpdate;
    QSlider *horizontalSlider;
    QLCDNumber *lcdNumber;
    Plotter *widget;
    QPushButton *pushButtonStart;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(463, 421);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 80, 161, 141));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 10, 131, 31));
        pushButtonGet = new QPushButton(centralWidget);
        pushButtonGet->setObjectName("pushButtonGet");
        pushButtonGet->setGeometry(QRect(10, 50, 80, 24));
        pushButtonDisconnect = new QPushButton(centralWidget);
        pushButtonDisconnect->setObjectName("pushButtonDisconnect");
        pushButtonDisconnect->setGeometry(QRect(110, 50, 80, 24));
        pushButtonUpdate = new QPushButton(centralWidget);
        pushButtonUpdate->setObjectName("pushButtonUpdate");
        pushButtonUpdate->setGeometry(QRect(90, 230, 80, 24));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(10, 270, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(170, 260, 64, 23));
        widget = new Plotter(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(239, 9, 211, 301));
        pushButtonStart = new QPushButton(centralWidget);
        pushButtonStart->setObjectName("pushButtonStart");
        pushButtonStart->setGeometry(QRect(10, 310, 80, 24));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 463, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\"> 127.0.0.1</span></p></body></html>", nullptr));
        pushButtonGet->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
