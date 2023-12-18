#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  socket = new QTcpSocket(this);

  dataTimer = new QTimer(this);
  connect(dataTimer, &QTimer::timeout, this, &MainWindow::putData);

  connect(ui->pushButtonStart,
          SIGNAL(clicked(bool)),
          this,
          SLOT(startDataTransmission));

  connect(ui->pushButtonStop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(stopDataTransmission));

  connect(ui->pushButtonEnd,
          SIGNAL(clicked(bool)),
          this,
          SLOT(end()));

  connect(ui->pushButtonDisconnect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(disconnectFromServer()));
}

void MainWindow::tcpConnect(){
  socket->connectToHost("127.0.0.1",1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;

  int minValue = ui->horizontalSliderMin->value();
  int maxValue = ui->horizontalSliderMax->value();

  if(socket->state()== QAbstractSocket::ConnectedState){

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+ QString::number(msecdate) + " " +
        QString::number(rand()%((maxValue + 1) - minValue) + minValue)+"\r\n";

    ui->textBrowser->append(str);

      qDebug() << str;
      qDebug() << socket->write(str.toStdString().c_str())
               << " bytes written";
      if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
      }
  }
}

void MainWindow::end()
{
    exit(0);
}

void MainWindow::startDataTransmission()
{
    int interval = 1000*(ui->horizontalSliderTime->value());
    dataTimer->start(interval);
}

void MainWindow::stopDataTransmission()
{
    dataTimer->stop();
}

void MainWindow::disconnectFromServer()
{
    if (socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->disconnectFromHost();
        socket->waitForDisconnected(3000);
        qDebug() << "Disconnected from the server.";
    }
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}
