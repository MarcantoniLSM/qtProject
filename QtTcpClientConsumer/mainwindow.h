#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QListWidgetItem>
#include <QDebug>
#include <QTimer>
#include "plotter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void tcpConnect();
public slots:
  void getData();
  void onListItemClicked(QListWidgetItem *item);
  void onStartButtonClicked();
  void startDataReception(QString selectedMachine,int captureInterval);
  void onTimeout();
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QString selectedMachine;
  int captureInterval;
  QListWidgetItem *selectedItem;
  Plotter *plotter;
};

#endif // MAINWINDOW_H
