
#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QVector>

class Plotter : public QWidget
{
    Q_OBJECT

public:
    Plotter(QWidget *parent = nullptr);
    void setPlotData(const QVector<qint64> &data);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<qint64> plotData;
};

#endif
