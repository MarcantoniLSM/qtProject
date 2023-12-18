#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
public slots:
  void putData();
  void end();
  void startDataTransmission();
  void stopDataTransmission();
  void tcpConnect();
  void disconnectFromServer();
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QTimer *dataTimer;
};

#endif // MAINWINDOW_H
