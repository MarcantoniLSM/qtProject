#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  tcpConnect();

  connect(ui->pushButtonGet,
          SIGNAL(clicked(bool)),
          this,
          SLOT(getData()));

  connect(ui->listWidget,
          SIGNAL(itemClicked(QListWidgetItem*)),
          this,
          SLOT(onListItemClicked(QListWidgetItem*)));

  connect(ui->pushButtonStart,
          SIGNAL(clicked()),
          this,
          SLOT(onStartButtonClicked()));
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

void MainWindow::getData(){
    QString str;
    QByteArray array;
    QStringList list;
    qint64 thetime;
    QVector<qint64> plotData; // Nova instância para armazenar os valores oscilatórios

    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";
            socket->write("list\r\n");
            socket->write("get 127.0.0.1 5\r\n");
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");
                if(list.size() == 1){
                    ui->listWidget->addItem(list.at(0));
                }
            }
        }
    }

    // Agora, chame setPlotData no Plotter para atualizar com os novos dados
    ui->widget->setPlotData(plotData);
}

void MainWindow::onListItemClicked(QListWidgetItem *item) {
    selectedItem = item;
    selectedMachine = item->text();
}

void MainWindow::onTimeout()
{
    QString str;
    QByteArray array;
    QStringList list;
    qint64 thetime;

    // Certifique-se de ajustar o comando para obter dados do servidor usando o IP e máquina corretos
    QString command = QString("get %1 %2\r\n").arg("127.0.0.1").arg(selectedMachine);
    socket->write(command.toUtf8());
    socket->waitForBytesWritten();
    socket->waitForReadyRead();

    qDebug() << socket->bytesAvailable();
    QVector<qint64> plotData; // Nova instância para armazenar os valores oscilatórios

    while (socket->bytesAvailable()) {
        str = socket->readLine().replace("\n", "").replace("\r", "");
        list = str.split(" ");
        if (list.size() == 2) {
            bool ok;
            str = list.at(1);
            qint64 oscillationValue = str.toLongLong(&ok);
            plotData.append(oscillationValue); // Adiciona o valor oscilatório ao vetor
            thetime = list.at(0).toLongLong(&ok);
            qDebug() << thetime << ": " << oscillationValue;
        }
    }

    // Agora, chame setPlotData no Plotter para atualizar com os novos dados
    plotter->setPlotData(plotData);
}

void MainWindow::startDataReception(QString selectedMachine,int captureInterval){
    // Criar um QTimer para leitura periódica dos dados
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start(captureInterval);  // Inicia o QTimer com o novo intervalo

    // Conectar o sinal de timeout do QTimer à função de leitura dos dados
    connect(timer, SIGNAL(timeout()), this, SLOT(getData()));

    // Adicionar lógica para conectar ao servidor e receber dados aqui
    // Certifique-se de ajustar o código para enviar o comando correto ao servidor

    // Exemplo (ajuste conforme necessário):
    // socket->write(QString("get %1\r\n").arg(selectedMachine).toUtf8());
    // socket->waitForBytesWritten();
}

void MainWindow::onStartButtonClicked() {
    // Verifique se uma máquina foi selecionada
    if (selectedMachine.isEmpty()) {
        qDebug() << "Selecione uma máquina antes de iniciar a recepção de dados.";
        return;
    }

    // Obtém o intervalo de tempo do slider
    captureInterval = ui->horizontalSlider->value();

    // Inicia a recepção de dados (você precisa implementar essa parte)
    startDataReception(selectedMachine, captureInterval);
}

MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
