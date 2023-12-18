
// plotter.cpp
#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

Plotter::Plotter(QWidget *parent)
    : QWidget(parent)
{
}

void Plotter::setPlotData(const QVector<qint64> &data)
{
    plotData = data;
    update(); // Chama paintEvent para redesenhar com os novos dados.
}

void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255, 255, 100));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(2);

    // Preencha o widget com a cor especificada
    painter.fillRect(0, 0, width(), height(), brush);

    // Desenhe um retângulo com a cor da borda
    painter.setPen(pen);
    painter.drawRect(0, 0, width() - 1, height() - 1);

    pen.setColor(QColor(255, 180, 0));
    painter.setPen(pen);

    int dataSize = plotData.size();
    if (dataSize > 1) {
        for (int i = 1; i < dataSize; ++i) {
            // Desenhe uma linha entre pontos consecutivos
            int x1 = (i - 1) * width() / (dataSize - 1);
            int x2 = i * width() / (dataSize - 1);
            int y1 = height() - plotData[i - 1];
            int y2 = height() - plotData[i];
            painter.drawLine(x1, y1, x2, y2);
        }
    }
}
